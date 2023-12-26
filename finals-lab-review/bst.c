#include "bst.h"

BST createBST()
{
	BST tree = (BST)malloc(sizeof(struct _bst));
	tree->root = NULL;
	tree->size = 0;
	return tree;
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
		insertBST(&((*root)->left), data);
	else
		insertBST(&((*root)->right), data);
}

int BST_serchRecursive(BST tree, Element data)
{
	return searchBST(tree->root, data);
}

int searchBST(BSTNODE root, Element data)
{
	if(root->data == data)
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

int deleteBST(BSTNODE *root, Element data)
{
	BSTNODE temp;
	if(*root ==  NULL)
		return 0;
	if(data < (*root)->data)
		return deleteBST(&((*root)->left), data);
	else if(data > (*root)->data)
		return deleteBST(&((*root)->right), data);
	else
	{
		if((*root)->left == NULL)
		{
			temp = (*root)->right;
			free(*root);
			*root = temp;
			return 1;
		}
		else if((*root)->right == NULL)
		{
			temp = (*root)->left;
			free(*root);
			*root = temp;
			return 1;
		}
		else
		{
			temp = (*root)->left;
			while(temp->right != NULL)
				temp = temp->right;
			free(*root);
			*root = temp;
			(*root)->data = temp->data;
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

BSTNODE searchNode(BST tree, Element data)
{
	return searchN(tree->root, data);
}
BSTNODE searchN(BSTNODE root, Element data)
{
	if(root->data == data)
		return root;
	else if(data < root->data)
		return searchN(root->left, data);
	else
		return searchN(root->right, data);
}

int isLeaf(BSTNODE root)
{
	return root->left == NULL && root->right == NULL;
}

int isInternalNode(BSTNODE root)
{
	return root->left != NULL || root->right !=NULL;
}

int isRoot(BSTNODE root)
{
	return !isLeaf(root) && !isInternalNode(root);
}

int computeLevel(BST tree, Element data)
{
	return levelBST(tree->root, data);
}
int levelBST(BSTNODE root, Element data)
{
	if(root==NULL)
		return -1;
	else
	{
		if(root->data == data)
			return 0;
		int l = levelBST(root->left, data), r = levelBST(root->right, data);
		int max = (l>=r) ? l : r;
		if(max >= 0)
			return max + 1;
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
	else if(!root->left && !root->right)
		return 1;
	else
	{
		int l = heightBST(root->left), r = heightBST(root->right);
		return (l>=r) ? l+1 : r+1;
	}
}


/*Level
	param(tree->root, node)
	if(root == NULL)
		return -1;
	if(root->data == node->data)
		return 0;
	find level of left;
	find level of right;
	max(left, right);
	if(max > -1)
		return max + 1;
	else
		return 1;
Height
	if(root == NULL)
		return -1;
	else if(!root->left && !root->right)
		return 0;
	else
		int l = heiht(root->left), r = height(root->right);
		return (l > r) ? l+1 : r+1;*/


