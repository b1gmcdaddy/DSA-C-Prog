#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyHeader.h"


int main() {
	Set setUnion, setInter, setDiff, setSymm; 
	
    Set setA = newSet();
    Set setB = newSet();
    
    addElement(&setA, 1);
    addElement(&setA, 2);
    addElement(&setA, 3);
    addElement(&setA, 4);
    addElement(&setB, 2);
    addElement(&setB, 4);
    addElement(&setB, 5);
    addElement(&setB, 6);
    addElement(&setB, 7);
    
    printf("Set A: "); 
	displaySet(setA);
    printf("Set B: "); 
	displaySet(setB); 
	printf("\n");
	
	setUnion = unionSet(setA, setB);
	setInter = intersectionSet(setA, setB);
	setDiff = differenceSet(setA, setB);
	setSymm = symmetricDiffSet(setA, setB);
	
	printf("Union Set: "); displaySet(setUnion);
	printf("Intersection Set: "); displaySet(setInter);
	printf("Difference Set: "); displaySet(setDiff);
	printf("SymmetricDiff Set: "); displaySet(setSymm);
	
	printf("\nCardinality of SetA: %d", cardinality(setA));
	printf("\nCardinality of SetB: %d", cardinality(setB));
	
    printf("\n\nVisualize Set A: "); visualize(setA);
    printf("\n\nVisualize Set B: "); visualize(setB);
    printf("\n\n");


    return 0;
}
