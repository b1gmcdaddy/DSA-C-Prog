#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "VHeapStackQueue.h"


Date newDate(int date, int month, int year) {
    Date nd;
    nd.date = date;
    nd.month = month;
    nd.year = year;
    return nd;
}

Product newProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp) {
    Product prod;
    prod.prodID = prodID;
    strcpy(prod.prodName, prodName);
    prod.prodQty = prodQty;
    prod.prodPrice = prodPrice;
    prod.prodExp = prodExp;
    return prod;
}

void initVirtualSpace(VirtualSpace *vs) {
    int i;
    for(i = 0; i < MAX - 1; i++){
        vs->data[i].link = i + 1;
    }
    vs->data[i].link = -1;
    vs->avail = 0;
}

int allocSpace(VirtualSpace *vs) {
    int retVal = vs->avail;
	if (retVal == -1) {
        printf("VSpace FULL\n");
        return -1; 
    }
    vs->avail = vs->data[retVal].link;
    return retVal;
}

void deallocSpace(VirtualSpace *vs, int index) {
	if(index != -1 && index < MAX){
    	vs->data[index].link = vs->avail;
    	vs->avail = index;
    }
}

void initStack(VirtualSpace *vs, StackList *s) {
    *s = -1;
}

bool isEmpty(VirtualSpace vs, StackList s) {
    return s == -1;
}

bool isFull(VirtualSpace vs, StackList s) {
    return vs.avail == -1;
}

void push(VirtualSpace *vs, StackList *s, Product prod) {
    if(isFull(*vs, *s)) {
        printf("STACK FULL\n");
        return;
    }
    int newData = allocSpace(vs);
    vs->data[newData].items = prod;
    vs->data[newData].link = *s;
    *s = newData;
}

void pop(VirtualSpace *vs, StackList *s) {
    if(isEmpty(*vs, *s)) {
        printf("STACK EMPTY\n");
        return;
    }
    int top = *s;
    *s = vs->data[top].link;
    deallocSpace(vs, top);
    printf("The top has been popped!\n\n");
}

int peek(VirtualSpace vs, StackList s) {
    if(isEmpty(vs, s)) {
        printf("STACK EMPTY.\n");
        return -1; 
    }
    return vs.data[s].items.prodID;
}

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isQueueEmpty(Queue q) {
    return q.front == -1;
}

bool isQueueFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(VirtualSpace *vs, Queue *q, Product prod) {
    if(isQueueFull(*q)) {
        printf("QUEUE FULL\n");
        return;
    }
    int newData = allocSpace(vs);
    vs->data[newData].items = prod;
    vs->data[newData].link = -1;
    
    if(isQueueEmpty(*q)) {
        q->front = newData;
        q->rear = newData;
    } else {
        vs->data[q->rear].link = newData;
        q->rear = newData;
    }
}

void dequeue(VirtualSpace *vs, Queue *q) {
    if(isQueueEmpty(*q)) {
        printf("QUEUE EMPTY\n");
        return;
    }
    int frontQ = q->front;
    q->front = vs->data[frontQ].link;
    deallocSpace(vs, frontQ);
    printf("Dequeue Successful\n\n");
}

int front(VirtualSpace vs, Queue q) {
    if(isQueueEmpty(q)) {
        printf("QUEUE EMPTY\n");
        return -1; 
    }
    return vs.data[q.front].items.prodID;
}

void visualize(VirtualSpace vs, StackList stack, Queue queue) {
    int i;
    int linearIndex = 0; 

    printf("%-8s | %-8s | %-8s | %s\n", "Index", "ProdID", "Label", "ADT");
    printf("---------------------------------------------------\n");

    for (i = stack; i != -1; i = vs.data[i].link) {
        printf("%-8d | %-8d | ", linearIndex, vs.data[i].items.prodID);
        if (i == stack) {
            printf("Top      | ");
        } else {
            printf("         | ");
        }
        printf("STACK\n");

        linearIndex++; 
    }

    for (i = queue.front; i != -1; i = vs.data[i].link) {
        printf("%-8d | %-8d | ", linearIndex, vs.data[i].items.prodID);
        if (i == queue.front) {
            printf("Front    | ");
        } else if (i == queue.rear) {
            printf("Rear     | ");
        } else {
            printf("         | ");
        }
        printf("QUEUE\n");

        linearIndex++; 
    }

    printf("---------------------------------------------------\n");
}


