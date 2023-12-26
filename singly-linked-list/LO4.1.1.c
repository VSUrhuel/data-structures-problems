#include <stdio.h>
#include <stdlib.h>

typedef struct snode
{
	char data;
	struct snode *link;
} *SNODE;

int main()
{
	
	SNODE head = (SNODE)malloc(sizeof(struct snode));
	head->data = 'A';
	head->link = (SNODE)malloc(sizeof(struct snode));
	head->link->data = 'B';
	head->link->link = (SNODE)malloc(sizeof(struct snode));
	head->link->link->data = 'C';
	head->link->link->link = NULL;

	SNODE temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = 'X';
	temp->link = NULL;

	temp->link = head->link->link;
	head->link->link = temp;

	temp = head;
	head = head->link;
	free(temp);

	SNODE p = head;
	while(p!=NULL)
	{
		printf("%c ", p->data);
		p = p->link;
	}
	return 0;
}