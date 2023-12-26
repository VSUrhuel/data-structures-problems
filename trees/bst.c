#include "bst.h"


BST createBST()
{
	BST tree = (BST)malloc(sizeof(struct _bst));
	tree->root = NULL;
	tree->size = 0;
	return tree;
}

void BST_insertIterative(BST tree, Element data)
{
	BSTNODE* curr = &(tree->root);
	while(*curr != NULL)
	{
		if(data < (*curr)->data)
			curr = &((*curr)->left);
		else
			curr = &((*curr)->right);
	}
	*curr = (BSTNODE)malloc(sizeof(struct _bstnode));
	(*curr)->data = data;
	(*curr)->left = (*curr)->right = NULL;
	tree->size++;
}

void BST_insertRecursive(BST tree, Element data)
{
	insertBST(&(tree->root), data);
	tree->size++;
}

void insertBST(BSTNODE* root, Element data)
{
	if(*root == NULL)
	{
		*root = (BSTNODE)malloc(sizeof(struct _bstnode));
		(*root)->data = data;
		(*root)->left = (*root)->right = NULL;
	}
	else if(data < (*root)->data)
		insertBST(&((*root)->left), data);
	else
		insertBST(&((*root)->right), data);
}

int BST_searchIterative(BST tree, Element data)
{
	BSTNODE* curr = &(tree->root);
	while(*curr != NULL)
	{
		if((*curr)->data == data)
			return 1;
		else if(data < (*curr)->data)
			curr = &((*curr)->left);
		else
			curr = &((*curr)->right);
	}

	return 0;
}

int BST_searchRecursive(BST tree, Element data)
{
	return searchBST(tree->root, data);
}

int searchBST(BSTNODE root, Element data)
{
	if(root == NULL)
		return 0;
	else if(data == root->data)
		return 1;
	else if(data < root->data)
		return searchBST(root->left, data);
	else
		return searchBST(root->right, data);
}

int BST_delete(BST tree, Element data)
{
	int x = deleteBST(&(tree->root), data);
	if(x)
		tree->size--;
	return x;

}

int deleteBST(BSTNODE* root, Element data)
{
	if(*root == NULL)
		return 0;
	else if(data < (*root)->data)
		return deleteBST(&(*root)->left, data);
	else if(data > (*root)->data)
		return deleteBST(&(*root)->right, data);
	else
	{
		if((*root)->left == NULL)
		{
			BSTNODE p = (*root)->right;
			free(*root);
			*root = p;
			return 1;
		}
		else if((*root)->right == NULL)
		{
			BSTNODE p = (*root)->right;
			free(*root);
			*root = p;
			return 1;
		}
		else
		{
			BSTNODE p = (*root)->left;
			while(p->right != NULL)
				p = p->right;
			(*root)->data = p->data;
			return deleteBST(&((*root)->left), (*root)->data);
		}
	}
}

void displayPre(BST tree)
{
	printf("[");
	preorder(tree->root);
	printf("]\n");
}
void preorder(BSTNODE root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void displayIn(BST tree)
{
	printf("[");
	inorder(tree->root);
	printf("]\n");
}

void inorder(BSTNODE root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void displayPost(BST tree)
{
	printf("[");
	postorder(tree->root);
	printf("]\n");
}

void postorder(BSTNODE root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int computeLevel(BST tree, Element data)
{
	return levelBST(tree->root, data);
}

int levelBST(BSTNODE root, Element data)
{
	if(root == NULL)
		return -1;
	else
	{
		if(data == root->data)
			return 0;
		int levelL = levelBST(root->left, data);
		int levelR = levelBST(root->right, data);
		int max = (levelL > levelR)? levelL:levelR;
		if(max > -1)
			return max+1;
		else
			return -1;
	}
}

int computeHeight(BST tree)
{
	return heightBST(tree->root);
}

int heightBST(BSTNODE root)
{
	if(root == NULL)
		return 0;
	else
	{
		int heightL = heightBST(root->left);
		int heightR = heightBST(root->right);
		int max = (heightL > heightR)? heightL:heightR;
		if(max > -1)
			return max+1;
		else 
			return 0;
	}
}

int isRoot(BST tree, Element data)
{
	return tree->root->data == data;
}

void nodeTraverse(BSTNODE* p, Element data)
{
	while(*p != NULL)
	{
		if(data == (*p)->data)
			break;
		else if(data < (*p)->data)
			*p = (*p)->left;
		else
			*p = (*p)->right;
	}
}

int isLeaf(BST tree, Element data)
{
	BSTNODE* p = &(tree->root);
	nodeTraverse(&(*p),data);
	if((*p)->left == NULL)
	{
		if((*p)->right == NULL)
			return 1;
		else 
			return 0;
	}
	else
		return 0;
}

int isInternalNode(BST tree, Element data)
{
	return (!isRoot(tree, data) && !isLeaf(tree, data))? 1:0;
}