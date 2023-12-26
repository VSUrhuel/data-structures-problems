#include "bst1.h"

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
	if(root == NULL)
		return -1;
	else
	{
		if(data == root->data)
			return 0;
		int l = (root->left, data);
		int r = (root->right, data);
		int max = (l > r) ? l : r;
		if(max > -1)
			return max+1;
		else
			return -1;
	}
}

if(x->right == y || x->left == y)
	return 1;


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
		int l = heightBST(root->left);
		int r = heightBST(root->right);
		int max = (l > r) ? l : r;
		return max + 1;
	}
}

void displayAncestor(BST tree, Element data)
{
	printf("ancestor of: %d\n[%d,", data, data);
	ancestor(tree->root, data);
	printf("]\n");
}
int ancestor(BSTNODE node, Element data)
{
	if(node == NULL)
		return 0;
	if(data == node->data)
		return 1;
	if(ancestor(node->left, data) || ancestor(node->right, data))
	{
		printf("%d,", node->data);
		return 1;
	}
	return 0;
}

int descendants(BSTNODE node, Element data)
{
	if(node == NULL)
		return 0;
	if(ancestor(node->left, data) || ancestor(node->right, data))
	{
		printf("%d,", node->data);
		return 1;
	}
	if(data == node->data)
		return 1;
	return 0;
}

int countLeaves(BST tree)
{
	return leaves(tree->root);
}

int leaves(BSTNODE root)
{
	if(root == NULL)
		return 0;
	if(root->right == NULL && root->left == NULL)
		return 1;
	else
	{
		int l = leaves(root->left);
		int r = leaves(root->right);
		return l+r+1;
	}
}

int countInternalNode(BST tree)
{
	return internalNode(tree->root);
}

int internalNode(BSTNODE root)
{
	if(root==NULL)
		return 0;
	if(root->right == NULL && root->left == NULL)
        return 0;
	int countL = internalNode(root->left);
	int countR = internalNode(root->right);
	return countL + countR + 1;
}