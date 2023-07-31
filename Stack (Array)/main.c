#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ARRAY_STACK.h"

int main() {
    Stack s;
    initStack(&s);
	
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    // prints 30, 20 ,10
    visualize(&s);
    
    Data peekValue = peek(&s);
    // should print 30
    printf("Top is %d\n", peekValue);
    
    pop(&s);
    // should print 20, 10
    visualize(&s);
    
    printf("DISPLAY FUNCTION STACK: ");
    display(&s);
    
    

    return 0;
}
