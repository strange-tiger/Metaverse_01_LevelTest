#include <iostream>


void sortArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int su = arr[0];
		for (int j = 1; j < size; j++)
		{
			if (su > arr[j])
			{
				arr[i - 1] = arr[j];
				arr[i] = su;
			}
			else if (su < arr[j])
			{
				su = arr[i];
			}
		}
	} // while ¹® ³¡
}

int main()
{
	int arr[5] = { 5, 2, 4, 1, 3 };
	sortArray(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
}