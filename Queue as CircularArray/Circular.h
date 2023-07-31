#ifndef CIRCULAR_H
#define CIRCULAR_H

#define MAX 10
#define EMPTY 9999

typedef char String[30];

typedef struct{
	int elems[MAX];
	int front;
	int rear;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void visualize(Queue q);
void display(Queue q);
void removeItem(Queue *q, int item);   
Queue removeEven(Queue *q);   				//remove all even # and return all deleted item stored in newQ
int doubleTheValue(Queue *q, int value);   // doubles the value in q that is a multiple of the given value and return how many values have been changed

#endif
