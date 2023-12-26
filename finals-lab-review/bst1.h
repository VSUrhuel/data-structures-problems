#ifndef BST1_H 
#define BST1_H 

#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _bstnode
{
	Element data;
	struct _bstnode *right, *left;
} *BSTNODE;

typedef struct _bst
{
	BSTNODE root;
	int size;
} *BST;

BST createBST();
//void BST_insertIterative(BST tree, Element data);
void BST_insertRecursive(BST tree, Element data);
void insertBST(BSTNODE *root, Element data);

//int BST_searchIterative(BST tree, Element data);
int BST_serchRecursive(BST tree, Element data);
int searchBST(BSTNODE root, Element data);

int BST_delete(BST tree, Element data);
int deleteBST(BSTNODE *root, Element data);

void displayPre(BST tree);
void preorder(BSTNODE root);
void displayIn(BST tree);
void inorder(BSTNODE root);
void displayPost(BST tree);
void postorder(BSTNODE root);

BSTNODE searchNode(BST tree, Element data);
BSTNODE searchN(BSTNODE root, Element data);
int isLeaf(BSTNODE root);
int isInternalNode(BSTNODE root);
int isRoot(BSTNODE root);
int computeLevel(BST tree, Element data);
int levelBST(BSTNODE root, Element data);
int heightBST(BSTNODE node);
int computeHeight(BST tree);

void displayAncestor(BST tree, Element data);
int ancestor(BSTNODE node, Element data);

int countLeaves(BST tree);
int leaves(BSTNODE node);

int countInternalNode(BST tree);
int internalNode(BSTNODE node);
#endif
