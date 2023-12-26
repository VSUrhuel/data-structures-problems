#include "stack.h"
#include <ctype.h>
#include <string.h>

void expVal()
{
	char exp[100];
	scanf("%s", exp);
	int l = strlen(exp);
	double ans = 0;
	STACKARR stack = STACKARR_create(100);
	for(int i=0; i<l; i++)
	{
		if(isdigit(exp[i]))
			STACKARR_push(stack, exp[i]-'0');
		else
		{
			int x = STACKARR_pop(stack);
			int y = STACKARR_pop(stack);
			switch(exp[i])
			{
			case '+':
				ans = y+x; break;
			case '-':
				ans = y-x; break;
			case '/':
				ans = y/x; break;
			case '*':
				ans = y*x; break;
			case '%':
				ans = y%x; break;
			default:
				return;
			}
			STACKARR_push(stack, ans);
		}
	}
	printf("Answer: %.2lf\n", ans);
}	

void revString()
{
	char exp[100];
	scanf("%s", exp);
	int l = strlen(exp);
	STACKARR stack = STACKARR_create(100);

	for(int i=0; i<l; i++)
		STACKARR_push(stack, exp[i]-'0');
	for(int i=0; i<l; i++)
		printf("%d", STACKARR_pop(stack));
}

void convertDecToBinary()
{
	int x;
	scanf("%d", &x);
	STACKARR stack = STACKARR_create(100);
	while(x > 0)
	{
		STACKARR_push(stack, x%2);
		x/=2;
	}
	while(!STACKARR_isEmpty(stack))
		printf("%d", STACKARR_pop(stack));
}

void placedContent(STACKARR stack)
{
	STACKARR_push(stack, 34);
	STACKARR_push(stack, 34);
	STACKARR_push(stack, 31);
	STACKARR_push(stack, 31);
	STACKARR_push(stack, 23);
	STACKARR_push(stack, 23);
}

/*void sortStack()
{
	
}
	//removalAdjacent();
	//nearestSmallElement();
	//minNumPar("(((");*/

int isPair(char data1, char data2)
{
	return ((data1 == '(' && data2 == ')') || (data1 == '[' && data2 == ']') || (data1 == '{' && data2 == '}'));
}

int checkBal()
{
	STACKARR stack = STACKARR_create(100);
	char exp[100];
	scanf("%s", exp);
	int l = strlen(exp);
	for(int i=0; i<l; i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			STACKARR_push(stack, exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
			if(!isPair(STACKARR_pop(stack), exp[i]))
				return 0;
	}
	return 1;
}

void sortStack()
{
	STACKARR stack = STACKARR_create(100);
	STACKARR temp = STACKARR_create(100);
	placedContent(stack);
	while(!STACKARR_isEmpty(stack))
	{
		int x = STACKARR_pop(stack);
		while(!STACKARR_isEmpty(temp) && x < STACKARR_peek(temp))
		{
			STACKARR_push(stack, STACKARR_pop(temp));
		}
		if(x>STACKARR_peek(temp))
			STACKARR_push(temp, x);
	}
	STACKARR_display(temp);
}

void removalAdjacent()
{
	STACKARR stack = STACKARR_create(100);
	STACKARR temp = STACKARR_create(100);
	placedContent(stack);
	for(int i=0; i<6 || !STACKARR_isEmpty(stack); i++)
	{
		int x = STACKARR_pop(stack);
		if(x == STACKARR_peek(stack))
			STACKARR_pop(stack);
		else
			STACKARR_push(temp, x);
	}
	STACKARR_display(temp);
}

void nearestSmallElement()
{
	STACKARR stack = STACKARR_create(100);
	STACKARR temp = STACKARR_create(100);
	placedContent(stack);
	while(!STACKARR_isEmpty(stack))
	{
			while(!STACKARR_isEmpty(temp) && STACKARR_peek(temp) >= STACKARR_peek(stack))
				STACKARR_pop(temp);
			if(!STACKARR_isEmpty(temp))
				printf("_,");
			else
				printf("%d,", STACKARR_peek(temp));
			STACKARR_push(temp, STACKARR_peek(stack));
			STACKARR_pop(stack);
	}
}
void minNumPar(char *exp)
{
	int l = strlen(exp);
	STACKARR stack = STACKARR_create(100);
	for(int i=0; i<l; i++)
	{
		if(exp[i] == '(')
			STACKARR_push(stack, exp[i]);
		else
			if(isPair(STACKARR_peek(stack), exp[i]))
				STACKARR_pop(stack);
	}
	int ctr = 0;
	while(!STACKARR_isEmpty(stack))
	{
		STACKARR_pop(stack);
		ctr++;
	}
	printf("%d", ctr);
}
int main()
{
	expVal();	
	//revString();
	//convertDecToBinary();
	//sortStack();
	//removalAdjacent();
	//nearestSmallElement();
	//minNumPar("((()");
	//printf("%d\n",checkBal());
}

/*if pos == 0 && cll->size == 0 //insert at the beginning in an empty list
else if pos == 0 //insert at the beginning
else if pos == cll->size //insert at the last
else //insert in the middle
*/
