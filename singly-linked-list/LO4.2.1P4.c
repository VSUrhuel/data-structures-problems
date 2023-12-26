#include <stdio.h>
#include <stdlib.h>

typedef struct _cnode
{
	char data;
	struct _cnode *next;
} *CNODE;

typedef struct _circularlinkedlist
{
	CNODE tail;
} *CIRCULARLINKEDLIST;

CIRCULARLINKEDLIST createCList()
{
	CIRCULARLINKEDLIST c = (CIRCULARLINKEDLIST)malloc(sizeof(struct _circularlinkedlist));
	c->tail = NULL;
	return c;
}

int checkConsecutiveThree(CIRCULARLINKEDLIST list)
{
	CNODE c = list->tail;
	while(c->next!=list->tail)
	{
		if(c->next->data == c->next->next->data && c->next->next->next->data == c->next->data)
			return 1;
		c = c->next;
	}
	return 0;
}

void removeDuplicates(CIRCULARLINKEDLIST list)
{
	CNODE c = list->tail;
	while(c->next!=list->tail)
	{
		int x = c->next->data;
		CNODE q = c;
		q = q->next;
		while(q->next!=list->tail)
		{
			if(x==q->next->data)
			{
				CNODE temp = q->next;
				q->next = temp->next;
				free(temp);
			}
			q = q->next;
		}
		c = c->next;
	}
}

CIRCULARLINKEDLIST mergeList(CIRCULARLINKEDLIST list1, CIRCULARLINKEDLIST list2)
{
	CIRCULARLINKEDLIST list = (CIRCULARLINKEDLIST)malloc(sizeof(struct _circularlinkedlist));
	list->tail = NULL;
	list->size = 0;
	CNODE p = list1->tail;
	for(int i=0; i<list1->size; i++)
	{
		addLast(list, p->data);
		CNODE temp = p;
		p = p->next;
		free(temp);
	}
	p = list2->tail;
	for(int i=0; i<list2->size; i++)
	{
		addLast(list, p->data);
		CNODE temp = p;
		p = p->next;
		free(temp);
	}
	list1->size = list2->size = 0;
	return list;
}
void addFirst(CIRCULARLINKEDLIST list, char data)
{
	CNODE p = (CNODE)malloc(sizeof(struct _cnode));
	p->data = data;
	p->next = NULL;
	if(list->tail == NULL)
	{
		list->tail = p;
		p->next = p;
	}
	else
	{
		p->next = list->tail->next;
		list->tail->next = p;
	}
	list->size++;
}
void addLast(CIRCULARLINKEDLIST list, char data)
{
	CNODE p = (CNODE)malloc(sizeof(struct _cnode));
	p->data = data;
	p->next = NULL;
	if(list->tail == NULL)
	{
		p->next = p;
		list->tail = p;
	}
	else
	{
		p->next = list->tail->next;
		list->tail->next = p;
		list->tail = p;
	}
	list->size++;
}

int main() {
    CIRCULARLINKEDLIST list = createCList();

    // Add elements to the circular linked list
    addFirst(list, 'A');
    addLast(list, 'A');
    addLast(list, 'C');
    addLast(list, 'B');
    addFirst(list, 'Z');



    // Display the circular linked list
    printf("Circular Linked List: ");
    CNODE current = list->tail;
    do
    {
    	printf("%c -> ", current->data);
        	current = current->next;
    }while(current != list->tail);
    
    printf("NULL\n");

    removeDuplicates(list);
    printf("Circular Linked List: ");
    current = list->tail;
    do
    {
    	printf("%c -> ", current->data);
        	current = current->next;
    }while(current != list->tail);
    
    printf("NULL\n");
    // Clean up and free memory (optional)
    current = list->tail;
    if (current != NULL) {
        CNODE firstNode = current->next;
        while (current != firstNode) {
            CNODE temp = current;
            current = current->next;
            free(temp);
        }
        free(current);
    }

    free(list);

    return 0;
}
