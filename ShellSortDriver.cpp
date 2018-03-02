#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
void printArray(int nums[], int n)
{
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";
}
long[] shellSort(long nums[], long n)
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
	return nums;
}
void printUsage(){
	cout << "shellsort [input-file-path] [output-file-path]" << endl << endl;
	cout << "This program reads an input file line by line parsing long values and then sorts them" << endl;
	cout << "and stores them in the same format, using the output file path" << endl;

}
int main(int arc, char *argv[]) {
	//make sure two arguments are  passed when running the program from command line
	if (arc != 3) {
		printUsage();
		return 0;
	}
	//at this point
	//argv[1] is the path to the input file
	//argv[2] is the path to save the output file

	int totalNumbersRead = 0;
	ifstream inputFile(argv[1]);

	if (!inputFile.is_open())
	{
		cout << "could not open file" << endl;
	}
	else
	{
		//read input file line by line and add to stack
		long num;
		while (inputFile >> num)
		{
			//TODO add num to stack
			totalNumbersRead++;
		}
		inputFile.close();

		//now we know how many numbers we read from the file
		long *numbers = new long[totalNumbersRead];

		//TODO add numbers from stack to the numbers array.

		printArray(numbers, totalNumbersRead);

		//sort
		shellSort(numbers, totalNumbersRead);


		printArray(numbers, totalNumbersRead);

		//write sorted array to the output file
		ofstream outputFile(argv[2]);
		if(!outputFile.is_open()){
			cout << "unable to open output file" << endl;
			return 1;
		}
		for(int i = 0; i < totalNumbersRead; i++){
			outputFile << numbers[i] << endl;
		}

		delete numbers;
	}
	return 0;
}
