#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
#define EMPTY 9999
#define DELETED 9998
 
typedef char String[20];

typedef struct node{
	String data;
	struct node* next;
} Node;

typedef struct{
	Node* arr[MAX];
	int count;
	int max;
} Dictionary;


void initDict(Dictionary* d){
	d->count = 0;
	d->max = MAX; 
	int i;
	for (i=0; i<MAX; i++){
		d->arr[i] = NULL;
	}
}

int hash(String name){
	return name[0] % MAX;
}

void insert(Dictionary *d, String name){
	int hashValue = hash(name);
	
	Node* new = malloc(sizeof(struct node));
	strcpy(new->data, name);
	new->next = NULL;
	
	if (d->arr[hashValue] == NULL) {
    	d->arr[hashValue] = new;
	} else {
    	Node* current = d->arr[hashValue];
    	while (current->next != NULL) {
        	current = current->next;
    	}
    current->next = new;
	}
}


void display(Dictionary d) {
    int i;

    for (i = 0; i < MAX; i++) {
        printf("[%d]: ", i);
        Node* current = d.arr[i];
        while (current != NULL) {
            printf("%s ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void removeString(Dictionary *d, String keyword){
	int index = hash(keyword);
	
	Node* current = d->arr[index];
	Node* prev = NULL;
	
	while(current!=NULL){
		if(strcmp(current->data, keyword)==0){
			if(prev == NULL){
				d->arr[index] = current->next;
			} else{
				prev->next = current->next;
			}
			free(current);
		}
		prev = current;
		current = current->next;
	}
}


int main(){
	Dictionary d;
	initDict(&d);
	
	insert(&d, "Jolo");
	insert(&d, "Hello");
	insert(&d, "John");
	insert(&d, "Greeat");
	insert(&d, "Buri");
	
	display(d);
	printf("\n\n");
	
	removeString(&d, "John");
	display(d);
	return 0;
}
