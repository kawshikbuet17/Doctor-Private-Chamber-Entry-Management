#ifndef QUEUE_ADDED
#define QUEUE_ADDED

#include "../all.h"

struct node
{
    struct node *next;
    struct Patient *patient;
};

struct queue
{
    struct node *head, *tail;
    int h, t;
    queue(){ head = NULL; tail = NULL; h = t = 0; }
    int empty() { return t == h; }
    void enqueue(struct Patient* newPatient) {
        struct node *newnode = (struct node*) malloc(sizeof(struct node));
        newnode->patient = newPatient;
        newnode->next = NULL;
        if(!head){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        t++;
    }
    struct Patient* dequeue() {
        if(head){
            node *t = (struct node*) malloc(sizeof(struct node));
            struct Patient* p = head->patient;
            t = head->next;
            // free(head);
            head = t;
            // free(t);
            h++;
            return p;
        }
        return NULL;
    }
    struct Patient* front() {
        return head->patient;
    }
    struct Patient* end() {
        return tail->patient;
    }
    int size() { return t - h; }
    int currentPatientSerial() {
        return head ? head->patient->serial : -1;
    }
    int nextPatientSerial() {
        return head ? head->next ? head->next->patient->serial : -1 : -1;
    }
} q ;

#endif