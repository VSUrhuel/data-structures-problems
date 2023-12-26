#include <stdio.h>
#include <stdlib.h>

typedef struct _snode
{
	int data;
	struct _snode* next;
} *SNODE;

typedef struct _singularlinkedlist
{
	SNODE head;
	int size;
} *SINGULARLINKEDLIST;

SINGULARLINKEDLIST createSLL()
{
	SINGULARLINKEDLIST s = (SINGULARLINKEDLIST)malloc(sizeof(struct _singularlinkedlist));
	s->head = NULL;
	s->size = 0;
	return s;
}

SINGULARLINKEDLIST createSLLOnes(int n)
{
	SINGULARLINKEDLIST s = (SINGULARLINKEDLIST)malloc(sizeof(struct _singularlinkedlist));
	s->head = NULL;
	s->size = 0;
	for(int i=0; i<n; i++)
	{
		SNODE temp = (SNODE)malloc(sizeof(struct _snode));
		temp->data = 1;
		if(s->head == NULL)
		{
			temp->next = NULL;
			s->head = temp;
		}
		else
		{
			temp->next = s->head;
			s->head = temp;
		}
	}
	return s;
}

void addFirst(SINGULARLINKEDLIST list, int data)
{
	SNODE s = (SNODE)malloc(sizeof(struct _snode));
	s->data = data;
	s->next = NULL;

	if(list->head == NULL)
	{
		list->head = s;
		list->size++;
	}
	else
	{
		s->next = list->head;
		list->head = s;
		list->size++;
	}

}

void replaceXWithY(SINGULARLINKEDLIST list, int x, int y)
{
	SNODE p = list->head;
	while(p!=NULL)
	{
		if(p->data == x)
			p->data = y;
		p = p->next;
	}
}

void addBetweenXandY(SINGULARLINKEDLIST list, int x, int y, int data)
{
	SNODE p =list->head;
	while(p!=NULL)
	{
		if(p->data == x && p->next->data==y)
		{
			SNODE temp = (SNODE)malloc(sizeof(struct _snode));
			temp->data = data;
			temp->next = p->next;
			p->next = temp;
			list->size++;
		}
		p = p->next;
	}
}
SINGULARLINKEDLIST createSLLZeroes(int n)
{
	SINGULARLINKEDLIST s = (SINGULARLINKEDLIST)malloc(sizeof(struct _singularlinkedlist));
	s->head = NULL;
	s->size = 0;
	for(int i=0; i<n; i++)
	{
		SNODE temp = (SNODE)malloc(sizeof(struct _snode));
		temp->data = 0;
		if(s->head == NULL)
		{
			temp->next = NULL;
			s->head = temp;
		}
		else
		{
			temp->next = s->head;
			s->head = temp;
		}
	}
	return s;
}
void flipFrontEnd(SINGULARLINKEDLIST list)
{
	SNODE p = list->head;
	int f = p->data;
	while(p->next!=NULL)
		p = p->next;
	int e = p->data;
	p->data = f;
	list->head->data = e;
	/*SNODE p = list->head;
	int data = p->data;
	while(p->next!=NULL)
		p = p->next;
	int y = p->data;
	p->data = data;
	list->head->data = y;*/
}
void addLast(SINGULARLINKEDLIST list, int data)
{
	SNODE temp = (SNODE)malloc(sizeof(struct _snode));
	temp->data = data;
	temp->next = NULL;
	if(list->head == NULL)
		list->head = temp;
	else
	{
		SNODE p = list->head;
		while(p!=NULL)
			p = p->next;
		p->next = temp;
		temp->next = NULL;
	}
}
void deleteData(SINGULARLINKEDLIST list, int data)
{
	SNODE p = list->head, prev = NULL;
	while(p->data!=data)
	{
		prev = p;
		p = p->next;
	}
	if(p!=NULL)
	{
		if(prev!=NULL)
			prev->next = p->next;
		else
			list->head = p->next;
	}
	free(p);
}
void insertPos(SINGULARLINKEDLIST list, int pos, int data)
{
	SNODE p = list->head;
	while(pos-1>1)
	{
		pos--;
		p=p->next;
	}
	SNODE temp = (SNODE)malloc(sizeof(struct _snode));
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
}
int main()
{
	SINGULARLINKEDLIST list = createSLLOnes(10);
	// Display the initial list
    printf("List: ");
    SNODE p = list->head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    list = createSLL();
    addFirst(list, 3);
    addFirst(list, 2);
    addFirst(list, 1);
    addFirst(list, 89);
    addFirst(list, 21);
    deleteData(list, 1);
    addLast(list, 6);
    insertPos(list, 3, 76);

    replaceXWithY(list, 3, 12);
    addBetweenXandY(list, 21, 89, 7);

    //flipFrontEnd(list);
    printf("List: ");
    p = list->head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    list = createSLLZeroes(10);
	// Display the initial list
    printf("List: ");
    p = list->head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}