/*
 * lcd_i2cmaster.c
 *
 * Created: 03/06/2014 11:08:07
 *  Author: David Prentice
 */
#define PCF8574A            0x27           // for your solder blobs.

#include <util/delay.h>
#include "i2cmaster.h"      //Fleury I2C
#include "lcd.h"            //Fleury LCD
#define I2C_INIT()          i2c_init()

uint8_t I2C_WRITESEQ(uint8_t slave, uint8_t *seq, uint8_t n)
{
    uint8_t ret = 1;
    if (i2c_start(slave << 1) == 0) {
        uint8_t i;
        for (i = 0; i < n; i++) {
            i2c_write(seq[i]);
        }
        ret = 0;
    }
    i2c_stop();
    return ret;
}


#include <util/delay.h>
#include <stdint.h>

static unsigned char _base_y[4]={0x80,0xc0};
unsigned char _lcd_x,_lcd_y,_lcd_maxx;

static char wr_lcd_mode(unsigned char c, unsigned char mode)
{
    char ret = 1;
    unsigned char seq[5];
    static unsigned char backlight = 8;
    if (mode == 8) {
        backlight = (c != 0) ? 8 : 0;
        return I2C_WRITESEQ(PCF8574A, &backlight, 1);
    }
    mode |= backlight;
    seq[0] = mode;                      // EN=0, RW=0, RS=mode
    seq[1] = (c & 0xF0) | mode | 4;     // EN=1, RW=0, RS=mode
    seq[2] = seq[1] & ~4;               // EN=0, RW=0, RS=mode
    seq[3] = (c << 4) | mode | 4;       // EN=1, RW=0, RS=mode
    seq[4] = seq[3] & ~4;               // EN=0, RW=0, RS=mode
    ret = I2C_WRITESEQ(PCF8574A, seq, 5);
    if (!(mode & 1) && c <= 2)
        _delay_ms(2);                    // CLS and HOME
    return ret;
}

// set the LCD display position  x=0..39 y=0..3
void lcd_gotoxy(unsigned char x, unsigned char y)
{
    wr_lcd_mode(0x80 | (_base_y[y] | x), 0);
    _lcd_x=x;
    _lcd_y=y;
}
// clear the LCD
void lcd_clrscr(void)
{
    wr_lcd_mode(0x01, 0);
    _lcd_x = _lcd_y = 0;
}
// home the LCD
void lcd_home(void)
{
    wr_lcd_mode(0x02, 0);
    _lcd_x = _lcd_y = 0;
}
void lcd_putc(char c)
{
    if (_lcd_x>=_lcd_maxx || c == '\n')
    {
        lcd_gotoxy(0,++_lcd_y);
    }
    if (c != '\n') {
        ++_lcd_x;
        wr_lcd_mode(c, 1);
    }
}
// write the string str located in SRAM to the LCD
void lcd_puts(const char *str)
{
    while (*str) lcd_putc(*str++);
}
// write the string str located in FLASH to the LCD
void lcd_puts_p(const char *progmem_s)
{
    uint8_t c;
    while ((c = pgm_read_byte(progmem_s++)) != 0) lcd_putc(c);
}
void lcd_command(unsigned char cmd)
{
    wr_lcd_mode(cmd, 0);
}
void lcd_data(unsigned char data)
{
    wr_lcd_mode(data, 1);
}
// initialize the LCD controller
void lcd_init(unsigned char command)
{
    uint8_t nibbleval30[] = {0x30, 0x34, 0x30};
    uint8_t nibbleval20[] = {0x20, 0x24, 0x20};
	uint8_t ret = 0;
    _lcd_maxx = LCD_DISP_LENGTH;
    _base_y[2] = _base_y[0] + _lcd_maxx;
    _base_y[3] = _base_y[1] + _lcd_maxx;
    DDRB |= (1<<5); PORTB |= (1<<5);
    I2C_INIT();
    _delay_ms(30);               // 30 ms Delay nach power-up
    ret |= I2C_WRITESEQ(PCF8574A, nibbleval30, 3);    //0x3- 8-bit  
    _delay_ms(5);
    ret |= I2C_WRITESEQ(PCF8574A, nibbleval30, 3);    //0x3- 8-bit
    ret |= I2C_WRITESEQ(PCF8574A, nibbleval30, 3);    //0x3- 8-bit
    ret |= I2C_WRITESEQ(PCF8574A, nibbleval20, 3);    //0x2- 8-bit
	ret |= wr_lcd_mode(0x28, 0);                      //0x28 set 4-bit 2 lines
    if (ret) { PORTB &= ~(1<<5); }
    wr_lcd_mode(0x0c, 0);
    wr_lcd_mode(0x06, 0);
    wr_lcd_mode(0x01, 0);
    wr_lcd_mode(command, 0);
}

void lcd_backlight(char on)
{
    wr_lcd_mode(on, 8);
}
