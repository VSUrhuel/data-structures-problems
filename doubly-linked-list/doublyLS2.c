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
void deleteMiddle(DOUBLYLINKEDLIST list)
{
	DNODE p = list->head;
	for(int i=0; i<list->size/2; i++)
		p = p->next;
	DNODE temp = p;
	p->prev->next = temp->next;
	temp->next->prev = p->prev;
	free(temp);
	list->size--;
}
void deleteData(DOUBLYLINKEDLIST list, Element data)
{
	DNODE p = list->head;
	for(int i=0; i<list->size; i++)
	{
		if(data == p->data && p == list->head)
		{
			DNODE temp = p;
			list->head = p->next;
			p->next->prev = NULL;
			free(temp);
			list->size--;
		}
		else if(data == p->data && p == list->tail)
		{
			DNODE temp = p;
			p->prev->next = NULL;
			list->tail = p->prev;
			free(temp);
			list->size--;
		}
		else if(data == p->data)
		{
			DNODE temp = p;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(temp);
			list->size--;
		}
		p = p->next;
	}
}
void deletePos(DOUBLYLINKEDLIST list, int pos)
{
	if(pos>0 && pos<list->size+1)
	{
		DNODE p = list->head;
		for(int i=0; i<pos-1; i++)
			p = p->next;
		DNODE temp = p;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(temp);
		list->size--;
	}
}
void pairSum(DOUBLYLINKEDLIST list, int sum)
{
	DNODE p = list->head;
	for(int i=0; i<list->size; i++)
	{
		DNODE q = list->head;
		int y = p->data;
		for(int j=0; j<list->size-1; j++)
		{
			if(sum == (y+q->data))
			{
				printf("(%d %d) ", y, q->data);
				break;
			}
			q = q->next;
		}
		p = p->next;
	}
}
void sort(DOUBLYLINKEDLIST list)
{
	for(int i=0; i<list->size; i++)
	{
		DNODE p = list->head;
		DNODE q = p;
		for(int j=0; j<list->size-1-i; j++)
		{
			if(q->data >= q->next->data)
			{
				int temp = q->data;
				q->data = q->next->data;
				q->next->data = temp;
			}
			q = q->next;
		}
	}
}
void rotateNNode(DOUBLYLINKEDLIST list, int rot)
{
	DNODE p = list->tail;
	p->next = list->head;
	DNODE q = list->head;
	for(int i=0; i<rot-1; i++)
		q = q->next;
	list->head = q;
	list->tail = q->prev;
}
DNODE mergeSort(DOUBLYLINKEDLIST list, DOUBLYLINKEDLIST list1)
{
	if(list->head->data > list1->head->data)
	{
		list1->tail->next = list->head;
		list1->size += list->size;
		sort(list1);
		return list1->head;
	}
	else
	{
		list->tail->next = list1->head;
		list->size += list1->size;
		sort(list);
		return list->head;
	}
}
void multiply(DOUBLYLINKEDLIST list, DOUBLYLINKEDLIST list1)
{
	int n=0, n1=0;
	DNODE p = list->head;
	for(int i=0; i<list->size; i++)
	{
		n = (n*10) + p->data;
		p = p->next;
	}
	p = list1->head;
	for(int i=0; i<list1->size; i++)
	{
		n1 = (n1*10) + p->data;
		p = p->next;
	}
	printf("Product: %d*%d == %d", n, n1, n*n1);
}
int main()
{
	DOUBLYLINKEDLIST list = createList();
	addLast(list, 3);
	addLast(list, 5);
	addLast(list, 1);
	DOUBLYLINKEDLIST list1 = createList();
	addLast(list1, 9);
	addLast(list1, 1);
	printf("Original List: ");
	DNODE p = list->head;
	for(int i=0; i<list->size; i++)
	{
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("NULL\n");
	printf("Original List: ");
	p = list1->head;
	for(int i=0; i<list1->size; i++)
	{
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("NULL\n");
	sort(list);
	sort(list1);

	multiply(list, list1);
	
}