#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
	char data;
	struct dnode *next;
	struct dnode *prev;
} *DNODE;

int main()
{
	DNODE head = (DNODE)malloc(sizeof(struct dnode));

	head->prev = NULL;
	head->data = 'A';
	head->next = (DNODE)malloc(sizeof(struct dnode));

	head->prev = head;
	head->next->data = 'B';
	head->next->next = (DNODE)malloc(sizeof(struct dnode));

	head->prev = head->next;
	head->next->next->data = 'C';
	head->next->next->next = NULL;

	DNODE temp = (DNODE)malloc(sizeof(struct dnode));
	temp->data = 'X';

	temp->next = head->next->next;
	temp->prev = head->next;
	head->next->next = temp;
	head->next->next->next->prev = temp;

	temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);

	DNODE p = head;
	while(p!=NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
}