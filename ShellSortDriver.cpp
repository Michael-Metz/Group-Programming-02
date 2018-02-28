#include <iostream>

using namespace std;

int main(int arc, char *argv[]) {
	int *nums = new int[arc];

	for (int i = 0; i < arc; i++) {
		nums[i] = (int)argv[i];
	}

	int n = arc / sizeof(argv[0]);

	cout << "Array before sorting: \n";
	printArray(nums, n);

	shellSort(nums, n);

	cout << "\nArray after sorting: \n";
	printArray(nums, n);

	return 0;
}
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
