#include <stdio.h>
#include <math.h>

long int convertToBinary(int n);
int countDigit(long int n);

int main()
{
	long int b, p, exp;
	printf("Enter expression (base expondent m): ");
	scanf("%ld", &exp);

	long int binary = convertToBinary(exp);
	printf("%ld\n", binary);
	/*int length = countDigit(binary);

	int x = 1, power = b  % p;

	for(int i=0; i<length; i++)
	{
		int digit = binary % 10;
		if(digit == 1)
		{
			x = x * power % b;
			power = (power * power) % b;
		}
		else
			power = (power * power) %b;
		binary /= 10;
	}

	printf("x = %d\n", x);
	return 0;*/
}

long int convertToBinary(int n)
{
	int temp = n, digit = 0;
	long int binary = 0;
	int f = 1;
	int exp = log(temp)/log(2);
	int ctr = exp;
	for(exp; exp>0;)
	{
		exp = log(temp)/log(2);
		if(exp != ctr&&exp>ctr)
		{
			printf("f:%d\n", f);
			int difference =  exp-ctr;
			printf("difference:%d\n", difference);
			for(int i=0; i<difference; i++)
				f=(f*10);
			printf("f:%d\n", f);
		}
			binary += 1 * f;
			printf("%d\n",binary);
			f=f*10;
		temp = temp - (pow(2, exp)); 
		ctr--;
	}
	return binary;
}

int countDigit(long int n)
{
	int ctr; 
	for(n; n>0; n/=10)
		ctr++;

	return ctr;
}