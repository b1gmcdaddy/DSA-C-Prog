#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "MyHeader.h"

Set newSet(){
	int i;
	Set s;
    s.count = 0;
    for(i = 0; i < MAX; i++) {
        s.elems[i] = 0;
    }
    return s;
}

bool addElement(Set *s, int item){
    s->elems[item] = 1;
    s->count++;
    return true;
}

bool removeElement(Set *s, int item){
    s->elems[item] = 0;
    s->count--;
    return true;
}

void displaySet(Set s){
	int i;
    for(i = 0; i < MAX; i++) {
        if(s.elems[i]) {
            printf("%d ", i);
        }
    } printf("\n");
} 

Set unionSet(Set a, Set b){
	Set result = newSet();
	int i;
    for(i = 0; i < MAX; i++) {
        if(a.elems[i] || b.elems[i]) {
            addElement(&result, i);
        }
    }
    return result;
}

Set intersectionSet(Set a, Set b){
	Set result = newSet();
	int i;
    for (i = 0; i < MAX; i++) {
        if(a.elems[i] && b.elems[i]) {
            addElement(&result, i);
        }
    }
    return result;
}

Set differenceSet(Set a, Set b){
	Set result = newSet();
	int i;
    for(i = 0; i < MAX; i++) {
        if(a.elems[i] && !b.elems[i]) {
            addElement(&result, i);
        }
    }
    return result;
}

Set symmetricDiffSet(Set a, Set b){
	Set result = newSet();
	int i;
    for (i = 0; i < MAX; i++) {
        if(a.elems[i] != b.elems[i]) {
            addElement(&result, i);
        }
    }
    return result;
}

int cardinality(Set s){
	return s.count; 
}

void visualize(Set s){     //optional

	printf("\n--------------------------------------------------------------------------------------------------------------------\n");
	printf("INDEX: ");
	int i;
	for(i=0; i<9; i++){
		printf("%d  | ", i);
	}
	for(i=10; i<MAX; i++){
		printf("%d | ", i);
	}
	printf("\n");
	printf("SET:   ");
	for(i=0; i<MAX-1; i++){
		printf("%d  | ", s.elems[i]);
	}		
	
}
