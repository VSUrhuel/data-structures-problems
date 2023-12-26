#include <stdio.h>

int main()
{
	int a[][3] = {{1,2,3},{4,5,6}};
	int (*ptr)[3] = a;
	printf("%d %d ", (*ptr)[1], (*ptr)[2]);
	ptr++;
	printf("%d %d", (*ptr)[1], (*ptr)[2]);
	return 0;
}


f(6, 1) // 6 +
f(11,2) // 11 - 
f(4,3) // 4 +
f(13,4)// 13 -
f(7,5) // 7 -
f(12,6) //12 +

z = 5;
y = 7;
x = 7;
3,0,
