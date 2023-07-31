#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "CursorBased.h"


int main() {
	VirtualHeap myHeap = newVirtualHeap();
	List myList = -1;
	List anotherList = -1; 
	
	visualizeSpace(myHeap);
	
	insertFront(&myHeap, &myList, newStudent(101, "Patrick", 'm', "BSIT"));
	
	insertFront(&myHeap, &myList, newStudent(102, "Jolo", 'm', "BSCS"));
	insertFront(&myHeap, &myList, newStudent(103, "Alchemist", 'm', "BSCS"));
	visualizeSpace(myHeap);
	
	//displayList(myHeap, myList);
	printf("\n");
	Student test = removeStudent(&myHeap, &myList, "Jolo");
	visualizeSpace(myHeap);
	printf("Removed student: %d - %s\n\n", test.studID, test.studName);
	
	
	return 0;
}
