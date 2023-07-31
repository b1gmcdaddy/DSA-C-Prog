#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
typedef char String[20];

typedef struct{
	String word;
}Value;

typedef struct{
	Value *list;
	int max;
	int count;
}closedHash;

void initDict(closedHash *d, int size) {
    d->count = 0;
    d->max = size;
    d->list = malloc(sizeof(Value) * size);
    int i;
    for (i = 0; i < d->max; i++) {
        strcpy(d->list[i].word, "");
    }
}

int hash(String word){
	return word[0] % MAX;
}

bool insert(closedHash *d, String word){
	int hashValue = hash(word);
	
	if(strcmp(d->list[hashValue].word, "") == 0){
		strcpy(d->list[hashValue].word, word);
		d->count++;
		return true;
	}else{
		int i = 1;
		int newIndex = (hashValue + i) % d->max; 

		while(strcmp(d->list[newIndex].word, "") != 0) {
			i++;
			newIndex = (hashValue + i) % d->max;
		}
		strcpy(d->list[newIndex].word, word);
		d->count++;
		return true;
	}
	return false;
}

void display(closedHash d){
	printf("Linear Probing Dictionary: \nINDEX: ");
	int i;
	
	for(i=0; i < d.max; i++){
		printf("%6d | ", i);
	}
	printf("\nWORDS: ");
	for(i=0; i < d.max; i++){
		printf("%6s | ", d.list[i].word);
	}
}


int main(){
	closedHash d;
	initDict(&d, MAX);
	insert(&d, "Jolo");
	insert(&d, "Annie");
	insert(&d, "Hub");
	insert(&d, "John");
	
	display(d);
	
	
	return 0;
}
