// ������ �ľ��� ���� : ���� �����ϰ� ��ġ�ϰ� ��ġ�� ĭ�� ��ġ�� ���¸� ����Ѵ�. �׸��� �� ĭ�� ��ġ�� ���� ������ ������ ����. �� ��� �� �ݺ��Ǿ� ǥ�õǾ�� �Ѵ�.
// �ذ� ���̵�� : vector�� 1���� 25������ ���� ����Ѵ�. �̸� int�� 2���� �迭�� ���� ������ �����Ѵ�. ���� vector�� ����Ϸ������� �ͼ����� �ʾ� �����ߴ�. �����ϴ� �������� �����ϸ� vector���� ���Ҹ� ���������ν� �ߺ��� ���Ѵ�.

#include <iostream>
#include <vector>
#include <cstdlib>

void CreateMap(int* (bingoNum)[5]);
int BingoCount(int* (bingoNum)[5], int size);
void PrintMap(int bingoCnt, int* (bingoNum)[5]);

int main()
{
	int* (bingoNum)[5] = { 0 };
	CreateMap(bingoNum);
	//std::vector<int> v(25);
	//
	//for (size_t i = 0; i < 25; i++)
	//{
	//	v[i] = i + 1;
	//}
	//
	//std::srand(time(NULL));
	//
	//int bingoNum[5][5] = { 0 };
	//for (size_t i = 0; i < 25; i++)
	//{
	//	int tempNum = rand() % v.size();
	//	bingoNum[i / 5][i % 5] = v[tempNum];
	//	v.erase(v.begin() + tempNum);
	//}

	//int bingoCnt = 0;
	//while (bingoCnt < 5 * 2 + 2)
	//{
	//	for (size_t i = 0; i < 5; i++)
	//	{
	//		for (size_t j = 0; j < 5; j++)
	//		{
	//			bingoNum[i][j] != 0 ? std::cout << bingoNum[i][j] : std::cout << "";
	//			
	//			j != 4 ? std::cout << "\t" : std::cout << std::endl;
	//		}
	//	}
	//	
	//	int bingoCnt = 0;
	//	
	//	// ������ ���� ī��Ʈ
	//	for (size_t i = 0; i < 5; i++)
	//	{
	//		bool rowBingo = true;
	//		for (size_t j = 0; j < 5; j++)
	//		{
	//			if (bingoNum[i][j] != 0)
	//			{
	//				rowBingo = false;
	//				break;
	//			}
	//		}
	//		if (rowBingo)
	//		{
	//			bingoCnt++;
	//		}
	//	}
	//
	//	// ������ ���� ī��Ʈ
	//	for (size_t i = 0; i < 5; i++)
	//	{
	//		bool columnBingo = true;
	//		for (size_t j = 0; j < 5; j++)
	//		{
	//			if (bingoNum[j][i] != 0)
	//			{
	//				columnBingo = false;
	//				break;
	//			}
	//		}
	//		if (columnBingo)
	//		{
	//			bingoCnt++;
	//		}
	//	}
	//
	//	// ���� �� �밢���� ���� ī��Ʈ
	//	bool crossBingo = true;
	//	for (size_t i = 0; i < 5; i++)
	//	{
	//		if (bingoNum[i][i] != 0)
	//		{
	//			crossBingo = false;
	//			break;
	//		}
	//	}
	//	if (crossBingo)
	//	{
	//		bingoCnt++;
	//	}
	//
	//	// ������ �� �밢���� ���� ī��Ʈ
	//	crossBingo = true;
	//	for (size_t i = 0; i < 5; i++)
	//	{
	//		if (bingoNum[i][4 - i] != 0)
	//		{
	//			crossBingo = false;
	//			break;
	//		}
	//	}
	//	if (crossBingo)
	//	{
	//		bingoCnt++;
	//	}

	int bingoCnt = 0;
	while (1)
	{
		bingoCnt = BingoCount(bingoNum, 5);

		PrintMap(bingoCnt, bingoNum);
	}
	
	/*std::cout << "���� " << bingoCnt << "���� ���� �ϼ��Ǿ����ϴ�." << std::endl;
	std::cout << "���ڸ� �Է��� �ּ��� : ";

	int inputNum;
	std::cin >> inputNum;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (inputNum == bingoNum[i][j])
			{
				bingoNum[i][j] = 0;
				break;
			}
		}
	}
	system("cls");
}*/
}

void CreateMap(int* (bingoNum)[5])
{
	std::vector<int> v(25);

	for (size_t i = 0; i < 25; i++)
	{
		v[i] = i + 1;
	}

	std::srand(time(NULL));

	for (size_t i = 0; i < 25; i++)
	{
		int tempNum = rand() % v.size();
		bingoNum[i / 5][i % 5] = v[tempNum];
		v.erase(v.begin() + tempNum);
	}
}

int BingoCount(int* (bingoNum)[5], int size)
{
	int bingoCnt = 0;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			bingoNum[i][j] != 0 ? std::cout << bingoNum[i][j] : std::cout << "";

			j != 4 ? std::cout << "\t" : std::cout << std::endl;
		}
	}

	int bingoCnt = 0;

	for (size_t i = 0; i < size; i++)
	{
		// ����, ������ ���� ī��Ʈ
		bool rowBingo = true;
		bool columnBingo = true;
		for (size_t j = 0; j < size; j++)
		{
			if (bingoNum[i][j] != 0)
			{
				rowBingo = false;
				break;
			}

			if (bingoNum[j][i] != 0)
			{
				columnBingo = false;
				break;
			}
		}

		if (rowBingo)
		{
			bingoCnt++;
		}
		if (columnBingo)
		{
			bingoCnt++;
		}

		// ���� �� �밢���� ���� ī��Ʈ
		bool crossBingo = true;
		for (size_t i = 0; i < size; i++)
		{
			if (bingoNum[i][i] != 0)
			{
				crossBingo = false;
				break;
			}
		}

		if (crossBingo)
		{
			bingoCnt++;
		}

		// ������ �� �밢���� ���� ī��Ʈ
		crossBingo = true;
		for (size_t i = 0; i < size; i++)
		{
			if (bingoNum[i][size - i - 1] != 0)
			{
				crossBingo = false;
				break;
			}
		}

		if (crossBingo)
		{
			bingoCnt++;
		}
	}

	return bingoCnt;
}

