#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// function that merges the two array halves
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int tempArray1[n1], tempArray2[n2];

    for (i = 0; i < n1; i++)
        tempArray1[i] = a[l + i];
    for (j = 0; j < n2; j++)
        tempArray2[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    // merge the temp arrays into one array
    while (i < n1 && j < n2)
    {
        if (tempArray1[i] <= tempArray2[j])
        {
            a[k] = tempArray1[i];
            i++;
        }
        else
        {
            a[k] = tempArray2[j];
            j++;
        }
        k++;
    }

    // copies the remaining elements of the first temp array
    while (i < n1)
    {
        a[k] = tempArray1[i];
        i++;
        k++;
    }

    // copies the remaining elements of the second temp array
    while (j < n2)
    {
        a[k] = tempArray2[j];
        j++;
        k++;
    }
}

// function to find the minimum of two ints
int min(int x, int y)
{
    return (x<y)? x:y;
}
// prints the sorted array out
void printArray(int sortedArray[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << sortedArray[i] << " ";
    cout << "\n";
}

// iterative version of mergesort
void mergeSort(int a[], int n)
{
    int currentSize;
    int start;

    for (currentSize = 1; currentSize <= n-1; currentSize = 2* currentSize)
    {
        for (start = 0; start <n-1; start = start + (2*currentSize))
        {
            int mid = start + currentSize - 1;
            int end = min(start + 2*currentSize - 1, n-1);

            merge(a, start, mid, end);
        }
    }
}

int main()
{
    int array[] = {12, 10, 13, 5, 7, 4, 3, 1};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Original array \n";
    printArray(array, n);

    mergeSort(array, n);

    cout << "\nSorted array\n";
    printArray(array, n);
    return 0;
}
