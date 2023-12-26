#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _sllnode
{
	Element data;
	struct _sllnode *next;
} *SLLNODE;

typedef struct _sll
{
	SLLNODE head;
	int size;
} *SLL;

SLL createSLL()
{
	SLL s = (SLL)malloc(sizeof(struct _sll));
	s->head = NULL;
	s->size = 0;
	return s;
}

void addFirst(SLL list, Element data)
{
	SLLNODE temp = (SLLNODE)malloc(sizeof(struct _sllnode));
	temp->next = NULL;
	temp->data = data;

	if(list->size == 0)
		list->head = temp;
	else
	{
		temp->next = list->head;
		list->head = temp;
	}
	list->size++;
}

void addLast(SLL list, Element data)
{
	SLLNODE temp = (SLLNODE)malloc(sizeof(struct _sllnode));
	temp->next = NULL;
	temp->data = data;

	if(list->size == 0)
		list->head = temp;
	else
	{
		SLLNODE p = list->head;
		for(int i=0; i<list->size-1; i++)
			p = p->next;
		p->next = temp;
	}
	list->size++;
}

void displayList(SLL list)
{
	SLLNODE p = list->head;
	for(int i=0; i<list->size; i++, p=p->next)
		printf("%d -> ", p->data);
	printf("NULL\n");
}

void replaceXwithY(SLL list, Element x, Element y)
{
	SLLNODE p = list->head;
	for(int i=0; i<list->size-1; i++, p=p->next)
		if(p->data == x)
			p->data = y;
}

void flipFrontEnd(SLL list)
{
	Element front = list->head->data;
	SLLNODE p = list->head;
	for(int i=0; i<list->size-1; i++)
		p = p->next;
	Element last = p->data;
	p->data = front;
	list->head->data = last;
}

void insertAt(SLL list, int pos, Element x)
{
	SLLNODE temp = (SLLNODE)malloc(sizeof(struct _sllnode));
	temp->next = NULL;
	temp->data = x;
	if(pos == 1)
	{
		temp->next = list->head;
		list->head = temp;
	}
	else 
	{
		SLLNODE p = list->head;
		for(int i=0; i<pos-1; i++)
			p=p->next;
		if(pos == list->size)
			p->next = temp;
		else
		{
			temp->next = p->next;
			p->next = temp;
		}
	}
	list->size++;
}

void addElementAfterX(SLL list, Element x, Element data)
{
	SLLNODE s = (SLLNODE)malloc(sizeof(struct _sllnode));
	s->next = NULL;
	s->data = data;
	SLLNODE p = list->head;
	for(int i=0; i<list->size-1; i++, p=p->next)
		if(p->data == x)
			break;
	s->next = p->next;
	p->next = s;
	list->size++;
}

void addElementBeforeX(SLL list, Element x, Element data)
{
	SLLNODE temp = (SLLNODE)malloc(sizeof(struct _sllnode));
	temp->data = data;
	temp->next = NULL;
	if(x == list->head->data)
	{
		temp->next = list->head;
		list->head = temp;
	}
	else
	{
		SLLNODE p = list->head;
		for(int i=0; i<list->size-1; i++, p=p->next)
			if(p->next->data == x)
				break;
		temp->next = p->next;
		p->next = temp;
	}
	list->size++;
}

void addBetweenXAndY(SLL list, Element x, Element y, Element data)
{
	SLLNODE temp = (SLLNODE)malloc(sizeof(struct _sllnode));
	temp->data = data;
	temp->next = NULL;
	SLLNODE p = list->head;
	if(list->head->data == x && list->head->next->data == y)
	{
		temp->next = list->head->next;
		list->head->next = temp;
	}
	for(int i=0; i<list->size-1; i++, p = p->next)
	{
		if(p->next->data == x && p->next->next->data == y)
		{
			temp->next = p->next->next;
			p->next->next = temp;
		}
	}
	list->size++;
}

void sortData(SLL list)
{
	SLLNODE p = list->head;
	for(int i=0; i<list->size-1; i++)
	{
		SLLNODE q = p;
		for(int j=0; j<list->size-i-1; j++, q=q->next)
		{
			if(q->data > q->next->data)
			{
				Element temp = q->data;
				q->data = q->next->data;
				q->next->data = temp;
			}
		}
	}
}

void deleteDuplicate(SLL list)
{
	SLLNODE p = list->head;
	while(p!=NULL)
	{
		Element x = p->data;
		SLLNODE q = p;
		while(q->next!=NULL)
		{
			if((q->next->data) == x)
			{
				SLLNODE temp = q->next;
				q->next = temp->next;
				free(temp);
				list->size--;
			}
			else
				q = q->next;
		}
		p = p->next;
	}
}

void reverseElements(SLL list)
{
	int arr[list->size], ctr = list->size-1;
	SLLNODE p = list->head;
	for(int i=0; i<list->size; i++, p=p->next)
		arr[i] = p->data;
	p = list->head;
	for(int i=0; i<list->size; i++, p=p->next)
		p->data = arr[ctr--];
}

void rotateLeft(SLL list, int n)
{
	SLLNODE p = list->head;
	for(int i=0; i<list->size-1; i++)
		p = p->next;
	p->next = list->head;
	int limit = n%list->size;
	p = list->head;
	for(int i=0; i<limit-1; i++)
		p = p->next;
	list->head = p->next;
	p->next = NULL;
}

int main()
{
	SLL list = createSLL();
	addFirst(list, 6);
	addFirst(list, 9);
	addFirst(list, 7);
	addFirst(list, 7);
	addLast(list, 7);
	addLast(list, 35);
	replaceXwithY(list, 1, 90);
	insertAt(list, 6, 78);
	insertAt(list, 1, 67);
	insertAt(list, 4, 7);
	flipFrontEnd(list);	
	addElementAfterX(list, 90, 52);	
	addElementBeforeX(list, 78, 16);
	addBetweenXAndY(list, 67, 52, 71);
	sortData(list);
	deleteDuplicate(list);
	reverseElements(list);
	rotateLeft(list, 9);

	displayList(list);
}