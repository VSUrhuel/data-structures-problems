#include <stdio.h>
#include <stdlib.h>

typedef struct snode
{
	int data;
	struct snode *link;
} *SNODE;

typedef struct SLL
{
	SNODE head;
} *SINGLYLINKEDLIST;

SINGLYLINKEDLIST createList()
{
	SINGLYLINKEDLIST list = (SINGLYLINKEDLIST)malloc(sizeof(struct SLL));
	list->head = NULL;
	return list;
}

void addFirst(SINGLYLINKEDLIST list, int data)
{
	SNODE temp, p;
	temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = data;
	temp->link = NULL;

	temp->link = list->head;
	list->head = temp;
}

void addLast(SINGLYLINKEDLIST list, int data)
{
	SNODE temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = data;
	temp->link = NULL;
	if(list->head==NULL)
		list->head = temp;
	else
	{
		SNODE p = list->head;
		while(p->link!=NULL)
			p=p->link;
		p->link = temp;
	}
}

/*void addLast(SINGLYLINKEDLIST list, int data)
{
	SNODE temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = data;
	temp->link = NULL;
	SNODE p = list->head;
	while(p!=NULL)
		p = p->link;
	p->link = temp;
}*/
void deleteData(SINGLYLINKEDLIST list, int data)
{
	SNODE p = list->head, prev = NULL;
	while(p->data != data)
	{
		prev = p;
		p = p->link;
	}
	if(p!=NULL)
	{
		if(prev!=NULL)
			prev->link = p->link;
		else
			list->head = p->link;
	}
	free(p);
}

void replaceXwithY(SINGLYLINKEDLIST list, int x, int y)
{
	SNODE p = list->head;
	while(p!=NULL)
	{
		if(p->data == x)
		{
			printf("l");
			p->data = y;
		}
		p = p->link;
	}
}

SINGLYLINKEDLIST createSLLOnes(int n)
{
	SINGLYLINKEDLIST s = (SINGLYLINKEDLIST)malloc(sizeof(struct SLL));
	s->head = NULL;
	for(int i=0; i<n; i++)
	{
		SNODE p = (SNODE)malloc(sizeof(struct snode));
		p->data = 1;
		//p->link = NULL;
		p->link = s->head;
		s->head = p;
	}
	return s;
}


void flipFrontEnd(SINGLYLINKEDLIST list)
{
	SNODE p = list->head;
	int f = p->data;
	while(p->link!=NULL)
		p = p->link;
	int e = p->data;
	p->data = f;
	list->head->data = e;
}

int checkPairs(SINGLYLINKEDLIST list)
{
	SNODE p = list->head;
	while(p!=NULL)
	{
		int x = p->data, flag = 0;
		SNODE q = p;
		while(q->link!=NULL)
		{
			if(x == q->link->data)
			{
				flag = 1;
				break;
			}
			q=q->link;
		}
		if(!flag)
		{
			return 0;
		}
		p=p->link;
	}
	return 1;
}

int addBeforeX(SINGLYLINKEDLIST list, int x, int data)
{
	SNODE temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = data;
	temp->link = NULL;

	SNODE p = list->head;
	while(p!=NULL)
	{
		if(p->link->data==x && p==list->head)
		{
			temp->link=list->head;
			list->head = temp;
			return 1;
		}
		else if(p->link->data==x)
		{
			temp->link = p->link;
			p = temp;
			return 1;
		}
		p = p->link;
	}
	return 0;
}

void removeConsecutiveEqualElements(SINGLYLINKEDLIST list)
{
	SNODE p = list->head;
	while(p!=NULL)
	{
		int x = p->data;
		SNODE q = p;
		while(q->link!=NULL)
		{
			if(x==q->link->data)
			{
				SNODE temp = q->link;
				q->link = temp->link;
				free(temp);
			}
			else
				break;
			q = q->link;
		}
		p = p->link;
	}
}

/*void reverseDLL(DLL list)
{
	DNODE d = list->head;
	while(d!=NULL)
	{
		DNODE temp = d->prev;
		d->prev = d->link;
		d->link = temp;

		d = d->link;
	}
	d = list->head;
	list->head = list->tail;
	list->tail = d;
}
*/
int main()
{
	SINGLYLINKEDLIST list = createList();
	// Adding elements to the list
    addLast(list, 7);
    addLast(list, 2);
    addLast(list, 3);
    addLast(list, 1);
    addFirst(list, 2);
    addFirst(list, 3);
    
 

    // Display the initial list
    printf("List: ");
    SNODE p = list->head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");

    //printf("checkPairs: %d\n", checkPairs(list));
   	flipFrontEnd(list);
   	printf("List: ");
    p = list->head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
   	removeConsecutiveEqualElements(list);
   	printf("List: ");
    p = list->head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
    /*
    /*Delete a node from the list
    char dataToDelete = 'B';
    deleteData(list, dataToDelete);
    printf("After deleting %c: ", dataToDelete);
    p = list->head;
    while (p != NULL) {
        printf("%c -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");*/

    // Free the allocated memory for the list
    while (list->head != NULL) {
        SNODE temp = list->head;
        list->head = list->head->link;
        free(temp);
    }
    free(list);
}

/*void deleteLastEven(DLL list)
{
	DNODE d = list->tail;
	while(d!=list->head)
	{
		if(d->data%2==0 && d == list->tail)
		{
			DNODE temp = d;
			list->tail = d->prev;
			list->tail->next = NULL;
			free(temp);
			list->size--;
		}
		else if(d->data%2==0 && d == list->head)
		{
			DNODE temp = d;
			list->head = list->head->next;
			list->head->prev = NULL;
			free(temp);
			list->size--;
		}
		else if(d->data%2==0)
		{
			DNODE temp = d;
			d->prev->next = d->next;
			d->next->prev = d->prev;
			free(temp);
			list->size--;
		}
		d = d->prev;
	}
}

int checkConsecutiveThree(CLL list)
{
	CNODE c = list->head;
	while(c->next!=list->head)
	{
		if(c->next->data == c->next->next->data && c->next->next->next->data == c->next->data)
			return 1;
		c = c->next;
	}
	return 0;
}*/