#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <fstream>

using namespace std;

// function that merges the two array halves
void merge(long a[],const int& l,const int& m,const int& r)
{
    cout << "merge" << endl;

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    long tempArray1[n1], tempArray2[n2];

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

// function to find the minimum of two longs
int min(long& x, long& y)
{
    return (x<y)? x:y;
}
//// prints the sorted array out
//void printArray(int sortedArray[], int size)
//{
//    int i;
//    for (i = 0; i < size; i++)
//        cout << sortedArray[i] << " ";
//    cout << "\n";
//}

// iterative version of mergesort
void mergeSort(long a[], const int& n)
{
    cout << "mergeSort" << endl;
    int currentSize;
    int start;

    for (currentSize = 1; currentSize <= n-1; currentSize = 2* currentSize)
    {
        for (start = 0; start < n-1; start = start + (2*currentSize))
        {
            int mid = start + currentSize - 1;
            int end = min(start + 2*currentSize - 1, n-1);

            merge(a, start, mid, end);
        }
    }
}

void printUsage(){
    cout << "mergesort [input-file-path] [output-file-path]" << endl << endl;
    cout << "This program reads an input file line by line parsing long values and then sorts them" << endl;
    cout << "and stores them in the same format, using the output file path" << endl;

}
bool outputArrayToFile(const long a[], const int& size, char* filePath){
    ofstream outputFile(filePath);

    if(!outputFile.is_open()){
        cout << "unable to open output file" << endl;
        return false;
    }
    for(int i = 0; i < size; i++){
        outputFile << a[i] << endl;
    }
    outputFile.close();
    return true;
}
int main(int arc, char *argv[]) {

    //make sure two arguments are  passed when running the program from command line
    if(arc != 3) {
        printUsage();
        return 0;
    }
//    char* inputPath = argv[1];
    char* outputPath = argv[2];

    ifstream inputFile(argv[1]);

    if(!inputFile.is_open())
    {
        cout << "could not open file" << endl;
    }
    else
    {
        stack <long> numStack;
        register int numCount = 0;
        //read input file line by line and add to stack
        long num;
        cout << "reading numbers" << endl;
        while(inputFile >> num)
        {
            numStack.push(num);
            numCount++;
        }
        inputFile.close();

        //now we know how many numbers we read so we can make an array
        long* numArray = new long[numCount];
        cout << "making array" << endl;

        for(int i = numCount-1; 0 <= i; i--){
            numArray[i] = numStack.top();
            numStack.pop();
        }
        cout << "sorting" << endl;

        mergeSort(numArray,numCount);
        cout << "output" << endl;

        outputArrayToFile(numArray,numCount,outputPath);
        delete[] numArray;
    }
    return 0;
}
