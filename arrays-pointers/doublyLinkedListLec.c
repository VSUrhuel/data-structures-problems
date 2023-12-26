#include <stdio.h>
#include <stdlib.h>

typedef char Element;

typedef struct dnode
{
	Element data;
	struct dnode *prev;
	struct dnode *next;
} *DNODE;

typedef struct doublylinkedlist
{
	DNODE head;
	DNODE tail;
	int size;
} *DOUBLYLINKEDLIST;

DOUBLYLINKEDLIST createlist()
{
	DOUBLYLINKEDLIST s = (DOUBLYLINKEDLIST) malloc(sizeof(struct snode));
	s->head = NULL;
	s->tail = NULL;
	s->size = 0;
	return s;
}


void addFirst(DOUBLYLINKEDLIST list, Element data)
{
	DNODE p = (DNODE) malloc(sizeof(struct dnode));
	p->data = data;
	p->next = list->head;
	p->prev = NULL;

	if(list->size==0)
		list->tail = p;
	else
		list->head-prev = p;

	list->head = p;
	list->size++;
}

void addLast(DOUBLYLINKEDLIST list, Element data)
{
	DNODE p = (DNODE) malloc(sizeof(struct dnode));
	p->data = data;
	p->next = NULL;
	p->prev = list->head;

	if(list->size==0)
		list->head = p;
	else
		//TODO



}

void deleteFirst(DOUBLYLINKEDLIST list, Element data)
{
	if(list->size > 0)
	{
		DNODE p = list->head;
		list->head = p->next;
		if(list->head!=NULL)
			list->head->prev = NULL;
		free(p);
		list->size
	}
}

void 
int main()
{
	DNODE head = (DNODE)malloc(sizeof(struct dnode));
	head->data = 'A';
	head->prev = NULL;
	head->next = (DNODE)malloc(sizeof(struct dnode));

	head->next->data = 'B';
	head->next->prev = head;
	head->next->next = (DNODE)malloc(sizeof(struct dnode));

	head->next->next->data = 'C';
	head->next->next->prev = head->next;
	head->next->next->next=NULL;
	DNODE tail = head->next->next;

	printf("Front:\n");
	DNODE p = head;
	while(p!=NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}

	printf("\nRear:\n");
	p = tail;
	while(p!=NULL)
	{
		printf("%c ", p->data);
		p = p->prev;
	}

	//if front to delete - redirect head
	//if last to delete - redirect tail
	//if between to delete - normal
	//if empty list after to delete - redirect tail to NULL

	DNODE z = (DNODE)malloc(sizeof(struct dnode));
	z->data = 'X';
	z->prev = head->next;
	z->next = tail;
	head->next->next = z;
	tail->prev = z;

	//Delete A
	z = head;
	head = head->next;
	free(z);
	head->prev = NULL;

	printf("Front:\n");
	p = head;
	while(p!=NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}

	printf("\nRear:\n");
	p = tail;
	while(p!=NULL)
	{
		printf("%c ", p->data);
		p = p->prev;
	}





}