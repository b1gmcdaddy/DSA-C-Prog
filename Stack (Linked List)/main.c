#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "LL_STACK.h"



int main(){
	Stack* head;
	initStack(&head);
	Data value; 
	Data peekValue;
	
	Data action;
	printf("MENU");
	do{
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Visualize\n0. Exit\n\nChoose action: ");
        scanf("%d", &action);

        switch (action){
        case 1:
        	printf("Enter value to add to stack: ");
			scanf("%d", &value);
            push(&head, value);
            system("cls");
            break;
        case 2:
            pop(&head);
            printf("Element has been popped!\n");
            break;
        case 3:
            peekValue = peek(head);
            printf("Top of Stack is: %d\n\n", peekValue);
            break;
        case 4:
        	display(head);
        	break;
        case 5:
        	visualize(head);
        	break;
        case 0:
            printf("You have exited.");
            break;
        default:
            printf("Press any key to try again");
            getch();
            break;
        }
       
    }while(action != 0);


}

