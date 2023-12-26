#include "stackB.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int evalPostFixExpr(char *exp)
{
	STACKARR s = STACKARR_create(100);
	int l = strlen(exp);
	char* ops = "+-*^/%";
	for(int i=0; i<l; i++)
	{
		if(isdigit(exp[i]))
			STACKARR_push(s, exp[i]-'0');
		else if(strchr(ops, exp[i]))
		{
			int y = STACKARR_pop(s);
			int x = STACKARR_pop(s), res=0;
			switch(exp[i])
			{
				case '+' : res = x+y; break;
				case '-' : res = x-y; break;
				case '*' : res = x*y; break;
				case '/' : res = x/y; break;
				case '^' : res = pow(x, y); break;
				case '%' : res = x%y; break;
				default: return -1;
			}
			STACKARR_push(s, res);
		}
	}
	STACKARR_display(s);
	return STACKARR_peek(s);
}
int main()
{
	char* str2 = "823^/23*+51*-";
	printf("Result: %d\n", evalPostFixExpr(str2));
}
