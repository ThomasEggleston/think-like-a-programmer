#include "iostream"




int compareFunc(const void *voidA, const void *voidB)
{
	int * intA = (int *) (voidA);
	int * intB = (int *) (voidB);
	return *intA - *intB;
}

void runQSort()
{
	const int ARRAY_SIZE = 10;
	int intArray[ARRAY_SIZE] = { 87, 28, 100, 78, 84, 98, 75, 70, 81, 68 };

	qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << intArray[i] << ' ';
	}
	std::cout << '\n';
	std::cin.get();
}


// Similar to sorting a hand of cards
void runInsertionSort()
{
	const int ARRAY_SIZE = 10;
	int intArray[ARRAY_SIZE] = { 87, 28, 100, 78, 84, 98, 75, 70, 81, 68 };

	int start = 0;
	int end = ARRAY_SIZE - 1;

	// Iterate through each item
	for (int i = start + 1; i <= end; i++)
	{
		// Compare with unsorted items and swap if necessary
		for (int j = i; j > start && intArray[j-1] > intArray[j]; j--)
		{
			int temp = intArray[j - 1];
			intArray[j-1] = intArray[j]
				;
			intArray[j] = temp;
		}
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << intArray[i] << ' ';
	}
	std::cout << '\n';
	std::cin.get();
}

int main()
{
	//runQSort();
	runInsertionSort();
}