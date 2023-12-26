#include <stdio.h>
#include <stdlib.h>

typedef struct _cnode
{
	char data;
	struct _cnode *next;
} *CNODE;

int main()
{
	CNODE c = (CNODE)malloc(sizeof(struct _cnode));
	c->data = 'A';
	c->next = (CNODE)malloc(sizeof(struct _cnode));
	c->next->data = 'B';
	c->next->next = (CNODE)malloc(sizeof(struct _cnode));
	c->next->next->data = 'C';
	c->next->next->next = c;

	CNODE temp = (CNODE)malloc(sizeof(struct _cnode));
	temp->data = 'X';
	temp->next = c;
	c->next->next->next = temp;

	temp = c;
	c = c->next;
	c->next->next->next = c;
	free(temp);	

	CNODE p = c;
	do
	{
		printf("%c ", p->data);
		p = p->next;
	} while(p!=c);
}