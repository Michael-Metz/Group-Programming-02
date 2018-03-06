#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <fstream>

using namespace std;

void printUsage();

bool outputArrayToFile(const long a[], const int &size, char *filePath);

void merge(long a[], long temp[], const int &aSize, const int &left, const int &mid, int end);

void mergeSort(long a[], const int &aSize);

int main(int arc, char *argv[]) {

    //make sure two arguments are  passed when running the program from command line
    if (arc != 3) {
        printUsage();
        return 0;
    }
//    char* inputPath = argv[1];
    char *outputPath = argv[2];

    ifstream inputFile(argv[1]);

    if (!inputFile.is_open()) {
        cout << "could not open file" << endl;
    } else {
        stack<long> numStack;
        register int numCount = 0;
        //read input file line by line and add to stack
        long num;
        while (inputFile >> num) {
            numStack.push(num);
            numCount++;
        }
        inputFile.close();

        //now we know how many numbers we read so we can make an array
        long *numArray = new long[numCount];


        for (int i = numCount - 1; 0 <= i; i--) {
            numArray[i] = numStack.top();
            numStack.pop();
        }

        mergeSort(numArray, numCount);

        outputArrayToFile(numArray, numCount, outputPath);
        delete[] numArray;
    }
    return 0;
}

/**
 * Sorts an array using bottom up mergesort
 * requires O(n) extra memory in heap
 *
 * @param a - the array to sort
 * @param aSize - the size of array "a"
 */
void mergeSort(long a[], const int &aSize) {
    long *temp = new long[aSize];
    int right, end;

    for (int width = 1; width < aSize; width *= 2) {
        for (int l = 0; l + width < aSize; l += width * 2) {
            right = l + width;
            end = right + width;
            merge(a, temp, aSize, l, right, end);
        }
    }
    delete[] temp;
}

void merge(long a[], long temp[], const int &aSize, const int &left, const int &mid, int end) {

    if (end > aSize)
        end = aSize;

    int m = left;
    int i = left;
    int j = mid;

    while (i < mid && j < end) {
        if (a[i] <= a[j]) {
            temp[m] = a[i];
            i++;
        } else {
            temp[m] = a[j];
            j++;
        }
        m++;
    }
    for (; i < mid; i++) {
        temp[m] = a[i];
        m++;
    }
    for (; j < end; j++) {
        temp[m] = a[j];
        m++;
    }
    for (m = left; m < end; m++) {
        a[m] = temp[m];
    }
}

/**
 * Prints the intended usage to the console
 */
void printUsage() {
    cout << "mergesort [input-file-path] [output-file-path]" << endl << endl;
    cout << "This program reads an input file line by line parsing long values and then sorts them" << endl;
    cout << "and stores them in the same format, using the output file path" << endl;

}

/**
 * Output each element in an array to a separate line in a file
 *
 * @param a - the array
 * @param size - the size of the array
 * @param filePath - the path that you want to save the file
 * @return true if we are able to save the file
 */
bool outputArrayToFile(const long a[], const int &size, char *filePath) {
    ofstream outputFile(filePath);

    if (!outputFile.is_open()) {
        cout << "unable to open output file" << endl;
        return false;
    }
    for (int i = 0; i < size; i++) {
        outputFile << a[i] << endl;
    }
    outputFile.close();
    return true;
}