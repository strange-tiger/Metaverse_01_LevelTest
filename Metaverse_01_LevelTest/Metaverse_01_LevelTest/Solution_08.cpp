// ������ �ľ��� ���� : �迭�� ���� �Ҵ�, ������ �迭�� ���� �ľ�
// �ذ� ���̵�� : way�� wayCount, shellNum�̶�� ������� ������� �����Ͽ� ��� �� �迭 �Ҵ� ���

/*
#include <iostream>

int main()
{
	int arrSize;
	std::cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	std::cin >> arrSize;

	// 2���� �迭�� ���� �Ҵ�
	int** arr = new int*[arrSize];
	for (size_t i = 0; i < arrSize; i++)
	{
		arr[i] = new int[arrSize];
	}

	int shellNum = (arrSize + 1) / 2;					// �迭 ������ �ݺ� -> shellNum (������ ����)���� way�� 4���� ����
	int way = 0;										// ������ ���� -> ��� �������� ��ǥ�� �̵��ϴ°�, ������ / �Ʒ� / ���� / �� �� 4���� ���� ����
	int wayCount = 0;									// ��ǥ�� �̵��ϴ� Ƚ��
	for (size_t i = 0; i < arrSize * arrSize; i++)		// ���� arrSize * arrSize���� �Ҵ��Ѵ�.
	{
		int n = i + 1;
		
		int fixCoord_1 = (arrSize + 1) / 2 - shellNum;	// ù ���� ��ǥ �� : way == 0, 3 �϶� ���� ��� ���� ���� ��ǥ ��
		int fixCoord_2 = arrSize - fixCoord_1 - 1;		// �ι�° ���� ��ǥ �� : way == 1, 2 �϶� ���� ���� ���� ���� ��ǥ ��

		switch (way)
		{
		case 0:
			arr[fixCoord_1][fixCoord_1 + wayCount] = n;
			break;
		case 1:
			arr[fixCoord_1 + wayCount][fixCoord_2] = n;
			break;
		case 2:
			arr[fixCoord_2][fixCoord_2 - wayCount] = n;
			break;
		case 3:
			arr[fixCoord_2 - wayCount][fixCoord_1] = n;
			break;
		}
		wayCount++;

		if (wayCount >= 2 * shellNum - 1 - arrSize % 2)
		{
			wayCount = 0;
			way++;
		}

		if (way == 4)
		{
			way = 0;
			shellNum--;
		}
	}

	// ���
	for (size_t i = 0; i < arrSize; i++)
	{
		for (size_t j = 0; j < arrSize; j++)
		{
			std::cout << arr[i][j];

			j != arrSize - 1 ? std::cout << "\t" : std::cout << std::endl;
		}
	}

	for (size_t i = 0; i < arrSize; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
*/
#pragma region �������ڵ�
// ������ �ڵ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int num;

	printf("�迭�� ũ�⸦ �Է��Ͻÿ�.\n : ");
	scanf("%d", &num);

	int arr[100][100] = { 0 };
	int count = 0;
	arr[0][0] = count;

	int n = 1, x = 0, y = -1;
	for (int i = 2 * num; i >= 2; --i)
	{
		for (int j = 1; j <= i / 2; ++j)
		{
			count++;

			switch (n)
			{
			case 1:
				++y;
				break;
			case 2:
				++x;
				break;
			case 3:
				--y;
				break;
			case 4:
				--x;
				break;
			}

			arr[x][y] = count;

		}

		if (n == 4)
		{
			n = 1;
		}
		else
		{
			++n;
		}
	}

	// ���
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("\t%d\t", arr[i][j]);
		}
		printf("\n");
	}

}
#pragma endregion