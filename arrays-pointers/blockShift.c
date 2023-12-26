#include <stdio.h>

int 
int main()
{
	int n;
	int n;
	printf("Number of Characters: ");
	scanf("%d", &n);

	int arr[n];
	for(int i=0; i<n; i++)
	{
		char c;
		scanf(" %c", &c);
		arr[i] = c-'A';
	}

	int block;
	printf("By blocks of: ");
	scanf("%d", &block);

	int blockKey[block];
	for(int i=0; i<n; i++)
	{
		int x;
		printf("O(%d) = ", i);
		scanf("%d", &x);
		blockKey[i] = x-1;
	}

	char option;
	printf("[E]Encrypty [D]Decrypt: ");
	scanf(" %c", &option);
	switch(toupper(option))
	{
		case 'D':
		{
			printf("Decrypted Text: \n");
			for(int i=0; i<n; i++)
			{
				
				printf("%c ", decrypt(arr[i]));
			}
			printf("\n");
			break;
		}
	}
}