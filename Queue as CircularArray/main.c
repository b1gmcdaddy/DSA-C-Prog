#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Circular.h"


int main() {
	int choice, i, value, frontValue, itemtoRemove, itemRemoved, numDoubled;
	String menuOption[10] = {"Enqueue", "Dequeue", "isEmpty", 
							"isFull", "Display", "Visualize", 
							"Front", "RemoveItem", 
							"RemoveEvenNumbers", "Double The Value"};
	Queue myQueue;
	initQueue(&myQueue);
	Queue evenNumbers;
	
	do{
		system("cls");
		printf("MENU\n");
		for(i=0; i<10; i++){
			printf("[%d] %s\n", i+1, menuOption[i]);	
		}
		printf("Enter your choice <0 to EXIT>: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enqueue\n");
				printf("Enter a number: ");
				scanf("%d", &value);
				enqueue(&myQueue, value);
				visualize(myQueue);
				break;
			case 2:
				printf("Dequeue\n");
				dequeue(&myQueue);
				visualize(myQueue);
				break;
			case 3:
				printf("Check if Empty\n");
				if(isEmpty(myQueue)){
					printf("Queue Empty\n\n");
				}else{
					printf("NOT Empty\n\n");
				}
				break;
			case 4:
				printf("Check if Full\n");
				if(isFull(myQueue)){
					printf("Queue FULL\n\n");
				}else{
					printf("NOT FULL\n\n");
				}
				break;
			case 5:
				printf("Display Queue\n");
				display(myQueue);
				break;
			case 6:
				printf("Visualize Queue\n");
				visualize(myQueue);
				break;
			case 7:
				printf("Front\n");
				frontValue = front(myQueue);
				printf("Front is: %d\n\n", frontValue);
				break;
			case 8:
				removeItem(&myQueue, 22);
				visualize(myQueue);
				break;
			case 9:
				evenNumbers = removeEven(&myQueue);
    			printf("\nTemp Queue Containing the Removed Even Numbers:\n");
    			visualize(evenNumbers);
				break;
			case 10:
				numDoubled = doubleTheValue(&myQueue, 2);
				printf("\n\nThe number of doubled values are %d: \n", numDoubled);				
				visualize(myQueue);
				break;
			case 0:
				printf("Thank you!\n");
				break;
			default:
				printf("Invalid choice...\n");
				
		}
		system("pause");
	}while (choice != 0);
	printf("BYE\n");
	
	
	
	return 0;
}
