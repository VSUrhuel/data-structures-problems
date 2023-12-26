#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double computeMedian(int *arr, int n);
int main()
{
	int arr[] = {9, 5, 1, 11, 4};
	int size = sizeof(arr)/sizeof(int);
	double median = computeMedian(arr, size);
	printf("%.2f\n", median);
}
double computeMedian(int *arr, int n)
{
	//sort
	int min = 10000;
	int index = 0;
	for(int i=0; i<n; i++)
	{
		min = 10000;
		for(int j=i; j<n; j++)
		{
			if(min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	if(n % 2 == 0)
		return (arr[n/2] + arr[(n/2)-1] / 2.0f);
	else
		return arr[n/2];
 }
/*int *findEven(int *arr, int n);
int countsEven(int *arr, int n);
int main()
{
	int arr[] = {90, 12, 1, 4, 6, 9};

	int size = countsEven(arr, 6);
	int *newArr = (int*)malloc(sizeof(int)*size);
	newArr = findEven(arr, 6);
	for(int i=0; i<size; i++)
		printf("%d ", newArr[i]);
}
int countsEven(int *arr, int n)
{
	int ctr = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]%2==0)
			ctr++;
	}
	return ctr;
}
int *findEven(int *arr, int n)
{
	int size = countsEven(arr, n);
	int *arr2 = (int*)malloc(sizeof(int)*size);
	int index = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i] % 2 == 0)
		{
			arr2[index] = arr[i];
			index++;
		}
	}
	return arr2;
}*/
/*Lesson 2.2.1 - 2.2.1
	int **arr = (int**)malloc(sizeof(int*)*5);
	for(int i=0; i<5; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*(i+1));
		for(int j=0; j<=i; j++)
			arr[i][j] = j;
	}

	int *temp = arr[1];
	arr[1] = arr[4];
	arr[4] = temp;

	for(int i=0; i<5; i++)
	{
		printf("[%d] ", i);
		if(i==1)
		{
			for(int j=0; j<=4; j++)
				printf("%d ", arr[i][j]);
		}
		else if(i==4)
		{
			for(int j=0; j<=1; j++)
				printf("%d ", arr[i][j]);
		}
		else
			for(int j=0; j<=i; j++)
				printf("%d ", arr[i][j]);
		printf("\n");
	}*/
/*Lesson 2.2.1 - 2.2.2
	int n;
	scanf("%d", &n);
	int *nums = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		scanf("%d", &nums[i]);
	for(int i=0; i<n; i++)
	{
		if(nums[i]%3==0)
			printf("%d ", nums[i]);
	}*/

/*Lesson 2.2.1 - 2.2.2
	int n;
	scanf("%d", &n);

	int *nums = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		scanf("%d", &nums[i]);
	for(int i=0; i<n; i++)
		printf("%d", nums[i]);*/
/*Lesson 2.1.1 - 2.1.2
	int arr[] = {10, 6, 3, 8, 5, 1, 2};
	int cumultative[7];
	cumultative[0] = arr[0];

	for(int i=1; i<7; i++)
	{
		cumultative[i] = arr[i] + cumultative[i-1];
	}
	for(int i=0; i<7; i++)
		printf("%d ", cumultative[i]);*/

/*Lesson 2.1.1 - 2.1.2
	double nums[10] = {0};
	srand(time(NULL));
	double ave = 0;
	for(int i=0; i<10; i++)
	{
		nums[i] = rand() % 11;
	}
	for(int i=0; i<10; i++)
	{
		printf("%.2f ", nums[i]);
		ave += nums[i];
	}
	ave = ave/10.0f;
	printf("\n");
	printf("Average: %.2f\n", ave);
	for(int i=0; i<10; i++)
	{
		if(nums[i] > ave)
			printf("%.2f ", nums[i]);
	}*/
/*Coding C
	int num1, num2, num3, num4, num5;
	int *nums = (int*)malloc(sizeof(int)*5);

	srand(time(NULL));
	for(int i=0; i<5; i++)
		nums[i] = rand() % 10;

	nums[0] = (nums[0] + nums[1] + nums[2] + nums[3] + nums[4])/5.0f;

	int *ptr = nums;

	printf("%d\n", *ptr);*/
/*Coding B
	int a = 21;
	int *p, **n;
	p = &a;
	n = &p;
	char b = 'x';
	char *q;
	q = &b;
	double c = 1.21;
	double *r;
	r = &c;

	void *m, *o;
	o = &n;
	m = &o;
	printf("%d\n", ****((int****)m));
	o = &q;
	printf("%c\n", ***((char***)m));
	m = &r;
	printf("%.2f\n", **((double**)m));
	
	o = &n;
	printf("%d\n", ***((int***)o));
	o = &q;
	printf("%d\n", **((char**)o));

	printf("%.2f\n", *r);
	printf("%d\n", **n);
	printf("%d\n", *p);
	printf("%c\n", *q);
*/
/*Coding A
	int *num1 = (int*)malloc(sizeof(int));
	int *num2 = (int*)malloc(sizeof(int));
	int *num3 = (int*)malloc(sizeof(int));

	*num1 = 1;
	*num2 = 12;
	*num3 = 67;

	scanf("%d", num1);

	*num2 += *num3;

	free(num3);
	num3 = NULL;

	char *num4 = (char*)malloc(sizeof(char));
	*num4 = 'h';

	void *num_ref;
	num_ref = num1;
	printf("%d\n", *((int*)num_ref));
	num_ref = num2;
	printf("%d\n", *((int*)num_ref));
	num_ref = num4;
	printf("%c\n", *((char*)num_ref));	*/

/*Lesson 1.2.3
	int *data1 = (int*)malloc(sizeof(int));
	int *data2 = (int*)malloc(sizeof(int));
	int *data3 = (int*)malloc(sizeof(int));

	*data1 = 3;
	*data2 = 5;
	*data3 = 11;

	float *ave = (float*)malloc(sizeof(float));
	*ave = (*data1 + *data2 + *data3)/3.0f;

	printf("%.2f\n", *ave);*/

/*Lesson 1.2.2
	int *a = (int*)malloc(sizeof(int));
	char *b = (char*)malloc(sizeof(char));
	double *c = (double*)malloc(sizeof(double));

	printf("%d\n", sizeof(*a));
	printf("%d\n", sizeof(*b));
	printf("%d\n", sizeof(*c));*/

/*Lesson 1.2.1
	char data1 = 'X';
	int data2 = 100;
	float data3 = 3.14f;
	
	void *data; 
	data = &data1;
	printf("%c\n", *((char*)data));
	data = &data2;
	printf("%d\n", *((int*)data));
	data = &data3;
	printf("%.2f\n", *((float*)data));*/

/*Lesson 1.1.1 -  1.1.4
	int x = 10;
	int *p = &x;
	*p = 15;

	float *pi = (float*)malloc(sizeof(float));
	*pi = 3.14;
	p = pi;

	int **p_ptr = &p;

	printf("%.2f\n", **((float**)p_ptr));*/

/*
	int *p, **q, **r, ***s, ***t, ***u, ***v;
	int a = 9;
	scanf("%d", &a);
	p = &a;
	q = r = &p;
	s = t = &q;
	u = v = &r;

	printf("%d\n", *p);
	printf("%d\n", **q);
	printf("%d\n", **r);
	printf("%d\n", ***s);
	printf("%d\n", ***t);	
	printf("%d\n", ***u);
	printf("%d\n", ***v);*/