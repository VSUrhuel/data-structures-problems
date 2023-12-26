#include <stdio.h>

int main()
{
    int x = 179;
    int temp = 0;
    while(x > 0)
    {
        int temp = x;
        x = x >> 1;
        x = x << 1;
        if(temp == x)
            printf("0");
        else
            printf("1");
        x = x >> 1;
    }
}
