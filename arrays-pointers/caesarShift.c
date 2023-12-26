	#include <stdio.h>
	#include <ctype.h>

	char encrypt(int n, int key);
	char decrypt(int n, int key);

	int main()
	{
		int n;
		printf("Number of Characters: ");
		scanf("%d", &n);
		int key;
		printf("Enter shift key: ");
		scanf("%d", &key);

		int arr[n];
		for(int i=0; i<n; i++)
		{
			char c;
			scanf(" %c", &c);
			c = toupper(c);
			arr[i] = c-'A';
		}

		char option;
		printf("[E]Encrypty [D]Decrypt: ");
		scanf(" %c", &option);
		switch(toupper(option))
		{
			case 'E':
			{
				printf("Encrypted Text: \n");
				for(int i=0; i<n; i++)
					printf("%c ",encrypt(arr[i], key));
				printf("\n");
				break;
			}
			case 'D':
			{
				printf("Decrypted Text: \n");
				for(int i=0; i<n; i++)
					printf("%c ", decrypt(arr[i], key));
				printf("\n");
				break;
			}
			default:
			{
				printf("Invalid Input");
			}
		}

	}

	char encrypt(int n, int key)
	{
		int pos = (n + key) % 26;
		return (pos + 'A');
	}

	char decrypt(int n, int key)
	{
		int pos = (n - key) % 26;
		pos = (pos < 0) ? pos + 26 : pos;
		return (pos + 'A');
	}