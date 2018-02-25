#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

void printUsage(){
    cout << "insertionsort [input-file-path] [output-file-path]" << endl << endl;
    cout << "This program reads an input file line by line parsing long values and then sorts them" << endl;
    cout << "and stores them in the same format, using the output file path" << endl;

}
int main(int arc, char *argv[]) {

    if(arc != 3) {
        printUsage();
        return 0;
    }

    LinkedList* list = new LinkedList;
    ifstream inputFile(argv[1]);
    if(!inputFile.is_open())
        cout << "could not open file" << endl;

    long data;
    while(inputFile >> data)
        list->addTail(data);
    inputFile.close();

    list->insertionSort();

    list->outputToFile(argv[2]);
    return 0;
}
