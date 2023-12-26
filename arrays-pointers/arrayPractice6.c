#include <stdio.h>
#include <stdlib.h>

int main()
{
    int jagged[4][5];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(j<=i)
                jagged[i][j]=j;
            else
                jagged[i][j]=-1;
        }
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(jagged[i][j] == -1)
                printf(" ");
            else
                printf("%d ",jagged[i][j]);
        }
        printf("\n");
    }


    int temp[5];
    for(int i=0; i<5; i++)
        temp[i] = jagged[1][i];
    for(int i=0; i<5; i++)
        jagged[1][i] = jagged[3][i];
    for(int i=0; i<5; i++)
        jagged[3][i] = temp[i];

    printf("\nSwapped Jagged Array\n");
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(jagged[i][j] == -1)
                printf(" ");
            else
                printf("%d ",jagged[i][j]);
        }
        printf("\n");
    }
}

