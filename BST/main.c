#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "BST.h"


int main() {
	
	BSTPtr tree;
	initBST(&tree);
	
	//inserting recursive and iterative
	tree = addElement(tree, createProduct(11, "Prod11", 1, 1.00));
    tree = addElement(tree, createProduct(22, "Prod22", 5, 2.00));
    tree = addElement(tree, createProduct(33, "Prod33", 7, 3.00));
    tree = addElement(tree, createProduct(44, "Prod44", 13, 4.00));
    insertBST(&tree, createProduct(55, "Prod55", 13, 4.00));
	
	//traversals
	printf("Preorder traversal: \nProdID | ProdNAme\n");
	preorderBST(tree);
	printf("Inorder traversal: \n");
	inorderBST(tree);
	printf("Postorder traversal: \n");
	postorderBST(tree);
    
    //searching
    int search = 22;
    if(isMember(tree, search)){
    	printf("\nProduct %d is a member of the BST.", search);
	}else{
		printf("\nProduct %d is NOT a member of this BST.", search);
	}
	
	//max and min
	BST *maxNode = max(tree);
	printf("\n\nMAX \t");
	displayProduct(maxNode->data);
	BST *minNode = min(tree);
	printf("\nMIN \t");
	displayProduct(minNode->data);
	
	//deletions
	deleteElement(tree, 33);
	removeElement(&tree, 22);
	printf("\nDeletion: \n");
	preorderBST(tree);
	
	
	return 0;
}
