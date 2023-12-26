#include "stackA.h"
#include <string.h>
#include <ctype.h>
#include <math.h>

int evalPostFixExpr(char* expr)
{
	int len = strlen(expr);
	STACKARR  s = STACKARR_create(100);
	char* ops = "+-*^/%";
	for(int i=0; i < len; i++)
	{
		if(isdigit(expr[i]))
		{
			STACKARR_push(s,expr[i]-'0');
		}
		else if(strchr(ops,expr[i]))
		{
			int y = STACKARR_pop(s);
			int x = STACKARR_pop(s);
			int res=0;
			switch(expr[i])
			{
				case '+': res = x+y; break;
				case '-': res = x-y; break;
				case '*': res = x*y; break;
				case '^': res = pow(x,y); break;
				case '/': res = x/y; break;
				case '%': res = x%y; break;
				default: return -1;
			}
			STACKARR_push(s,res);
		}
	}
	return STACKARR_peek(s);
}

int main()
{
	/*char expr[10000];
	scanf("%s",expr);*/
	//char* str = "823^/23*+51*-";
	//char* str2 = "95989%-52+*^-";
	char* str2 = "23^74%4*/1-23^8/*9+";
	printf("Result: %d\n", evalPostFixExpr(str2));
	//STACKARR s = STACKARR_create(5);

	return 0;
}