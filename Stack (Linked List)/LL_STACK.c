#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "LL_STACK.h"


void initStack(Stack** head){
	*head = NULL;
}

bool isEmpty(Stack* head) {
    return(head == NULL);
}

void push(Stack** head, Data value){

	Stack* curr = malloc(sizeof(struct node));
		if(isEmpty(*head)){
			curr->data = value;
			curr->next = NULL;
			*head = curr;
		}
		else{
			curr->data = value;
			curr->next = *head;
			*head = curr;
		}
}

void pop(Stack** head){
	Stack* temp;

    if(isEmpty(*head))
        printf("EMPTY\n");
    else
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

Data peek(Stack* head){
	Stack* curr = head;
		if(isEmpty(head)){
			printf("EMPTY STACK");
			return 0;
		}else{
			return curr->data;
		}
}

void display(Stack* head){
	Stack* newStack;
	initStack(&newStack);
	
	while(!isEmpty(head)){
	Data top = peek(head);
	push(&newStack, top);
	pop(&head);
	}
	printf("DISPLAY NEW STACK: ");
	while(!isEmpty(newStack)){
		Data top = peek(newStack);
		printf("%d ", top);
		pop(&newStack);
	}
	printf("\n");
	
}

void visualize(Stack* head){
	Stack* curr = head;
	printf("LIST: ");
	while( curr!= NULL ){
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

