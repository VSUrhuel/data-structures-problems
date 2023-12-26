#include <stdio.h>
#include <stdlib.h>

int countZeroes(int n);
int countDigit(int n);
int checkProperRound(int n);
int checkSameDigit(int n);
void sameDigit(int n);
void sameDigitExcept(int n);
int checkNoZeroDigit(int n);
void noZeroDigit(int n);
void zeroLastDigit(int n);
void zeroInBetween(int n);

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(countDigit(arr[i])==1)
        {
            printf("1\n");
            printf("%d\n", arr[i]);
        }
        else if(checkProperRound(arr[i]) == 1)
        {
            printf("1\n");
            printf("%d\n", arr[i]);
        }
        else if(checkSameDigit(arr[i]) == 1)
        {
            sameDigit(arr[i]);
        }
        else if(arr[i]%10 == 0 && checkSameDigit(arr[i]/10) == 1)
        {
            sameDigitExcept(n);
        }
        else if(checkNoZeroDigit(arr[i]))
        {
            noZeroDigit(arr[i]);
        }
        else if(arr[i]%10 == 0 && checkSameDigit(arr[i]/10) == 0)
        {
            zeroLastDigit(arr[i]);
        }
        else
            zeroInBetween(arr[i]);
    }
}
int countDigit(int n)
{
    int ctr = 0;
    while(n>0)
    {
        ctr++;
        n/=10;
    }
    return ctr;
}
int checkProperRound(int n)
{
    while(n>10)
    {
        int digit = n % 10;
        if(digit > 0)
            return 0;
        n/=10;
    }
    return 1;
}
int checkSameDigit(int n)
{
    while(n>0)
    {
        int currentDigit = n % 10;
        int nextDigit = (n % 100)/10;
        if(currentDigit != nextDigit && nextDigit != 0)
            return 0;
        n/=10;
    }
    return 1;
}
int checkNoZeroDigit(int n)
{
    while(n>0)
    {
        int currentDigit = n % 10;
        if(currentDigit == 0)
            return 0;
        n/=10;
    }
    return 1;
}
void noZeroDigit(int n)
{
    printf("%d\n",countDigit(n));
    int f = 1;
    while(n>0)
    {
        int digit = n % 10;
        printf("%d ", digit * f);
        f*=10;
        n/=10;
    }
    printf("\n");
}
void sameDigit(int n)
{
    int count = countDigit(n);
    printf("%d\n", count);
    int f=1, num=n%10;
    for(int i=0; i<count; i++)
    {
        printf("%d ",num*f);
        f*=10;
    }
    printf("\n");
}
void sameDigitExcept(int n)
{
    int count = countDigit(n);
    printf("%d\n", count-1);
    int f=10, num=n%10;
    for(int i=0; i<count-1; i++)
    {
        printf("%d ",num*f);
        f*=10;
    }
    printf("\n");
}
void zeroLastDigit(int n)
{
    int count = countDigit(n)-1;
    printf("%d\n", count-1);
    int f=10, j=10;
    for(int i=0; i<count; i++)
    {
        int digit = ((n/j)%10)*f;
        printf("%d ", digit);
        j*=10;
        f*=10;
    }
    printf("\n");
}
void zeroInBetween(int n)
{
    int count = countDigit(n) - countZeroes(n);
    printf("%d\n", count);
    int f=1;
    while(n>0)
    {
        int digit = n % 10;
        if((n%100)==digit)
        {
            printf("%d ", digit*f);
            n/=100;
            f*=100;
        }
        else if((n%100==digit) && (n%1000==digit))
        {
            printf("%d ", digit*f);
            n/=1000;
            f*=1000;
        }
        else if (digit == 0)
        {
            n/=10;
            f*=10;
        }
        else
        {
            printf("%d ", digit*f);
            n/=10;
            f*=10;
        }
    }
    printf("\n");
}
int countZeroes(int n)
{
    int ctr= 0;
    while(n>0)
    {
        int digit = n%10;
        if(digit==0)
        {
            ctr++;
        }
        n/=10;
    }
    return ctr;
}
