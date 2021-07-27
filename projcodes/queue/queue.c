/*
 * queue.c
 *
 * Created: 7/27/2021 8:18:16 PM
 *  Author: ASUS
 */ 
#ifndef QUEUE_ADDED
#define QUEUE_ADDED

#include "../all.h"

struct queue *q;


void queueConstructor(struct queue *qPtr){ qPtr->head = NULL; qPtr->tail = NULL; qPtr->h = qPtr->t = 0; }
int empty(struct queue *qPtr) { return qPtr->t == qPtr->h; }
void enqueue(struct queue *qPtr, struct Patient* newPatient) {
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->patient = newPatient;
	newnode->next = NULL;
	if(!qPtr->head){
		qPtr->head = newnode;
		qPtr->tail = newnode;
	}
	else{
		qPtr->tail->next = newnode;
		qPtr->tail = newnode;
	}
	qPtr->t++;
}
struct Patient* dequeue(struct queue *qPtr) {
	if(qPtr->head){
		struct node *t = (struct node*) malloc(sizeof(struct node));
		struct Patient* p = qPtr->head->patient;
		t = qPtr->head->next;
		// free(head);
		qPtr->head = t;
		// free(t);
		qPtr->h++;
		return p;
	}
	return NULL;
}
struct Patient* front(struct queue *qPtr) {
	return qPtr->head->patient;
}
struct Patient* end(struct queue *qPtr) {
	return qPtr->tail->patient;
}
int size(struct queue *qPtr) { return qPtr->t - qPtr->h; }
int currentPatientSerial(struct queue *qPtr) {
	return qPtr->head ? qPtr->head->patient->serial : -1;
}
int nextPatientSerial(struct queue *qPtr) {
	return qPtr->head ? qPtr->head->next ? qPtr->head->next->patient->serial : -1 : -1;
}


#endif
