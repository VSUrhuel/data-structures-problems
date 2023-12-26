#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _dnode
{
	Element data;
	struct _dnode *prev;
	struct _dnode *next;
} *DNODE;

typedef struct _dll
{
	DNODE head;
	DNODE tail;
	int size;
} *DOUBLYLINKEDLIST;

DOUBLYLINKEDLIST createList()
{
	DOUBLYLINKEDLIST list = (DOUBLYLINKEDLIST)malloc(sizeof(struct _dll));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}
void addFirst(DOUBLYLINKEDLIST list, Element data)
{
	DNODE temp = (DNODE)malloc(sizeof(struct _dnode));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;

	if(list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
	}
	else
	{
		temp->next = list->head;
		list->head->prev = temp;
		list->head = temp;
	}
	list->size++;
}
void addLast(DOUBLYLINKEDLIST list, Element data)
{
	DNODE temp = (DNODE)malloc(sizeof(struct _dnode));
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;

	if(list->head == NULL)
	{
		list->tail = temp;
		list->head = temp;
	}
	else
	{
		list->tail->next = temp;
		temp->prev = list->tail;
		list->tail = temp;
	}
	list->size++;
}
void printMiddle(DOUBLYLINKEDLIST list)
{
	DNODE p = list->head;
	for(int i=0; i<list->size/2; i++)
		p = p->next;
	printf("Middle data: %d\n", p->data);
}
void insertMiddle(DOUBLYLINKEDLIST list, Element data)
{
	DNODE temp = (DNODE)malloc(sizeof(struct _dnode));
	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;

	if(list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
	}
	int limit = (list->size/2)-1;
	DNODE p = list->head;
	for(int i=0; i<limit; i++)
		p = p->next;
	temp->next = p->next;
	temp->prev = p;
	p->next = temp;
	list->size++;
}
void deleteData(DOUBLYLINKEDLIST list, Element data)
{
	if(list->size>0)
	{
		if(list->head->data == data)
		{
			DNODE temp = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			free(temp);
		}
		else if(list->tail->data == data)
		{
			DNODE temp = list->tail;
			list->tail = list->tail->prev;
			list->tail->next = NULL;
			free(temp);
		}
		else
		{
			DNODE p = list->head;
			while(p->next != NULL)
			{
				if(p->next->data == data)
				{
					DNODE temp = p->next;
					p->next = temp->next;
					temp->next->prev = p;
					free(temp);
				}
				else
					p = p->next;
			}
		}
		list->size--;
	}
}
void sortedInsert(DOUBLYLINKEDLIST list, Element data)
{
	DNODE temp = (DNODE)malloc(sizeof(struct _dnode));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;

	DNODE p = list->head;
	for(int i=0; i<list->size; i++)
	{
		if(data <= p->data && p->prev->data <= data)
		{
			temp->prev = p->prev;
			temp->next = p;
			p->prev->next = temp;
			list->size++;
			break;
		}
		else
			p = p->next;
	}
}
void sortList(DOUBLYLINKEDLIST list)
{
	for(int i=0; i<list->size; i++)
	{
		DNODE p = list->head;
		DNODE q = p;
		for(int j=0; j<list->size-1-i; j++)
		{
			if(q->data>q->next->data)
			{
				int temp = q->data;
				q->data = q->next->data;
				q->next->data = temp;
			}
			q = q->next;
		}
	}
}
void exchangeFirst(DOUBLYLINKEDLIST list)
{
	int temp = list->head->data;
	list->head->data = list->tail->data;
	list->tail->data =  temp;
}
void reverseList(DOUBLYLINKEDLIST list)
{
	/*DNODE p = list->head;
	for(int i=0; i<list->size-1; i++)
		p = p->next;
	list->tail = p;*/
	DNODE p = list->head;
	for(int i=0; i<list->size-1; i++)
	{
		DNODE temp = p->prev;
		p->prev = p->next;
		p->next = temp;
		p = p->prev;
	}
	list->head = p->prev;	
}
int main()
{
	DOUBLYLINKEDLIST list = createList();
	/*addFirst(list, 1);
	addFirst(list, 2);
	addFirst(list, 4);
	addLast(list, 6);
	insertMiddle(list, 3);
	deleteData(list, 1);*/
	addLast(list, 3);
	addLast(list, 5);
	addLast(list, 1);
	addLast(list, 8);
	addLast(list, 20);
	printf("Original List: ");
	DNODE p = list->head;
	for(int i=0; i<list->size; i++)
	{
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("NULL\n");
	reverseList(list);
	printf("Updated List: ");
	p = list->head;
	for(int i=0; i<list->size; i++)
	{
		printf("%d<->", p->data);
		p = p->next;
	}
	//exchangeFirst(list);
	//sortList(list);
	//sortedInsert(list, 8);
	
	printf("NULL\n");
	printMiddle(list);
}