void PrintMap(int bingoCnt, int* (bingoNum)[5])
{
	std::cout << "���� " << bingoCnt << "���� ���� �ϼ��Ǿ����ϴ�." << std::endl;
	std::cout << "���ڸ� �Է��� �ּ��� : ";

	int inputNum;
	std::cin >> inputNum;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (inputNum == bingoNum[i][j])
			{
				bingoNum[i][j] = 0;
				break;
			}
		}
	}
	system("cls");
}

#pragma region �������ڵ�
// ������ �ڵ�
///*
//	[������ �ľ��� ����]
//	- 1 ~ 25 ���� �������� ��ġ�� 5*5 ������ ����
//	- ���ڸ� �Է¹����� �׿� ���� ���ڰ� ��������, �������� �ϼ��� ������ ������ ���� �߰�
//	[�ذ� ���̵��]
//	- ������ �����ϴ� �Լ� / ���� �����ϴ� �Լ� / ������ ����ϴ� �Լ� / �÷����ϴ� �Լ�
//	- 1) �����ϴ� �Լ��� �ʱ⿡ ������ �������ִ� �Լ�
//	- 2) ���� �����ϴ� �Լ� - ���� ���� / ���� ���� / �밢�� ���� Ȯ���� ������ ��ȯ
//	- 3) ������ �ܼ�â�� ���
//	- 4) �Լ����� �̿��� �÷���
//	- ���� ���� �����ϴ� ������ ���淡 ������ �� ä���߸� ���ߵ��� �����߽��ϴ� ^^
//*/
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdbool.h>
//
//void Create_Map(int(*arr)[5], int width_n, int height_n);	// �� ����
//int Judgment(int(*arr)[5], int width_n, int height_n);
//void Print_Map(int(*arr)[5], int width_n, int height_n);	//�� �� ������ �� ��������
//void Play_Game();	//�����÷���
//
//int main()
//{
//	Play_Game();
//}
//
//void Create_Map(int(*arr)[5], int width_n, int height_n)
//{
//	srand(time(NULL));
//	int count = 0;
//	int randArr[25] = { 0 };
//
//	while (count < 25)
//	{
//		int randNum = rand() % 25 + 1;
//		bool isRandNumExistence = false;
//		for (int i = 0; i <= count; i++)
//		{
//			if (randNum == randArr[i])
//			{
//				isRandNumExistence = true;
//				break;
//			}
//		}
//
//		if (!isRandNumExistence)
//		{
//			randArr[count++] = randNum;
//		}
//
//	}
//
//	for (int i = 0; i < height_n; i++)
//	{
//		for (int j = 0; j < width_n; j++)
//		{
//			arr[i][j] = randArr[--count];
//		}
//	}
//
//}
//
//void Print_Map(int(*arr)[5], int width_n, int height_n)
//{
//	for (int i = 0; i < width_n; i++)
//	{
//		for (int j = 0; j < height_n; j++)
//		{
//			if (arr[i][j] == 0)
//				printf("	");
//			else
//				printf("%d	", arr[i][j]);
//		}
//		printf("\n\n");
//	}
//}
//
//int Judgment(int(*arr)[5], int arrNum1, int arrNum2)
//{
//	int count_bingo = 0;
//
//	bool diagonal_judgment1 = true;	// �밢��1 ����
//	bool diagonal_judgment2 = true;	// �밢��2 ����
//	for (int i = 0; i < arrNum1; i++)
//	{
//		bool horizontal_judgment = true;	// ���� ����
//		bool vertical_judgment = true;		// ���� ����
//
//		for (int j = 0; j < arrNum2; j++)
//		{
//			if (arr[i][j] != 0)
//				horizontal_judgment = false;
//			if (arr[j][i] != 0)
//				vertical_judgment = false;
//
//			if (i == j && arr[i][j] != 0)
//				diagonal_judgment1 = false;
//			if (i + j == 4 && arr[i][j] != 0)
//				diagonal_judgment2 = false;
//		}
//
//		if (horizontal_judgment)
//			count_bingo++;
//		if (vertical_judgment)
//			count_bingo++;
//	}
//
//	if (diagonal_judgment1)
//		count_bingo++;
//	if (diagonal_judgment2)
//		count_bingo++;
//
//	return count_bingo;
//}
//
//void Play_Game()
//{
//	int Bingo[5][5] = { 0 };
//	Create_Map(Bingo, 5, 5);
//
//	int bingo = 0;
//	while (bingo < 12)
//	{
//		Print_Map(Bingo, 5, 5);
//
//		int num;
//
//		printf("���� %d���� ���� �ϼ��Ǿ����ϴ�.\n", bingo);
//		printf("���ڸ� �Է����ּ��� : ");
//		scanf("%d", &num);
//
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 5; j++)
//			{
//				if (num == Bingo[i][j])
//				{
//					Bingo[i][j] = 0;
//				}
//			}
//		}
//
//		bingo = Judgment(Bingo, 5, 5);
//
//		system("cls");
//	}
//
//	printf("%d���� ���� ��� �ϼ��ϼ̽��ϴ�.", bingo);
//
//}
#pragma endregion