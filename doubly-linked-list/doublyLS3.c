#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct dnode
{
	Element data;
	struct dnode *prev;
	struct dnode *next;
} *DNODE;

typedef struct dll
{
	DNODE head, tail;
	int size;
} *DOUBLYLINKEDLIST;

DOUBLYLINKEDLIST createList()
{
	DOUBLYLINKEDLIST d = (DOUBLYLINKEDLIST)malloc(sizeof(struct dnode));
	d->head = d->tail = NULL;
	d->size = 0;
	return d;
}

void addLast(DOUBLYLINKEDLIST list, Element data)
{
	DNODE temp = (DNODE)malloc(sizeof(struct dnode));
	temp->data = data;
	temp->next = temp->prev = NULL;
	if(list->head == NULL || list->tail == NULL)
	{
		list->head = list->tail = temp;
	}
	else
	{
		temp->prev = list->tail;
		list->tail->next = temp;
		list->tail = temp;
	}
	list->size++;
}

void insertPos(DOUBLYLINKEDLIST list, Element data, int pos)
{
	DNODE temp = (DNODE)malloc(sizeof(struct dnode));
	temp->data = data;
	temp->prev = temp->next = NULL;
	DNODE p = list->head;
	if(pos < 1 || pos > list->size)
		return;
	if(pos == 1)
	{
		temp->next = list->head;
		list->head = temp;
	}
	else if(pos == list->size)
	{
		temp->prev = list->tail;
		list->tail->next = temp;
		list->tail = temp;
	}
	else
	{
		for(int i=0; i<pos-1; i++)
			p = p->next;
		temp->prev = p->prev;
		temp->next = p;
		p->prev->next = temp;
	}
	list->size++;
}
int main()
{
	DOUBLYLINKEDLIST list = createList();
	addLast(list, 3);
	addLast(list, 5);
	addLast(list, 1);
	addLast(list, 8);
	addLast(list, 9);
	insertPos(list, 12, 3);
	insertPos(list, 7, 1);
	insertPos(list, 19, 7);

	printf("Original List: ");
	DNODE p = list->head;
	for(int i=0; i<list->size; i++)
	{
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}