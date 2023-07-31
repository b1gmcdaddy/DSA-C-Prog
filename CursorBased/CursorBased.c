#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CursorBased.h"



Student newStudent(int studID, String studName, char sex, String program){
	Student s;
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex = sex;
	strcpy(s.program, program);	
	return s;
}

VirtualHeap newVirtualHeap(){
	VirtualHeap vh;
	int i;
	for(i=0; i<MAX; i++){
		vh.elems[i].elem = newStudent(0, "", ' ', "");
		vh.elems[i].next = i-1;
	}
	vh.avail = MAX-1;
	return vh; 
}

int allocSpace(VirtualHeap *vh){
	int retVal = vh->avail;
	
	if(retVal != -1){
		vh->avail = vh->elems[retVal].next;
	}
	return retVal;
}

void insertFront(VirtualHeap *vh, List *list, Student s){
	List temp = allocSpace(vh);
	
	if(temp != -1){
		vh->elems[temp].elem = s;
		vh->elems[temp].next = *list;
		*list = temp;
	}
}
void displayList(VirtualHeap vh, List list) {
    List current = list;
    List tempList = -1;
    while (current != -1) {
        insertFront(&vh, &tempList, vh.elems[current].elem);
        current = vh.elems[current].next;
    }
    printf("displayList function:\n");
    current = tempList;
    while (current != -1) {
        printf("Student ID: %d\n", vh.elems[current].elem.studID);
        printf("Name: %s\n\n", vh.elems[current].elem.studName);
        current = vh.elems[current].next;
    }
}

void visualizeSpace(VirtualHeap vh){
	int i;
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	printf("---------------------------------------------\n");
	for(i=0; i<MAX; i++){
		printf("%5d | ", i);
		if(vh.elems[i].elem.studID == 0){
			printf("%30s | ", "Empty");
		}else{
			printf("%4d - %-23s | ", vh.elems[i].elem.studID, vh.elems[i].elem.studName);
		}
		printf("%d\n", vh.elems[i].next);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d\n\n", vh.avail);
}

void deallocSpace(VirtualHeap *vh, int index){
	if(index != - 1 && index < MAX){
		vh->elems[index].next = vh->avail;
		vh->elems[index].elem = newStudent(0, "", ' ', "");
		vh->avail = index;
	}
}


Student removeStudent(VirtualHeap *vh, List *list, String keyword){
    List trav = *list;
    List temp = NULL;

    while (trav != -1) {
        if(strcmp(vh->elems[trav].elem.studName, keyword)==0){
            if(temp == -1) {
                *list = vh->elems[trav].next; 
            }else{
                vh->elems[temp].next = vh->elems[trav].next;
            }
            Student removedStudent = vh->elems[trav].elem;
            deallocSpace(vh, trav); 
            return removedStudent;
        }
        temp = trav;
        trav = vh->elems[trav].next;
    }
}

