#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *prev;
    struct node *next;
} node;

node *insert(node* head, int value);

int main()
{
   node *list = NULL;

    int s;
    do
    {
        printf("Enter the number of elements: ");
        scanf("%d", &s);
    } while(s <= 0);

    int arr[s];
    for(int i=0; i<s; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<s; i++)
    {
        // Allocate size to a node;
        node *n = malloc(sizeof(node));
        if(n == NULL)
            return 1;

        // Asign the corresponding value to its corresponding node
        n->value = arr[i];  //(*n).value = arr[i];
        n->next = NULL;

        // Prepend this to the list;
        n->next = list;
        list = n;

    }

    int k;
    print("Using insert function, what element should be added: ");
    scanf("%d", &k);

    node *j = insert(list, k);

    //We create a traversing pointer
    node *ptr = j;
    //Continue the loop while not reaching the NULL ptr
    while(ptr != NULL)
    {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }

    //Re assigne ptr to list
    ptr = list;
    while(ptr != NULL)
    {
        //We create a temp for a next ptr
       node *temp = ptr->next;
       //free the current ptr
       free(ptr);
       //Assign the current ptr to stored next ptr
       ptr = temp;
    }
}
node *insert(node* head, int value)
{
    //Dynamically allocate space for a new node
    node *n = malloc(sizeof(node));
    //Check to make sure we didn't run out of memory
    if(n == NULL)
        return;

    //Populate and insert the node at the beginning of the linked list
    n->value = value;
    n->next = head;
    n->prev = NULL;
    //Fix the prev pointer of the old head of the linke list
    head->prev = n;
    head = n;
    //Return a pointer to the new head of the linked list
    return head;
}
void delete(node *target)
{
    //Fix the pointers of the surrounding nodes to "skip over" target
    node *n = malloc(sizeof(node));
    n = target->next;
    node *l = malloc(sizeof(node));
    l = target->prev;
    n->prev = l->next;
    l->next = n;

    //Free target
    free(target);
}
