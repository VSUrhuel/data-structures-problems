#include <iostream>
#include <cctype>
using namespace std;

void bubbleSort(int a[], int n);
void selectionSort(int b[], int n);
void insertionSort(int c[], int n);

int main()
{
    int n;
    do
    {
        cout<<"Enter number of elements: ";
        cin>>n;
    } while(n <= 0);

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cout<<"arr["<<i<<"]: ";
        cin>>arr[i];
    }

    cout<<endl<<"Sorting algorithms"<<endl;
    cout<<"Bubble Sort (B)"<<endl;
    cout<<"Selection Sort (S)"<<endl;
    cout<<"Insertion Sort (I)"<<endl;
    cout<<"All 3 Sorting Algorithm (A)"<<endl;

    char a;
    cout<<"Enter Sorting Algorith: ";
    cin>>a;
    a = toupper(a);

    switch (a)
    {
        case 'B':
        {
            bubbleSort(arr, n);
            break;
        }
        case 'S':
        {
            selectionSort(arr, n);
            break;
        }
        case 'I':
        {
            insertionSort(arr, n);
            break;
        }
        case 'A':
        {
            bubbleSort(arr, n);
            selectionSort(arr, n);
            insertionSort(arr, n);
            break;
        }
        default:
        {
            cout<<"Invalid Selection"<<endl;
        }
    }
}
void bubbleSort(int arr[], int n)
{
    //This sorting algorithm contains two kinds of steps: COMPARISON and SWAPS;
    //Comparisons, two numbers are compared with one another to determine which is greater;
    //Swaps, two numbers are swapped with one another in orther to sort them;
    //For N elements, we make (N-1) + (N-2) + (N-3) ... + 1 comparisons;
    //Thus, Bubble Sort has an efficiency of O(N^2), wherein for N data elements, there are roughly N^2 steps;
/*
    int unsortedIndex = n-1;
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i=0; i<unsortedIndex; i++)
        {
            int temp = 0;
            if(arr[i]>arr[i+1])
            {
                sorted = false;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        unsortedIndex--;
    }*/

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            int temp = 0;
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<endl<<"Bubble Sort"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
void selectionSort(int arr[], int n)
{
    //Selection Sorrt contains two steps, COMPARISONS and SWAPS;
    //We compare each element with the lowest number we've encountered in each passthrough;
    //We swap the lowest number into its correct position;
    //For N elements, we make (N-1) + (N-2) + (N-3) ... + 1 comparisons;
    //In Selection Sort we only need to make a maximum of one swaps, that is after we find the lowest number
    //Contrast with Bubble Sort, where in worst-case scenario, we have to make swap each and every comparison;
    //Thus, the efficiency of Selection Sort is O(N^2/2), but since the rule of Big O notation is ignoring constants,
    //It will still be an O(N^2). However, we all know, that despite having same efficiency of O(N^2) with
    //Bubble Sort, Selection Sort is twice as fast;
    for(int i=0; i<n; i++)
    {
        int minElement = 1000000;
        int minIndex = 0;
        int temp = 0;
        for(int j=i; j<n; j++)
        {
            if(minElement > arr[j])
            {
                minElement = arr[j];
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    cout<<endl<<"Selection Sort"<<endl;
     for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
void insertionSort(int arr[], int n)
{
    //There were four types occured: REMOVALS, COMPARISONS, SHIFTS, INSERTIONS
    //Comparisons happens each time we compare a value to the left game with the TEMP. It has 1 + 2 + 3 + ... + N-1 comparions;
    //Shifts occur each time we move a value one cell to the right.
    //Remnoving and Inserting the temp from the array happen once per passthrough.
    //Thus, N^2 for Comparisons and Shifts, N-1 for removals and Insertions;
    //Hence, N^2 + 2N - 2 steps;
    //But BIG O takes into account only the highest order of N, thus, we have N^2 efficiency;
    //However, Insertion Sort is the best among the three because in an average case scenario the performance is
    //In between of N and N^2;
    int index = 1;
    for(int i=index; i<n; i++)
    {
        int position = i;
        int temp = arr[i];
        while(position > 0 && arr[position-1]>temp)
        {
            arr[position] = arr[position-1];
            position--;
        }
        arr[position] = temp;
    }

    cout<<endl<<"Insertion Sort"<<endl;
     for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
