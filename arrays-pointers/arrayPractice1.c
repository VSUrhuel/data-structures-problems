#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    double weights[10];

    for(int i=0; i<10; i++)
        weights[i] = rand()%10+0;
    double sum = 0.0;
    for(int i=0; i<10; i++)
    {
        sum += weights[i];
        printf("%.2f\n",weights[i]);
    }
    double average = sum/10.0;
    printf("\nValues Greater than the Average %.2f\n", average);
    for(int i=0; i<10; i++)
    {
        if(weights[i] > average)
            printf("%.2f\n",weights[i]);
    }

}
