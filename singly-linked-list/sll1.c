#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct snode
{
	char data;
	struct snode *link;
} *SNODE; 

SNODE addBeginning(SNODE head, char data)
{
	SNODE temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = data;
	temp->link = head;
	head = temp;
	return head;
}

void addBeginninga(SNODE *head, int data)
{
	SNODE temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = data;
	temp->link = *head;
	*head = temp;
}

void deleteData(SNODE head, char data)
{
	SNODE temp, ptr = head;
	while(ptr->data!=data)
		ptr = ptr->link;
	temp = ptr->link;

	ptr->link = temp->link;
	free(temp);
	//free(ptr->link);
}
SNODE deleteFirst(SNODE head)
{
	if(head == NULL)
		printf("Linked List is Empty.\n");
	else
	{
		SNODE temp = head;
		head = head->link;
		free(temp);
		temp = NULL;
	}
	return head;
}
void addEnd(SNODE head, int data)
{
	SNODE ptr, temp;
	ptr = head;
	temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = data;
	temp->link = NULL;

	while(ptr->link != NULL)
		ptr = ptr->link;
	ptr->link = temp;
}

void insertPos(SNODE head, int data, int pos)
{
	if(head == NULL)
	{
		addBeginning(head, data);
		return;
	}
	SNODE ptr, temp;
	temp = (SNODE)malloc(sizeof(struct snode));
	temp->data = data;

	ptr = head;
	int ctr = 1;
	while(ctr<pos-1)
	{
		ptr = ptr->link;
		ctr++;
	}
	temp->link = ptr->link;
	ptr->link = temp;

}
void print(SNODE head)
{
	if(head == NULL)
	{
		printf("Linked List is Empty");
		return;
	}
	SNODE temp = head;
	while(temp!=NULL)
	{
		printf("%c ", temp->data);
		temp = temp->link;
	}
}

int main()
{
	//Manually Creating a SLL

	/*SNODE head = (SNODE)malloc(sizeof(struct snode));
	head->data = 3;
	head->link = (SNODE)malloc(sizeof(struct snode));
	head->link->data = 4;
	head->link->link = (SNODE)malloc(sizeof(struct snode));
	head->link->link->data = 23;
	head->link->link->link = NULL;*/
	
	//Creating a dynamic SLL
	/*int n;
	scanf("%d", &n);
	SNODE head = NULL;

	for(int i=0; i<n; i++)
	{
		SNODE p = (SNODE)malloc(sizeof(struct snode));
		p->data = i+1;
		p->link = head;
		head = p;
	}
	addEnd(head, 78);
	addEnd(head, 32);
	head = addBeginning(head, 8);*/
	//SNODE head = NULL;
	/*head = addBeginning(head, 3);
	head = addBeginning(head, 2);
	addEnd(head, 34);
	addEnd(head, 13);
	//addBeginninga(&head, 21);*/
	/*for(int i=0; i<4; i++)
		insertPos(head, i+1, i);*/
	//deleteData(head, 4);
	SNODE head = NULL;
	for(int i=0; i<6; i++)
	{
		SNODE p = (SNODE)malloc(sizeof(struct snode));
		p->data = 'A'+i;
		p->link = head;
		head = p;
	}
	head = addBeginning(head, 'X');
	addEnd(head, 'Z');
	insertPos(head, 'Y', 4);
	deleteData(head, 'F');
	head = deleteFirst(head);
	print(head);
	
	
	return 0;
}
