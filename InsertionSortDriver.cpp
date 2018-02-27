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

    //make sure two arguments are  passed when running the program from command line
    if(arc != 3) {
        printUsage();
        return 0;
    }
    //at this point
    //argv[1] is the path to the input file
    //argv[2] is the path to save the output file

    LinkedList* list = new LinkedList;
    ifstream inputFile(argv[1]);
    
    if(!inputFile.is_open())
        cout << "could not open file" << endl;
    else
    {
        //read input file line by line and add to list
         long num;
        while(inputFile >> num)
           list->addTail(num);
    
         inputFile.close();

         //sort the list
         list->insertionSort();

         //save list to file
         list->outputToFile(argv[2]);
    }
    return 0;
}
