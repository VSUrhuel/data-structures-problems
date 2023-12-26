#include <stdio.h>
#include <stdlib.h>

typedef struct _snode
{
	int data;
	struct _snode *next;
} *SNODE;

typedef struct _sll
{
	SNODE head;
	int size;
} *SLL;

SLL createSLL()
{
	SLL s = (SLL)malloc(sizeof(struct _snode));
	s->head = NULL;
	s->size = 0;
	return s;
}

int addBetweenXandY(SLL list, int x, int y, int data)
{
	SNODE p = list->head;
	while(p!=NULL)
	{
		if(p->data == x && p->next->data == y)
		{
			SNODE s = (SNODE)malloc(sizeof(struct _snode));
			s->data = data;
			s->next = p->next;
			p = s;
			dll->size++;
			return 1;
		}
		p=p->next;
	}
	return 0;
}

typedef struct _dnode
{
	int data;
	struct _dnode *prev;
	struct _dnode *next;
} *DNODE;

typedef struct _dll
{
	DNODE head;
	int size;
} *DLL;

DLL createDLL()
{
	DLL l = (DLL)malloc(sizeof(struct _dll));
	l->head = NULL;
	l->size = 0;
	return l;
}
DLL createDLLX()
{
	DLL l = createDLLX();
	for(int i=10; i>0; i--)
		_addFirst(l, i);
	return l;
}

typedef struct _cnode
{
	char data;
	struct _cnode *next;
} *CNODE;

typedef struct _cll
{
	CNODE tail;
} *CLL;

CLL createCLL()
{
	CLL c = (CLL)malloc(sizeof(struct _cll));
	c->tail = NULL;
	return c;
}

void deleteAllX(CLL list, int x)
{
	if(list->size>0)
	{
		CNODE p = list->head, temp;
		while(p->next!=list->head)
		{
			if(p->next->data == x)
			{
				temp = p->next;
				p->next = temp->next;
				free(temp);
				list->size--;
			}
			p = p->next;
		}
		if(list->size==1 && list->head->data == x)
		{
			free(list->head);
			list->head == NULL;
			list->size--;
		}
		else if(list->head->data == x)
		{
			temp = list->head;
			list->head = list->head->next;
			while(p->next!=list->head)
				p = p->next;
			p->next = list->head;
			list->size--;
			free(temp);
		}
	}

}

int checkIfPalindrome(DLL list)
{
	int limit =  (list->size/2)+1;
	DNODE a = list->head;
	DNODE b = list->tail;	
	for(int i=0; i<limit; i++)
	{
		if(a->data != b->data)
			return 0;
		a = a->next;
		b = b->prev;
	}
	return 1;
}
int main()
{

}