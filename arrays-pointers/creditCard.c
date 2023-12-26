#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int checkCard(char n[]);
int checkValid(long long n);
int countDigit(long long n);

int main()
{
	char num[16];
	do
	{
		printf("Credit Card Number: ");
		scanf("%s", &num);
	} while(!checkCard(num));

	long long n = strtoll(num, NULL, 10);

	if(checkValid(n))
	{
		int count = countDigit(n)-2;
		int twoDigit = n / pow(10, count);
		int oneDigit = n / pow(10, count+1);
		if(twoDigit == 34 || twoDigit == 37)
			printf("AMEX\n");
		else if(twoDigit == 51 || twoDigit == 52 || twoDigit == 53 || twoDigit == 54 || twoDigit == 55 || twoDigit == 22)
			printf("MASTERCARD\n");
		else if(oneDigit == 4)
			printf("VISA\n");
		else if(twoDigit == 35)
			printf("JCB\n");
		else if(twoDigit == 60)
			printf("DISCOVER\n");
		else if(twoDigit == 30)
			printf("DINERS CLUB\n");
		else
			printf("INVALID\n");
	}
	else
		printf("INVALID");

	return 0;
}

int checkCard(char n[])
{
	int flag = 1;
	for(int i=0; i<strlen(n); i++)
	{
		if(!isdigit(n[i]))
		{
			flag = 0;
			break;
		}
	}

	long long number;
	if(flag)
	{
		number = strtoll(n, NULL, 10);
		if(countDigit(number) == 15 || countDigit(number) == 16)
			return 1;
		else
			return 0;
	}
	else
		return 0;
	
}

int checkValid(long long n)
{
	int sum1 = 0, sum2 = 0, ctr = 1;
	while(n > 0)
	{
		int digit = n % 10;
		if(ctr % 2 == 0)
		{
			int prod = digit * 2;
			while(prod > 0)
			{
				sum1 += prod % 10;
				prod/=10;
			}
		}
		else
		{
			sum2 += digit;
		}
		n/=10;
		ctr++;
	}
	int sum = sum1 + sum2;
	if(sum % 10 == 0)
		return 1;
	else
		return 0;
}

int countDigit(long long n)
{
	int ctr = 0;
	while(n > 0)
	{
		ctr++;
		n /= 10;
	}
	return ctr;
}