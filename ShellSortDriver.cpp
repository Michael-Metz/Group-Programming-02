#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stack>

using namespace std;
void printArray(int nums[], int n)
{
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";
}
void shellSort(long nums[], const int& n)
{	//Starts with a large gap and then decreases
	for (int g = n / 2; g > 0; g /= 2)
	{	//gapped insertion sort for this gap size
		for (int i = g; i < n; i += 1)
		{	//add nums[i] to the sorted items
			//makes a gap at i 
			long temp = nums[i];
			int k;
			//finds the right location for nums[i]
			for (k = i; k >= g && nums[k - g] > temp; k -= g) {
				nums[k] = nums[k - g];
			}
			//adds nums[i] to the right spot in the array
			nums[k] = temp;
		}
	}
}
void printUsage(){
	cout << "shellsort [input-file-path] [output-file-path]" << endl << endl;
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

		shellSort(numArray,numCount);
		cout << "output" << endl;

		outputArrayToFile(numArray,numCount,outputPath);
		delete[] numArray;
	}
	return 0;
}
