#include<stdio.h>
#include<stdlib.h>

typedef int List;
#define MAX 10

typedef struct{
	int data;
	int next;
} Node;

typedef struct{
	Node elems[MAX];
	int front, rear, avail;
} VHeap;


VHeap initVHeap(){
	VHeap vh;
	int i;
	for(i=0; i<MAX; i++){
		vh.elems[i].next = i+1;
	}
	vh.elems[i].next = -1;
	vh.avail = 0;
	vh.front = -1;
	vh.rear = -1;
	return vh;
}

int isEmpty(VHeap *vh) {
    return vh->front == -1;
}

int isFull(VHeap *vh) {
    return vh->avail == -1;
}

void enqueue(VHeap* vh, List *L, int data){
	if(isFull(vh)){
		printf("LIST FULL.\n");
		return;
	}
	int index = vh->avail;
	vh->avail = vh->elems[index].next;
	vh->elems[index].data = data;
	vh->elems[index].next = -1;
	
	if(isEmpty(vh)){
		vh->front = index;
		vh->rear = index;
	}else{
		vh->elems[vh->rear].next = index;
		vh->rear = index;
	}	
}

void dequeue(VHeap* vh){
	if(isEmpty(vh)){
		printf("LIST EMPTY.\n");
		return;
	}
	
	int index = vh->front;
	vh->front = vh->elems[index].next;
	vh->elems[index].next = vh->avail;
}

void display(VHeap vh) {
    if (isEmpty(&vh)) {
        printf("Queue is empty.\n");
        return;
    }
    int currentIndex = vh.front;
    int i;
    for (i = 0; i<MAX; i++){
		printf("%5d | ", i);
	}
	printf("\n");
    while (currentIndex != -1) {
        printf("%5d | ", vh.elems[currentIndex].data);
        currentIndex = vh.elems[currentIndex].next;
    }

    printf("\nAVAIL: %d\n", vh.avail);
    printf("\n");
}


int main(){
	VHeap vh = initVHeap();
	List L = -1;
	
	enqueue(&vh, &L, 11);
	enqueue(&vh, &L, 22);
	enqueue(&vh, &L, 33);
	
	display(vh);
	
	dequeue(&vh);
	display(vh);
	
	enqueue(&vh, &L, 88);
	enqueue(&vh, &L, 55);
	display(vh);
	printf("\nFront: %d Rear: %d", vh.front, vh.rear);
	
	return 0;
}
