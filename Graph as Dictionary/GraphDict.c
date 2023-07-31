#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "GraphDict.h"


void initDict(Dictionary* d, int size){
	int i;
    for(i = 0; i < 26; i++){
        strcpy(d->dict[i].key, EMPTY);
        d->dict[i].list.count = 0;
        d->dict[i].list.max = size;
        d->dict[i].list.data = malloc(sizeof(String) * size);
    }
}

int hash(String word){
    return word[0] % 26;
}

bool addVertex(Dictionary *d, String word){
    int hashValue = hash(word);
    int index = hashValue;
   
    if(strcmp(d->dict[hashValue].key, EMPTY) == 0 || strcmp(d->dict[hashValue].key, DELETED) == 0) {
        strcpy(d->dict[hashValue].key, word);
        return true;
    }else{
        index = (index + 1) % 26;
        while(index != hashValue) {
            if(strcmp(d->dict[index].key, EMPTY) == 0 || strcmp(d->dict[index].key, DELETED) == 0) {
                strcpy(d->dict[index].key, word);
                return true;
            }
        	index = (index + 1) % 26;
        }
    }
    return false;
}


bool addEdge(Dictionary* dictionary, String src, String edge){
    int srcIndex = hash(src);
    int adjEdge = hash(edge);

    if(strcmp(dictionary->dict[srcIndex].key, src) != 0) {
        return false;
    }
    int count = dictionary->dict[srcIndex].list.count;
    if(count == dictionary->dict[srcIndex].list.max){
        return false;
    }
    strcpy(dictionary->dict[srcIndex].list.data[count], edge);
    dictionary->dict[srcIndex].list.count++;
    return true;
}


void display(Dictionary d){
	int i, j;
    for(i = 0; i < 26; i++){
        if(strcmp(d.dict[i].key, EMPTY) != 0 && strcmp(d.dict[i].key, DELETED) != 0){
            printf("[%d]%s ", i, d.dict[i].key);
            printf("[");
            for(j = 0; j < d.dict[i].list.count; j++){
                printf("%s,", d.dict[i].list.data[j]);
            }
            printf("]");
            printf("\n\n");
        }
    }
}

bool removeVertex(Dictionary* d, String word){
    int hashValue = hash(word);
    int index = hashValue;

    if(strcmp(d->dict[hashValue].key, word) == 0){
        strcpy(d->dict[hashValue].key, DELETED);
        d->dict[hashValue].list.count = 0;
        return true;
    }else{
        index = (index + 1) % 26;
        while(index != hashValue){
            if(strcmp(d->dict[index].key, word) == 0){
                strcpy(d->dict[index].key, DELETED);
                d->dict[index].list.count = 0;
                return true;
            }
            index = (index + 1) % 26;
        }
    }
    return false;
}

bool removeEdge(Dictionary* dictionary, String src, String edge){
	int i, j;
    int srcIndex = hash(src);
    int adjEdge = hash(edge);
    int count = dictionary->dict[srcIndex].list.count;

    if(strcmp(dictionary->dict[srcIndex].key, src) == 0){
        for (i = 0; i < count; i++) {
            if(strcmp(dictionary->dict[srcIndex].list.data[i], edge) == 0){
                for(j = i; j < count - 1; j++) {
                    strcpy(dictionary->dict[srcIndex].list.data[j], dictionary->dict[srcIndex].list.data[j + 1]);
                }
                dictionary->dict[srcIndex].list.count--;
                return true;
            }
        }
    }
    return false;
}

void BFS(Dictionary d, String start){
    int visited[26] = {0};  
    int queue[26];
    int front = -1, rear = -1, i;

    int startHash = hash(start);
    queue[++rear] = startHash;
    visited[startHash] = 1;
    printf("BFS Traversal with '%s' as start: \n", start);

    while (front != rear) {
        int current = queue[++front];
        printf("%s ", d.dict[current].key);
        for(i = 0; i < d.dict[current].list.count; i++) {
            int neighborHash = hash(d.dict[current].list.data[i]);
            if (!visited[neighborHash]) {
                queue[++rear] = neighborHash;
                visited[neighborHash] = 1;
            }
        }
    }
    printf("\n");
}
