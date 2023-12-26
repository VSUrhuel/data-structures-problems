#include "bst2.h"

int main()
{
	BST tree = createBST();
	BST_insertRecursive(tree, 30);
	BST_insertRecursive(tree, 7);
	BST_insertRecursive(tree, 4);
	BST_insertRecursive(tree, 8);
	BST_insertRecursive(tree, 10);
	BST_insertRecursive(tree, 16);
	BST_delete(tree, 4);
	printf("%d", BST_serchRecursive(tree,16));
	//BST_insertIterative(tree, 20);
	displayPre(tree);
	displayIn(tree);
	displayPost(tree);
}