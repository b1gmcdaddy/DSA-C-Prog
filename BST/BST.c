#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include "BST.h"

//Add element ot the BST recursive
BST* addElement(BST *list, Product item){
    if (list == NULL) {
        BST *newNode = malloc(sizeof(BST));
        newNode->data = item;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (item.prodID < list->data.prodID) {
        list->left = addElement(list->left, item);
    } else if (item.prodID > list->data.prodID) {
        list->right = addElement(list->right, item);
    }
    return list;
}

void insertBST(BSTPtr *list, Product item){       //iterative
	BSTPtr newNode = malloc(sizeof(NodeType));
	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;
	
    if (*list == NULL) {
        *list = newNode;
        return;
    }
    struct node* curr = *list;
    while(curr){
        if(item.prodID < curr->data.prodID) {
            if (curr->left == NULL) {
                curr->left = newNode;
                break;
            }else{
                curr = curr->left;
            }
        }else if(item.prodID > curr->data.prodID) {
            if(curr->right == NULL) {
                curr->right = newNode;
                break;
            }else{
                curr = curr->right;
            }
        }
    }
}

//Delete element based on prodID
void removeElement(BST **list, int prodID){   //iterative
	BST **curr = list;
    while(*curr != NULL) {
        if(prodID < (*curr)->data.prodID){
            curr = &(*curr)->left;
        }else if(prodID > (*curr)->data.prodID){
            curr = &(*curr)->right;
        }else if(prodID == (*curr)->data.prodID){
            BST *temp = *curr;
            if((*curr)->left == NULL){
                *curr = (*curr)->right;
            }else if((*curr)->right == NULL){
                *curr = (*curr)->left;
            }else{
                BST *succ = (*curr)->right;
                while(succ->left != NULL){
                    succ = succ->left;
                }
                succ->left = (*curr)->left;
                *curr = (*curr)->right;
            }
            free(temp);
            return;
        }
    }
}

BST *deleteElement(BST *list, int prodID){   //recursive method
	if(list == NULL){
		printf("BST is empty.\n");
		return;
	}
	if(prodID < list->data.prodID){
		list->left = deleteElement(list->left, prodID);
	}else if(prodID > list->data.prodID){
		list->right = deleteElement(list->right, prodID);
	}else{
		if(list->left == NULL){
			BST*temp = list->right;
			free(list);
			return temp;
		}else if(list->right == NULL){
			BST* temp = list->left;
			free(list);
			return temp;
		}
		BST* succ = min(list->right);
		list->data = succ->data;
		list->right = deleteElement(list->right, succ->data.prodID);
	}
	return list;
}

//Display BST all in recursive method
void inorderBST(BST *list){       //LNR
	if(!isEmpty(list)){
		inorderBST(list->left);
		displayProduct(list->data);
		inorderBST(list->right);
	}
}

void preorderBST(BST *list){     //NLR
	if(!isEmpty(list)){
		displayProduct(list->data);
		preorderBST(list->left);
		preorderBST(list->right);
	}
}

void postorderBST(BST *list){     //LRN
	if(!isEmpty(list)){
		postorderBST(list->left);
		postorderBST(list->right);
		displayProduct(list->data);
	}
}

//Other functions
BST *newBST(){
	BST *bst = malloc(sizeof(BST));
	bst->left = NULL;
    bst->right = NULL;
	return bst;
}


void initBST(BST **list){
	*list = NULL;
}


bool isEmpty(BST *list){
	return list == NULL;
}

Product createProduct(int id, char *name, int qty, float price){
	Product p;
	p.prodID = id;
	strcpy(p.prodName, name);
	p.prodQty = qty;
	p.prodPrice = price;
	return p;
}

void displayProduct(Product p){
	printf("<%d>  |  <%s>\n", p.prodID, p.prodName);
}

BST *max(BST *list){
	if(list == NULL || list->right == NULL){
        return list;
    }
    return max(list->right);
}

BST *min(BST *list){
	if(list == NULL || list->left == NULL){
		return list;
	}
	return min(list->left);
}

bool isMember(BST *list, int prodID){
	if(list == NULL) {
        return false;
    }
    if(prodID < list->data.prodID) {
        return isMember(list->left, prodID);
    }else if(prodID > list->data.prodID) {
        return isMember(list->right, prodID);
    } 
    return true;
}
