#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
	int data;
	struct dnode *prev;
	struct dnode *next;
} *DNODE;

typedef struct DLL
{
	DNODE head;
	int size;
} *DOUBLYLINKEDLIST;

DOUBLYLINKEDLIST createList()
{
	DOUBLYLINKEDLIST d = (DOUBLYLINKEDLIST)malloc(sizeof(struct DLL));
	d->head = NULL;
	d->size = 0;
	return d;
}

void addFirst(DOUBLYLINKEDLIST list, int data)
{
	DNODE p = (DNODE)malloc(sizeof(struct dnode));
	p->data = data;
	p->prev = NULL;
	p->next = NULL;

	if(list->head == NULL)
		list->head = p;
	else
	{
		p->next = list->head;
		p->prev = NULL;
		list->head->prev = p;
		list->head = p;
	}
	list->size++;
}

void addLast(DOUBLYLINKEDLIST list, int data)
{
	DNODE p = (DNODE)malloc(sizeof(struct dnode));	
	p->data = data;
	p->prev = NULL;
	p->next = NULL;

	DNODE temp = list->head;
	while(temp->next!=NULL)
		temp = temp->next;
	p->prev = temp;
	temp->next = p;
	list->size++;
}

void deleteEnd(DOUBLYLINKEDLIST list)
{
	DNODE p = list->head;
	while(p->next!=NULL)
		p = p->next;
	DNODE temp = p;
	p->prev->next = NULL;
	free(temp);
	list->size--;
}

void deleteFirst(DOUBLYLINKEDLIST list)
{
	DNODE temp = list->head;
	list->head = list->head->next;
	list->head->prev = NULL;
	free(temp);
	list->size--;
}

void insertPos(DOUBLYLINKEDLIST list, int data, int pos)
{
	if(list->head == NULL)
		addFirst(list, data);
	else
	{
		DNODE p = list->head;
		while(pos!=1)
		{
			p = p->next;
			pos--;
		}
		DNODE temp = (DNODE)malloc(sizeof(struct dnode));
		temp->data = data;
		temp->prev = p;
		temp->next = p->next;
		p->next->prev = temp;
		p->next = temp;
		list->size++;
	}
}

int getMiddleValue(DOUBLYLINKEDLIST list)
{
	if(list->size % 2 != 0)
	{
		int limit = ((list->size)/2)+1;
		DNODE p = list->head;
		for(int i=0; i<limit-1; i++)
			p = p->next;
		return p->data;
	}
	else
	{
		int limit = ((list->size)/2);
		DNODE p = list->head;
		for(int i=0; i<limit; i++)
			p = p->next;
		int sum = p->data + p->prev->data;
		return sum/2;
	}
}
int main() {
    DOUBLYLINKEDLIST list = createList();

    // Add elements to the doubly linked list
    addFirst(list, 1);
    addLast(list, 3);
    addLast(list, 6);
    addLast(list, 8);
    addFirst(list, 9);
    //(list, 9);

    // Display the doubly linked list
    printf("Doubly Linked List: ");
    DNODE current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("getMiddleValue: %d", getMiddleValue(list));
   /* // Delete the first and last elements
    deleteFirst(list);
    deleteEnd(list);

    // Display the modified doubly linked list
    printf("Doubly Linked List after deleting first and last elements: ");
    current = list->head;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Insert an element at position 2
    insertPos(list, 'X', 2);

    // Display the doubly linked list after inserting an element
    printf("Doubly Linked List after inserting 'X' at position 2: ");
    current = list->head;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // Clean up and free memory
    while (list->head != NULL) {
        deleteFirst(list);
    }

    free(list);*/
    
    return 0;
}

