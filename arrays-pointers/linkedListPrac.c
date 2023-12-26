#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

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

    //We create a traversing pointer
    node *ptr = list;
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

