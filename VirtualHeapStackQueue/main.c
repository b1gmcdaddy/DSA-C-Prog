#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "VHeapStackQueue.h"


int main() {
	int i, choice, ID;
	Product toPush, toEnqueue;
    VirtualSpace vs;
    StackList s;
    Queue q;
    
    initVirtualSpace(&vs);
    initStack(&vs, &s);
    initQueue(&q);
	    
    String menuOption[5] = {"Push", "Enqueue", "Pop", "Dequeue", "Visualize"};
	printf("MENU\n");
	
	do{
		system("cls");
		printf("MENU\n");
		for(i=0; i<5; i++){
			printf("[%d] %s\n", i+1, menuOption[i]);	
		}
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:  
				printf("Enter product ID to push to stack: ");    //ID lang ako gipangayo sa user sir hehe peace
				scanf("%d", &ID);
				toPush = newProduct(ID, "StackProduct", 5, 6.9, newDate(1, 1, 1));				
				push(&vs, &s, toPush);
				printf("Product added to stack->virtualSpace\n\n");							
				break;
			case 2:
				printf("Enter product ID to enqueue: ");
				scanf("%d", &ID);
				toEnqueue = newProduct(ID, "QueueProduct", 6, 6.9, newDate(1, 1, 1));
				enqueue(&vs, &q, toEnqueue);
				printf("Product added to queue->virtualSpace\n\n");
				break;
			case 3: 
				pop(&vs, &s);
				visualize(vs,s,q);
				break;
			case 4:
				dequeue(&vs, &q);
				visualize(vs,s,q);
				break;
			case 5:
				visualize(vs, s, q);
				break;
			default:
				printf("EXITED\n\n");		
		}
		system("pause");
	}while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);


    return 0;
}

