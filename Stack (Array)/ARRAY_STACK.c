#include<stdio.h>
#include<stdbool.h>
#include "ARRAY_STACK.h"


void initStack(Stack* s) {
    s->top = -1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, Data value) {
    if (isFull(s)) {
        printf("STACK FULL\n");
        return;
    }
    s->elems[++(s->top)] = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY\n");
        return;
    }
    s->top--;
}

Data peek(Stack* s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY\n");
        return;
    }
    return s->elems[s->top];
}

void display(Stack* s){
	Stack newStack;
	initStack(&newStack);
	
	while(!isEmpty(s)){
		push(&newStack, peek(s));
		pop(s);
	}
	while(!isEmpty(&newStack)){
		printf("%d ", peek(&newStack));
		pop(&newStack);
	}
	printf("\n");
}

void visualize(Stack* s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY\n");
        return;
    }
	Data i;
    printf("STACK: ");
    for (i = s->top; i >= 0; i--) {
        printf("%d ", s->elems[i]);
    }
    printf("\n");
}

