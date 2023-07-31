#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef int List;

typedef struct{
	char elem;
	int next;
} Node;

typedef struct{
	Node H[MAX];
	int avail;
} VHeap;


VHeap initVHeap(){
	VHeap vh;
	int i;
	for(i=0; i<MAX; i++){
		vh.H[i].next = i-1;
	}
	vh.avail = MAX-1;
	return vh;
}

int allocSpace(VHeap* vh){
	int retVal = vh->avail;
	
	if (retVal != -1){
		vh->avail = vh->H[retVal].next;
	}
	return retVal;
}

void insertSorted(VHeap *vh, List *top, char elem){
	List temp;
	temp = allocSpace(vh);
	if(temp !=-1){
		for(top = top; *top != -1 && vh->H[*top].elem < elem; top = &vh->H[*top].next){}
		vh->H[temp].elem = elem;
		vh->H[temp].next = *top;
		*top = temp;
	}
}

void display(VHeap vh, List top){
	List trav;
	for(trav = top; trav!=-1; trav = vh.H[trav].next){
		printf("%c ", vh.H[trav].elem);
	}
}

void dealloc(VHeap *vh, int index){
	vh->H[index].next = vh->avail;
	vh->avail = index;
}

void deleteElem(VHeap *vh, List *top, char elem){
	List *trav, temp; 
	for(trav = top; *trav != -1 && elem != vh->H[*trav].elem; trav = &vh->H[*trav].next){}
	if(*trav!=-1){
		temp = *trav;
		*trav = vh->H[temp].next;
		dealloc(vh, temp);
	}
}


int main(){
	VHeap vh = initVHeap();
	List top = -1;
	
	insertSorted(&vh, &top, 'j');
	insertSorted(&vh, &top, 'a');
	insertSorted(&vh, &top, 'z');
	
	display(vh,top);
	printf("\n\n");
	deleteElem(&vh, &top, 'j');
	display(vh, top);
	return 0;
}







