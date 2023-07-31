#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "MyHeader.h"


VSpace newVSpace(int max) {
    VSpace vs;
    
    vs.max = max%2 == 0? max: max + 1;
    vs.count = 0;
    vs.data = malloc(sizeof(Data) * vs.max);
    vs.avail = vs.max/2;
    
    int i;
    for(i = 0; i < vs.avail; ++i) {
        vs.data[i].elem = EMPTY;
        vs.data[i].link = -1;
    }
    
    for(; i < vs.max-1; ++i) {      //where the collisions will be stored
        vs.data[i].elem = EMPTY;
        vs.data[i].link = i + 1;    
    }
    vs.data[i].elem = EMPTY;
    vs.data[i].link = -1;
    
    return vs;
}

int hash(int val, int size){
	return val % (size);
}
/*
void rehash(VSpace* vs) {
    int newSize = vs->max * 2;
    Data* newData = malloc(sizeof(Data) * newSize);
    int i;
    for (i = 0; i < newSize; ++i) {
        newData[i].elem = EMPTY;
        newData[i].link = -1;
    }
    int j;
    for (j = 0; j < vs->max; ++j) {
        if (vs->data[j].elem != EMPTY && vs->data[j].elem != DELETED) {
            int index = hash(vs->data[j].elem, newSize);
            while (newData[index].elem != EMPTY && newData[index].elem != DELETED) {
                index = (index + 1) % newSize;  // Linear probing
            }
            newData[index].elem = vs->data[j].elem;
            newData[index].link = -1;
        }
    }
    free(vs->data);
    vs->data = newData;
    vs->avail = vs->max / 2;  
    vs->max = newSize;
}

*/

bool addElement(VSpace* vs, int elem) {
    if (vs->avail == -1) {
//        rehash(vs);
    }

    int index = hash(elem, vs->max);

    if (vs->data[index].elem == EMPTY || vs->data[index].elem == DELETED) {
        vs->data[index].elem = elem;
        vs->count++;
        return true;
    } else {
        vs->data[index].link = vs->avail;
        int temp = vs->avail;
        if (temp != -1) {
            vs->avail = vs->data[temp].link;
            vs->data[temp].elem = elem;
            vs->data[temp].link = -1;
        }
    }
    return false;
}

void visualize(VSpace vs) {
    int i, half = vs.max/2;
    printf("%5s | %5s | %5s %10s %5s | %5s | %5s \n", "INDEX", "DATA", "LINK", "","INDEX", "DATA", "LINK");
    printf("----------------------          ----------------------\n");    
    for(i = 0; i < half; ++i) {
        printf("%5d | %5d | %5d %10s %5d | %5d | %5d \n", 
                i, vs.data[i].elem, vs.data[i].link, "",
                i + half, vs.data[i+half].elem, vs.data[i+half].link);
    }
    printf("\nAVAIL: %d\n\n", vs.avail);
}

void freeSpace(VSpace *vs, int loc) {
    if(loc < vs->max / 2 || loc >= vs->max){
        return;    //only synonym area can be freed
    }
    vs->data[loc].elem = EMPTY;
    vs->data[loc].link = vs->avail;
    vs->avail = loc;
}

bool removeElement(VSpace *vs, int elem) {
    int index = hash(elem, vs->max);
    
    if(vs->data[index].elem == elem){
        vs->data[index].elem = DELETED;
        vs->count--;
        return true;
    }else{
        int prev = index;
        int curr = vs->data[index].link;
        while (curr != -1) {
            if(vs->data[curr].elem == elem){
                vs->data[curr].elem = DELETED;
                vs->count--;
                vs->data[prev].link = vs->data[curr].link;
                freeSpace(vs, curr);
                return true;
            }
            prev = curr;
            curr = vs->data[curr].link;
        }
    } 
    return false;
}
