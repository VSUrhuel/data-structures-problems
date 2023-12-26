#include <stdio.h>

int isPrime(int n)
{
	if(n==2)
		return 1;
	for(int i=2; i<sqrt(n)+1; i++)
		if(n%i==0)
			return 0;
	return 1;
}

int main()
{
	int n, temp, ans[1000000], index = 0, ctr = 0;
	scanf("%d", &n);
	temp = n;
	for(int i=2; i<temp; i++)
	{
		while(n>0)
		{
			if(isPrime(i))
			{
				n-=i;
				ans[index++] = i;
				ctr++;
			}
			else
				break;
		}
	}
	for(int i=0; i<index; i++)
		printf("%d ", ans[i]);
}