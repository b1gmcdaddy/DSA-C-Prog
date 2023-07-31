#ifndef LL_STACK_H
#define LL_STACK_H

typedef int Data;

typedef struct node{
	Data data;
	struct node* next;
} Stack;

void initStack(Stack** head);
bool isEmpty(Stack* head);
void push(Stack** head, Data value);
void pop(Stack** head);
Data peek(Stack* head);
void display(Stack* head);
void visualize(Stack* head);


#endif
