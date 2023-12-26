#include <stdio.h>
#include <math.h>

int main()
{
	double n;
	do
	{
		printf("Enter a cents: ");
		scanf("%lf", &n);
	} while (n <= 0);

	int num = round(n*100);

	int changedOwed = num, ctr25 = 0, ctr10 = 0, ctr5 = 0, ctr1 = 0;
	while(changedOwed > 0)
	{
		if(changedOwed / 25 > 0)
		{
			ctr25++;
			changedOwed -= 25;
		}
		else if(changedOwed  / 10 > 0)
		{
			ctr10++;
			changedOwed -= 10;
		}
		else if(changedOwed / 5 > 0)
		{
			ctr5++;
			changedOwed -= 5;
		}
		else
		{
			ctr1++;
			changedOwed -= 1;
		}
	}
	printf("25 Cents: %d\n", ctr25);
	printf("10 Cents: %d\n", ctr10);
	printf("5 Cents: %d\n", ctr5);
	printf("1 Cent: %d\n", ctr1);
	printf("Sum = %d\n", ctr25*25 + ctr10*10 + ctr5*5 + ctr1*1);
	printf("Coins: %d", (ctr25 + ctr10 + ctr5 + ctr1));
}