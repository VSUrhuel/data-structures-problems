#include "bst.h"

int main()
{
	BST tree = createBST();
	BST_insertIterative(tree, 30);
	BST_insertIterative(tree, 7);
	BST_insertIterative(tree, 4);
	BST_insertIterative(tree, 8);
	BST_insertIterative(tree, 10);
	BST_insertIterative(tree, 16);
	//BST_insertIterative(tree, 20);
	displayPre(tree);
	displayIn(tree);
	displayPost(tree);
	printf("%d\n",computeHeight(tree));
	printf("%d-isLeaf?: %d\n", 30,isLeaf(tree, 30));
	printf("%d-isInternalNode?: %d\n", 8,isInternalNode(tree, 8));

	return 0;
}