#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _bstnode
{
	Element data;
	struct _bstnode *left, *right;
} *BSTNODE;

typedef struct _bst
{
	BSTNODE root;
	int size;
} *BST;

BST createBST();
void BST_insertIterative(BST tree, Element data);
void BST_insertRecursive(BST tree, Element data);
void insertBST(BSTNODE* root, Element data);

int BST_searchIterative(BST tree, Element data);
int BST_searchRecursive(BST tree, Element data);
int searchBST(BSTNODE root, Element data);

int BST_delete(BST tree, Element data);
int deleteBST(BSTNODE* root, Element data);

void displayPre(BST tree);
void preorder(BSTNODE root);
void displayIn(BST tree);
void inorder(BSTNODE root);
void displayPost(BST tree);
void postorder(BSTNODE root);

int computeLevel(BST tree, Element data);
int levelBST(BSTNODE root, Element data);

int computeHeight(BST tree);
int heightBST(BSTNODE root);

int isRoot(BST tree, Element data);
int isLeaf(BST tree, Element data);
int isInternalNode(BST tree, Element data);

void nodeTraverse(BSTNODE* p, Element data);

#endif