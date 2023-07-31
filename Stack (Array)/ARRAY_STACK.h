#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#define MAX 20

typedef int Data;

typedef struct {
	Data elems[MAX];
	int top;
} Stack;

void initStack(Stack* s);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, Data value);
void pop(Stack* s);
Data peek(Stack* s);  
void display(Stack* s);  
void visualize(Stack* s);  

#endif
