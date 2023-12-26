#include "bst.h"

int main()
{
	BST tree = createBST();
	
	BST_insertRecursive(tree, 30);
	BST_insertRecursive(tree, 7);
	BST_insertRecursive(tree, 61);
	BST_insertRecursive(tree, 8);
	BST_insertRecursive(tree, 10);
	BST_insertRecursive(tree, 16);
	BST_insertRecursive(tree, 35);
	BST_insertRecursive(tree, 50);
	//BST_delete(tree, 4);
	//printf("%d", BST_serchRecursive(tree,16));
	//BST_insertIterative(tree, 20);
	displayPre(tree);
	displayIn(tree);
	displayPost(tree);
	//BSTNODE b = searchNode(tree, (30));
		//printf("Value: %d\t Is Leaf: %d, Is Internal Node: %d, Is root: %d\n", (30)	, isLeaf(b), isInternalNode(b), isRoot(b));	
	printf("%d\n", computeHeight(tree));
	
}