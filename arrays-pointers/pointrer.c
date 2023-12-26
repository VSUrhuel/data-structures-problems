#include <stdio.h>

double computeMedian(double *a, int length);

int main()
{
	double arr[] = {2,1.1,3,4,10,5.1};
	int n = sizeof(arr)/sizeof(double);
	double median = computeMedian(arr,n);
	for(int i=0; i<n; i++)
	{
		printf("%.2f, ",arr[i]);
	}

	printf("\nMedian: %.2f",median);
	return 0;
}

double computeMedian(double *data, int length)
{
	double min = 1000;
	int index;
	for(int i=0; i<length; i++)
    {
        min = 1000;
        for(int j=i; j<length; j++)
        {
            if(data[j] < min)
            {
                min = data[j];
                index = j;
            }
        }
        int temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }

	if((length) % 2 != 0)
	{
		return data[(int)(length)/2];
	}
	else
	{
		return (data[(int)((length-1)/2)] + data[(int)(length/2)])/2;
	}
	return 0;
}
