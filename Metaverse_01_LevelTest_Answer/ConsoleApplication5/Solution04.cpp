#include <iostream>

using namespace std;

void Sort(int* arr, int size)
{
	// ���� ��Ʈ�� ���� ������� �̷�����,
	// �� ����� ���� �� �� �� ���Һ��� ���ĵȴ�.
	for (int phase = 0; phase < size - 1; ++phase)
	{
		// ù ��° ���Һ��� ���س�����.
		for (int i = 0; i < size - 1 - phase; ++i)
		{
			// ���� ���� : ���� ���Ұ� ���� ���Һ��� Ŭ ��(��������)
			if (arr[i] < arr[i + 1])
			{
				// ���� �ٲ۴�.
				std::swap(arr[i], arr[i + 1]);
			}
		}
	}
}

int main()
{
	int arr[5] = { 5, 2, 4, 1, 3 };
	Sort(arr, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}

	return 0;
}