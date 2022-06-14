// ������ �ľ��� ���� : ���� �����ϰ� ��ġ�ϰ� ��ġ�� ĭ�� ��ġ�� ���¸� ����Ѵ�. �׸��� �� ĭ�� ��ġ�� ���� ������ ������ ����. �� ��� �� �ݺ��Ǿ� ǥ�õǾ�� �Ѵ�.
// �ذ� ���̵�� : vector�� 1���� 25������ ���� ����Ѵ�. �̸� int�� 2���� �迭�� ���� ������ �����Ѵ�. ���� vector�� ����Ϸ������� �ͼ����� �ʾ� �����ߴ�. �����ϴ� �������� �����ϸ� vector���� ���Ҹ� ���������ν� �ߺ��� ���Ѵ�.

#include <iostream>
#include <vector>
#include <cstdlib>

void CreateMap(int (*bingoNum)[5]);
int BingoCount(int (*bingoNum)[5], int size);
void PrintMap(int bingoCnt, int (*bingoNum)[5]);

int main()
{
	int bingoNum[5][5] = { 0 };
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
	while (bingoCnt < 10)
	{
		bingoCnt = BingoCount(bingoNum, 5);

		PrintMap(bingoCnt, bingoNum);
	}
	
	std::cout << "12���� ���� ��� �ϼ��ϼ̽��ϴ�." << std::endl;
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
	return 0;
}

void CreateMap(int (*bingoNum)[5])
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

int BingoCount(int (*bingoNum)[5], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			bingoNum[i][j] != 0 ? std::cout << bingoNum[i][j] : std::cout << "";

			j != 4 ? std::cout << "\t" : std::cout << std::endl;
		}
	}

	int bingoCnt = 0;

	// ������ ���� ī��Ʈ
	for (size_t i = 0; i < size; i++)
	{
		bool rowBingo = true;
		for (size_t j = 0; j < size; j++)
		{
			if (bingoNum[i][j] != 0)
			{
				rowBingo = false;
				break;
			}
		}
		if (rowBingo)
		{
			bingoCnt++;
		}
	}

	// ������ ���� ī��Ʈ
	for (size_t i = 0; i < size; i++)
	{
		bool columnBingo = true;
		for (size_t j = 0; j < size; j++)
		{
			if (bingoNum[j][i] != 0)
			{
				columnBingo = false;
				break;
			}
		}
		if (columnBingo)
		{
			bingoCnt++;
		}
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
		if (bingoNum[i][size - 1 - i] != 0)
		{
			crossBingo = false;
			break;
		}
	}
	if (crossBingo)
	{
		bingoCnt++;
	}

	return bingoCnt;
}

void PrintMap(int bingoCnt, int (*bingoNum)[5])
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

#pragma region �������ڵ� 2
// ������ �ڵ� 2

/*
	[������ �ľ��� ����]
	- 1 ~ 25 ���� �������� ��ġ�� 5*5 ������ ����
	- ���ڸ� �Է¹����� �׿� ���� ���ڰ� ��������, �������� �ϼ��� ������ ������ ���� �߰�
	[�ذ� ���̵��]
	- ������ �����ϴ� �Լ� / ���� �����ϴ� �Լ� / ������ ����ϴ� �Լ� / �÷����ϴ� �Լ�
	- 1) �����ϴ� �Լ��� �ʱ⿡ ������ �������ִ� �Լ�
	- 2) ���� �����ϴ� �Լ� - ���� ���� / ���� ���� / �밢�� ���� Ȯ���� ������ ��ȯ
	- 3) ������ �ܼ�â�� ���
	- 4) �Լ����� �̿��� �÷���
	- ���� ���� �����ϴ� ������ ���淡 ������ �� ä���߸� ���ߵ��� �����߽��ϴ� ^^
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#define MAP_WIDTH	5
#define MAP_HEIGHT	MAP_WIDTH
#define MAP_SIZE	(MAP_WIDTH * MAP_HEIGHT)	// ��ȣ ����߸� �������� �� ����. ��ȣ �����ִ� rand()���� ������������ ���� �����
#define BINGO		(MAP_WIDTH + MAP_HEIGHT + 2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void Create_Map(int(*arr)[MAP_WIDTH]);	// �� ����
int Bingo_Judgment(int(*arr)[MAP_WIDTH]);
void Print_Map(int(*arr)[MAP_WIDTH]);	//�� �� ������ �� ��������
void Play_Game();	//�����÷���

int main()
{
	Play_Game();
}

void Create_Map(int(*arr)[MAP_WIDTH])
{
	srand(time(NULL));

	int count = 1;
	int rand_nums[MAP_SIZE] = { 0 };

	while (count <= MAP_SIZE)
	{
		int index = rand() % MAP_SIZE;

		if (rand_nums[index] == 0)
		{
			rand_nums[index] = count;
			++count;
		}
	}

	count = MAP_SIZE;

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			arr[i][j] = rand_nums[--count];
		}
	}

}

void Print_Map(int(*arr)[MAP_WIDTH])
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (arr[i][j] == 0)
				printf("	");
			else
				printf("%d	", arr[i][j]);
		}
		printf("\n\n");
	}
}

int Bingo_Judgment(int(*arr)[MAP_WIDTH])
{
	bool is_bingo[BINGO] = { false };
	memset(is_bingo, true, sizeof(is_bingo));

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (arr[i][j] != 0)					// ���� ����
				is_bingo[i] = false;
			if (arr[j][i] != 0)					// ���� ����
				is_bingo[i + MAP_WIDTH] = false;

			if (i == j && arr[i][j] != 0)		// �밢��1 ����
				is_bingo[BINGO - 1] = false;
			if (i + j == MAP_WIDTH - 1 && arr[i][j] != 0)	// �밢��2 ����
				is_bingo[BINGO - 2] = false;
		}
	}

	int count_bingo = 0;

	for (int i = 0; i < BINGO; i++)
	{
		if (is_bingo[i] == true)
			++count_bingo;
	}

	return count_bingo;
}

void Play_Game()
{
	int bingo_map[MAP_HEIGHT][MAP_WIDTH] = { 0 };
	Create_Map(bingo_map, MAP_HEIGHT, MAP_WIDTH);

	int bingo_count = 0;
	while (bingo_count < BINGO)
	{
		Print_Map(bingo_map);

		int num;

		printf("���� %d���� ���� �ϼ��Ǿ����ϴ�.\n", bingo_count);
		printf("���ڸ� �Է����ּ��� : ");
		scanf("%d", &num);

		for (int i = 0; i < MAP_HEIGHT; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if (num == bingo_map[i][j])
				{
					bingo_map[i][j] = 0;
				}
			}
		}

		bingo_count = Bingo_Judgment(bingo_map);

		system("cls");
	}

	printf("%d���� ���� ��� �ϼ��ϼ̽��ϴ�.", bingo_count);

}
*/
#pragma endregion