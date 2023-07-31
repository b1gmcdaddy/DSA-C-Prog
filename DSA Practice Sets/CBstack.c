#include<stdio.h>
#include<stdlib.h>

typedef int List;
typedef char String[20];
#define MAX 10

typedef struct{
	int elem;
	int next;
}Node;

typedef struct{
	Node elems[MAX];
	int avail;
} Heap;

Heap initHeap(){
	Heap vh;
	int i;
	for(i=0; i<MAX; i++){
		vh.elems[i].elem = 0;
		vh.elems[i].next = i-1;
	}
	vh.avail = MAX-1;
	return vh;
}

int allocSpace(Heap *vh){
	int retVal = vh->avail;
	
	if(retVal != -1){
		vh->avail = vh->elems[retVal].next;
	}
	return retVal;
}

void push(Heap *vh, List *L, int elem){
	List temp = allocSpace(vh);
	
	if(temp != -1){
		vh->elems[temp].elem = elem;
		vh->elems[temp].next = *L;
		*L = temp;
	}	
}

void visualize(Heap vh, List L){
	int i;
	for(i=0; i<MAX; i++){
		printf("%d | ", vh.elems[i].elem);
	}
	printf("\nTop of Stack: %d", L);
}

void dealloc(Heap *vh, int index){
	if(index != -1 && index<MAX){
	vh->elems[index].next = vh->avail;
	vh->elems[index].elem = 0;
	vh->avail = index;
  }
}

void pop(Heap *vh, List *L) {
    if (*L == -1) {
        printf("Stack is empty\n");
        return;
    }
    int top = *L;
    *L = vh->elems[top].next; // Update the top of the stack
    dealloc(vh, top); // Deallocate the top element
}


int main(){
	Heap vh = initHeap();
	List L = -1;
	
	push(&vh, &L, 22);
	push(&vh, &L, 5);
	push(&vh, &L, 99);
	push(&vh, &L, 56);
	
	visualize(vh, L);
	printf("\n\n");
	
	pop(&vh, &L);
	visualize(vh, L);
	printf("\n\n");
	
	push(&vh, &L, 111);
	push(&vh, &L, 21);
	visualize(vh, L);
	
	return 0;
}




















