#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _cnode
{
	Element data;
	struct _cnode *next;
} *CNODE;

typedef struct _cll
{
	CNODE head;
	int size;
} *CLL;

CLL createCLL()
{
	CLL c = (CLL)malloc(sizeof(struct _cll));
	c->head = NULL;
	c->size = 0;
	return c;
}

void addFirst(CLL list, Element data)
{
	CNODE temp = (CNODE)malloc(sizeof(struct _cnode));
	temp->data = data;
	temp->next = NULL;

	if(list->head == NULL)
	{
		list->head = temp;
		temp->next = temp;
	}
	else
	{
		temp->next = list->head;
		
	}
}