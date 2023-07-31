#ifndef VHEAP_STACKQUEUE_H
#define VHEAP_STACKQUEUE_H

#define MAX 20

typedef char String[20];

typedef struct{				//Date struct
	int date, month, year;
} Date;

typedef struct{				//Product struct		   
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
} Product;

typedef struct{				//LL
	Product items;
	int link;
} SType;

typedef struct{				//VirtualHeap
	SType data[MAX];
	int avail;
} VirtualSpace;

typedef int StackList;

typedef struct{				//Queue struct
	int front, rear;
} Queue;


//Create new Date and Product
Date newDate(int date, int month, int year);
Product newProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp);

//VirtualSpace functions
void initVirtualSpace(VirtualSpace *vs);
int allocSpace(VirtualSpace *vs);
void deallocSpace(VirtualSpace *vs, int index);
void visualize(VirtualSpace vs, StackList stack, Queue queue);

//Stack functions
void initStack(VirtualSpace *vs, StackList *s);
bool isEmpty(VirtualSpace vs, StackList s);
bool isFull(VirtualSpace vs, StackList s);
void push(VirtualSpace *vs, StackList *s, Product prod);
void pop(VirtualSpace *vs, StackList *s);
int peek(VirtualSpace vs, StackList s);

//Queue functions
void initQueue(Queue *queue);
void enqueue(VirtualSpace *vs, Queue *q, Product prod);
void dequeue(VirtualSpace *vs, Queue *q);
bool isQueueEmpty(Queue q);
bool isQueueFull(Queue q);
int front(VirtualSpace vs, Queue q);


#endif







