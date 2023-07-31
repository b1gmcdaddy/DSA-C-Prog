#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "MyHeader.h"


int main() {
	
	VSpace vs = newVSpace(10);
	
	addElement(&vs, 1);
	addElement(&vs, 2);
	addElement(&vs, 3);
	addElement(&vs, 4);
	addElement(&vs, 13);
	addElement(&vs, 14);
	addElement(&vs, 12);
	
	visualize(vs);
	
	printf("\nAfer Removal: \n");
	removeElement(&vs, 14);
	visualize(vs);
	
//	addElement(&vs, 20);
//	addElement(&vs, 33);
//	addElement(&vs, 44);
//	addElement(&vs, 43);
//	addElement(&vs, 54);
//	addElement(&vs, 82);
//	visualize(vs);


	return 0;
}
