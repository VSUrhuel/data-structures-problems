in#include "bst2.h"

BST createBST()
{
	BST b = (BST)malloc(sizeof(struct _bst));
	b->size = 0;
	b->root = NULL;
	return b;
}

void BST_insertIterative(BST tree, Element data)
{
	BSTNODE *curr = &(tree->root);
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

void insertBST(BSTNODE *root, Element data)
{
	if(*root == NULL)
	{
		*root = (BSTNODE)malloc(sizeof(struct _bstnode));
		(*root)->data = data;
		(*root)->left = (*root)->right = NULL;
	}
	else if(data < (*root)->data)
		insertBST(&(((*root)->left)), data);
	else
		insertBST(&(((*root)->right)), data);
}

int BST_searchIterative(BST tree, Element data)
{
	BSTNODE *curr = &(tree->root);
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

int BST_serchRecursive(BST tree, Element data)
{
	return searchBST(tree->root, data);
}

int searchBST(BSTNODE root, Element data)
{
	if(root == NULL)
		return 0;
	else if((root)->data == data)
		return 1;
	else if(data < (root)->data)
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

int deleteBST(BSTNODE *root, Element data)
{
	if(*root == NULL)
		return 0;
	if(data < (*root)->data)
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
			BSTNODE p = (*root)->left;
			free(*root);
			*root = p;
			return 1;
		}
		else
		{
			BSTNODE p = (*root)->left;
			while(p->right != NULL)
				p = p->right;
			free(*root);
			(*root)->data = p->data;
			return deleteBST(&((*root))->left, (*root)->data);
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
	if(root!=NULL)
	{
		printf("%d,", root->data);
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
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d,", root->data);
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
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d,", root->data);
	}	
}

/*int computeLevel(BST tree, Element data);
{

}
int levelBST(BSTNODE root, Element data);*/