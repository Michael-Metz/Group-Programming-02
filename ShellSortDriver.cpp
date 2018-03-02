#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
void printArray(int nums[], int n)
{
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";
}
int shellSort(int nums[], int n)
{
	for (int g = n / 2; g > 0; g /= 2)
	{
		for (int i = g; i < n; i += 1)
		{
			int temp = nums[i];
			int k;
			for (k = i; k >= g && nums[k - g] > temp; k -= g) {
				nums[k] = nums[k - g];
			}
			nums[k] = temp;
		}
	}
	return 0;
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
		int *numbers = new int[totalNumbersRead];

		//TODO add numbers from stack to the numbers array.



		//sort
		shellSort(numbers, totalNumbersRead);



		//write sorted array to the output file
		ofstream outputFile(argv[2]);
		if(!outputFile.is_open()){
			cout << "unable to open output file" << endl;
			return;
		}
		for(int i = 0; i < totalNumbersRead; i++){
			outputFile << numbers[i] << endl;
		}

		delete numbers;
	}
	return 0;
}
