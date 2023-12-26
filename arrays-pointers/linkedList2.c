#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

void create();
void insertEnd();
void insertBeginning();
void insertInN(int data, int pos);
void deleteNode(int n); //Index of node to be deleted
void deleteNodeValue(int value); //Value in a node tp be deleted
void print();
void reverseIterative();
void printInRecursion(node *head);
void reverseRecursion(node *head);

node *head;

int main()
{
    head = NULL;
    create();

    char ans;
    do
    {
        char c;
        printf("What action will you take?\n");
        printf("[E] Insert at End of Linked List\n");
        printf("[B] Insert at the Beginning of Linked List\n");
        printf("[M] Insert anywhere at the Linked List\n");
        printf("[D] Delete a Node Using Index\n");
        printf("[V] Delete a Node Using Value\n");
        printf("[I] Reverse Linked List in Iterative Way\n");
        printf("[R] Print Using Recusrion\n");
        printf("[K] Reverse Using Recursion\n");
        printf("Input: ");
        scanf("%s", &c);

        c = tolower(c);
        switch(c)
        {
        case 'e':
            {
                insertEnd();
                break;
            }
        case 'b':
            {
                insertBeginning();
                break;
            }
        case 'm':
            {
                int i;
                printf("How many insertion you need: ");
                scanf("%d", &i);
                int n[i], x[i];
                for(int k=0; k<i; k++)
                {
                    printf("Enter the data to be inserted and its index (n x): ");
                    scanf("%d %d", &n[k], &x[k]);
                }
                for(int k=0; k<i; k++)
                {
                    insertInN(n[k], x[k]);
                }
                break;
            }
        case 'd':
            {
                int n;
                printf("Enter the node index to be deleted (1-index): ");
                scanf("%d",&n);
                deleteNode(n);
                break;
            }
        case 'v':
            {
                int n;
                printf("Enter the value of a node to be deleted: ");
                scanf("%d", &n);
                deleteNodeValue(n);
                break;
            }
        case 'i':
            {
                reverseIterative();
                break;
            }
        case 'r':
            {
                printInRecursion(head);
                printf("\n");
                break;
            }
        case 'k':
            {
                reverseRecursion(head);
                break;
            }
        default:
            printf("Invalid Input\n");
        }
        print();

        printf("Would you Like to Repeat Action (y/n)?: ");
        scanf("%s", &ans);
        ans = tolower(ans);
    } while(ans == 'y');

}

void create()
{
    head = NULL;

    int n;
    do
    {
        printf("Enter the number of elements in the Linked List: ");
        scanf("%d", &n);
    } while(n <= 0);

    for(int i=0; i<n; i++)
    {
        node *temp = malloc(sizeof(node));
        if(temp == NULL)
            return;

        int value;
        printf("Enter the (%d) data to Linked List: ", i);
        scanf("%d", &value);

        temp->data = value;
        temp->link = NULL;

        temp->link = head;
        head = temp;
    }
}

void insertEnd()
{
    node *temp = (node *)malloc(sizeof(node));
    int value;
    printf("Enter a value to be added at the end of the Linked List: ");
    scanf("%d", &value);
    temp->data = value;
    temp->link = NULL;

    node *otherTemp = head;
    while(1)
    {
        otherTemp = otherTemp->link;
        if(otherTemp->link == NULL)
        {
            otherTemp->link = temp;
            break;
        }
    }
}

void insertBeginning()
{
    // Inserting at the beginning of the head
    node *temp = malloc(sizeof(node));
    int value;
    printf("Enter a value to be added at the beginning of the Linked List: ");
    scanf("%d", &value);
    temp->data = value;
    temp->link = head;
    head = temp;
}

void insertInN(int data, int pos)
{
    if(data<=0)
        return;
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    node *otherTemp = head;
    if(pos == 1)
    {
        temp->link = head;
        head = temp;
        return;
    }
    for(int i=1; otherTemp != NULL; otherTemp = otherTemp->link, i++)
    {
        if(i==pos)
        {
            node *otherTemp2 = otherTemp->link;
            otherTemp->link = temp;
            temp->link = otherTemp2;
        }
    }
}

void deleteNode(int n)
{
    node *temp = head;
    if(n==1)
    {
        head = temp->link;
        free(temp);
        return;
    }
    for(int i=0; i<n-2; i++)
       temp = temp->link;
    node *temp2 = temp->link;
    temp->link = temp2->link;
    free(temp2);
}

void deleteNodeValue(int n)
{
    node *temp = head;
    node *prev = temp;
    for(temp; temp!=NULL; temp = temp->link)
    {
        if(n == temp->data)
        {
            prev->link = temp->link;
            free(temp);
            return;
        }
        prev = temp;
    }
}

void reverseIterative()
{
    node *current = head;
    node *prev = NULL;
    node *next = NULL;
    for(current; current!=NULL; current=next)
    {
        next =  current->link;
        current->link = prev;
        prev = current;
    }
    head = prev;
}

void reverseRecursion(node *p)
{
    if(p->link == NULL)
    {
        head = p;
        return;
    }
    reverseRecursion(p->link);
    node *q = p->link;
    q->link = p;
    p->link = NULL;
}
void printInRecursion(node *head)
{
    if(head == NULL)
        return;
    printInRecursion(head->link);
    printf("%d, ", head->data);
}


void print()
{
    for(node *temp = head; temp != NULL; temp = temp->link)
    {
        printf("%d, ", temp->data);
    }
    printf("\n");
}
