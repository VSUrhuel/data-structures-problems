#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;

node *create();
void preorder(node *tree);
void postorder(node *tree);
void inorder(node *tree);

int main()
{
    node *root;
    // Call create function
    root = create();

    printf("Preorder is (Root, Left,Right): \n");
    preorder(root);
    printf("\nInorder is (Left, Root, Right): \n");
    inorder(root);
    //printf("\nPostorder is (Left, Root, Right): \n");
    //postorder(root);
}

node *create()
{
    // Allocate a memory to a new node
    node *newNode = malloc(sizeof(node));

    // Get input from the user
    int n;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &n);

    // Check if its -1 and end end of node
    if(n == -1)
        return 0;

    // Assign the value to the node
    newNode->value = n;

    // Create a left node
    printf("Left node for %d\n", n);
    newNode->left = create();

    // Create a right node
    printf("Right node for %d\n", n);
    newNode->right = create();

    // Return root
    return newNode;
}

void preorder(node *root)
{
    // Order is Root, Left, Right
    // Check if root is NULL
    if(root == NULL)
        return;

    // Print the value on the root
    printf("%d, ", root->value);

    // Call the root on the left side
    preorder(root->left);
    // Call the root on the right side
    preorder(root->right);
}

void postorder(node *root)
{
    int ctr = 0;
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d, ", root->value);
}

void inorder(node *root)
{
    // Left, Root, Right
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d, ", root->value);
    inorder(root->right);
}
