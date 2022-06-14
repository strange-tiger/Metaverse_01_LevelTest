// 문제를 파악한 내용 : 수를 랜덤하게 배치하고 배치된 칸의 위치와 상태를 기록한다. 그리고 그 칸의 위치에 따라 빙고의 개수를 센다. 이 모든 건 반복되어 표시되어야 한다.
// 해결 아이디어 : vector로 1부터 25까지의 수를 기록한다. 이를 int의 2차원 배열에 임의 순서로 저장한다. 이중 vector를 사용하려했지만 익숙하지 않아 실패했다. 저장하는 과정에서 저장하면 vector에서 원소를 지워감으로써 중복을 피한다.

#pragma region 이진호_코드
//
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//
//void CreateMap(int (*bingoNum)[5]);
//int BingoCount(int (*bingoNum)[5], int size);
//void PrintMap(int bingoCnt, int (*bingoNum)[5]);
//
//int main()
//{
//	int bingoNum[5][5] = { 0 };
//	CreateMap(bingoNum);
//	
//	//std::vector<int> v(25);
//	//
//	//for (size_t i = 0; i < 25; i++)
//	//{
//	//	v[i] = i + 1;
//	//}
//	//
//	//std::srand(time(NULL));
//	//
//	//int bingoNum[5][5] = { 0 };
//	//for (size_t i = 0; i < 25; i++)
//	//{
//	//	int tempNum = rand() % v.size();
//	//	bingoNum[i / 5][i % 5] = v[tempNum];
//	//	v.erase(v.begin() + tempNum);
//	//}
//
//	//int bingoCnt = 0;
//	//while (bingoCnt < 5 * 2 + 2)
//	//{
//	//	for (size_t i = 0; i < 5; i++)
//	//	{
//	//		for (size_t j = 0; j < 5; j++)
//	//		{
//	//			bingoNum[i][j] != 0 ? std::cout << bingoNum[i][j] : std::cout << "";
//	//			
//	//			j != 4 ? std::cout << "\t" : std::cout << std::endl;
//	//		}
//	//	}
//	//	
//	//	int bingoCnt = 0;
//	//	
//	//	// 가로의 빙고 카운트
//	//	for (size_t i = 0; i < 5; i++)
//	//	{
//	//		bool rowBingo = true;
//	//		for (size_t j = 0; j < 5; j++)
//	//		{
//	//			if (bingoNum[i][j] != 0)
//	//			{
//	//				rowBingo = false;
//	//				break;
//	//			}
//	//		}
//	//		if (rowBingo)
//	//		{
//	//			bingoCnt++;
//	//		}
//	//	}
//	//
//	//	// 세로의 빙고 카운트
//	//	for (size_t i = 0; i < 5; i++)
//	//	{
//	//		bool columnBingo = true;
//	//		for (size_t j = 0; j < 5; j++)
//	//		{
//	//			if (bingoNum[j][i] != 0)
//	//			{
//	//				columnBingo = false;
//	//				break;
//	//			}
//	//		}
//	//		if (columnBingo)
//	//		{
//	//			bingoCnt++;
//	//		}
//	//	}
//	//
//	//	// 왼쪽 위 대각선의 빙고 카운트
//	//	bool crossBingo = true;
//	//	for (size_t i = 0; i < 5; i++)
//	//	{
//	//		if (bingoNum[i][i] != 0)
//	//		{
//	//			crossBingo = false;
//	//			break;
//	//		}
//	//	}
//	//	if (crossBingo)
//	//	{
//	//		bingoCnt++;
//	//	}
//	//
//	//	// 오른쪽 위 대각선의 빙고 카운트
//	//	crossBingo = true;
//	//	for (size_t i = 0; i < 5; i++)
//	//	{
//	//		if (bingoNum[i][4 - i] != 0)
//	//		{
//	//			crossBingo = false;
//	//			break;
//	//		}
//	//	}
//	//	if (crossBingo)
//	//	{
//	//		bingoCnt++;
//	//	}
//
//	int bingoCnt = 0;
//	while (bingoCnt < 10)
//	{
//		bingoCnt = BingoCount(bingoNum, 5);
//
//		PrintMap(bingoCnt, bingoNum);
//	}
//	
//	std::cout << "12줄의 빙고를 모두 완성하셨습니다." << std::endl;
//	/*std::cout << "현재 " << bingoCnt << "줄의 빙고가 완성되었습니다." << std::endl;
//	std::cout << "숫자를 입력해 주세요 : ";
//
//	int inputNum;
//	std::cin >> inputNum;
//	for (size_t i = 0; i < 5; i++)
//	{
//		for (size_t j = 0; j < 5; j++)
//		{
//			if (inputNum == bingoNum[i][j])
//			{
//				bingoNum[i][j] = 0;
//				break;
//			}
//		}
//	}
//	system("cls");
//}*/
//	return 0;
//}
//
//void CreateMap(int (*bingoNum)[5])
//{
//	std::vector<int> v(25);
//
//	for (size_t i = 0; i < 25; i++)
//	{
//		v[i] = i + 1;
//	}
//
//	std::srand(time(NULL));
//
//	for (size_t i = 0; i < 25; i++)
//	{
//		int tempNum = rand() % v.size();
//		bingoNum[i / 5][i % 5] = v[tempNum];
//		v.erase(v.begin() + tempNum);
//	}
//}
//
//int BingoCount(int (*bingoNum)[5], int size)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		for (size_t j = 0; j < size; j++)
//		{
//			bingoNum[i][j] != 0 ? std::cout << bingoNum[i][j] : std::cout << "";
//
//			j != 4 ? std::cout << "\t" : std::cout << std::endl;
//		}
//	}
//
//	int bingoCnt = 0;
//
//	// 가로의 빙고 카운트
//	for (size_t i = 0; i < size; i++)
//	{
//		bool rowBingo = true;
//		for (size_t j = 0; j < size; j++)
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
//	// 세로의 빙고 카운트
//	for (size_t i = 0; i < size; i++)
//	{
//		bool columnBingo = true;
//		for (size_t j = 0; j < size; j++)
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
//	// 왼쪽 위 대각선의 빙고 카운트
//	bool crossBingo = true;
//	for (size_t i = 0; i < size; i++)
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
//	// 오른쪽 위 대각선의 빙고 카운트
//	crossBingo = true;
//	for (size_t i = 0; i < size; i++)
//	{
//		if (bingoNum[i][size - 1 - i] != 0)
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
//	return bingoCnt;
//}
//
//void PrintMap(int bingoCnt, int (*bingoNum)[5])
//{
//	std::cout << "현재 " << bingoCnt << "줄의 빙고가 완성되었습니다." << std::endl;
//	std::cout << "숫자를 입력해 주세요 : ";
//
//	int inputNum;
//	std::cin >> inputNum;
//	for (size_t i = 0; i < 5; i++)
//	{
//		for (size_t j = 0; j < 5; j++)
//		{
//			if (inputNum == bingoNum[i][j])
//			{
//				bingoNum[i][j] = 0;
//				break;
//			}
//		}
//	}
//	system("cls");
//}
//
#pragma endregion

#pragma region 전지윤코드
// 전지윤 코드
///*
//	[문제를 파악한 내용]
//	- 1 ~ 25 까지 랜덤으로 배치된 5*5 빙고판 생성
//	- 숫자를 입력받으면 그에 대한 숫자가 지워지고, 빙고줄이 완성될 때마다 빙고줄 개수 추가
//	[해결 아이디어]
//	- 빙고판 생성하는 함수 / 빙고 판정하는 함수 / 빙고판 출력하는 함수 / 플레이하는 함수
//	- 1) 생성하는 함수는 초기에 빙고판 생성해주는 함수
//	- 2) 빙고 판정하는 함수 - 가로 판정 / 세로 판정 / 대각선 판정 확인해 빙고줄 반환
//	- 3) 빙고판 콘솔창에 출력
//	- 4) 함수들을 이용해 플레이
//	- 따로 게임 종료하는 조건이 없길래 빙고줄 다 채워야만 멈추도록 설계했습니다 ^^
//*/
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdbool.h>
//
//void Create_Map(int(*arr)[5], int width_n, int height_n);	// 맵 생성
//int Judgment(int(*arr)[5], int width_n, int height_n);
//void Print_Map(int(*arr)[5], int width_n, int height_n);	//한 턴 지날때 맵 갱신해줌
//void Play_Game();	//게임플레이
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
//	bool diagonal_judgment1 = true;	// 대각선1 판정
//	bool diagonal_judgment2 = true;	// 대각선2 판정
//	for (int i = 0; i < arrNum1; i++)
//	{
//		bool horizontal_judgment = true;	// 가로 판정
//		bool vertical_judgment = true;		// 세로 판정
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
//		printf("현재 %d줄의 빙고가 완성되었습니다.\n", bingo);
//		printf("숫자를 입력해주세요 : ");
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
//	printf("%d줄의 빙고를 모두 완성하셨습니다.", bingo);
//
//}
#pragma endregion

#pragma region 전지윤코드2
// 전지윤 코드 2

/*
	[문제를 파악한 내용]
	- 1 ~ 25 까지 랜덤으로 배치된 5*5 빙고판 생성
	- 숫자를 입력받으면 그에 대한 숫자가 지워지고, 빙고줄이 완성될 때마다 빙고줄 개수 추가
	[해결 아이디어]
	- 빙고판 생성하는 함수 / 빙고 판정하는 함수 / 빙고판 출력하는 함수 / 플레이하는 함수
	- 1) 생성하는 함수는 초기에 빙고판 생성해주는 함수
	- 2) 빙고 판정하는 함수 - 가로 판정 / 세로 판정 / 대각선 판정 확인해 빙고줄 반환
	- 3) 빙고판 콘솔창에 출력
	- 4) 함수들을 이용해 플레이
	- 따로 게임 종료하는 조건이 없길래 빙고줄 다 채워야만 멈추도록 설계했습니다 ^^
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#define MAP_WIDTH	5
#define MAP_HEIGHT	MAP_WIDTH
#define MAP_SIZE	(MAP_WIDTH * MAP_HEIGHT)	// 괄호 쳐줘야만 랜덤값이 잘 나옴. 괄호 안쳐주니 rand()와의 나머지연산이 먼저 적용됨
#define BINGO		(MAP_WIDTH + MAP_HEIGHT + 2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void Create_Map(int(*arr)[MAP_WIDTH]);	// 맵 생성
int Bingo_Judgment(int(*arr)[MAP_WIDTH]);
void Print_Map(int(*arr)[MAP_WIDTH]);	//한 턴 지날때 맵 갱신해줌
void Play_Game();	//게임플레이

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
			if (arr[i][j] != 0)					// 가로 판정
				is_bingo[i] = false;
			if (arr[j][i] != 0)					// 세로 판정
				is_bingo[i + MAP_WIDTH] = false;

			if (i == j && arr[i][j] != 0)		// 대각선1 판정
				is_bingo[BINGO - 1] = false;
			if (i + j == MAP_WIDTH - 1 && arr[i][j] != 0)	// 대각선2 판정
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

		printf("현재 %d줄의 빙고가 완성되었습니다.\n", bingo_count);
		printf("숫자를 입력해주세요 : ");
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

	printf("%d줄의 빙고를 모두 완성하셨습니다.", bingo_count);

}
*/
#pragma endregion

#pragma region 최선문교수_코드
//#include <iostream>
//
//using namespace std;
//
//#define BLANK 0
//
//int main()
//{
//	// 1. 빙고판 세팅
//	bool isUsed[26] = { false };
//	int board[5][5];
//	for (int r = 0; r < 5; ++r)
//	{
//		for (int c = 0; c < 5; ++c)
//		{
//			int n = 0;
//			do
//			{
//				n = 1 + rand() % 25;
//			} while (isUsed[n]);
//
//			board[r][c] = n;
//			isUsed[n] = true;
//		}
//	}
//
//	int bingoCount = 0;
//	while (bingoCount < 12)
//	{
//		system("cls");
//
//		// 2. 빙고판 출력
//		for (int r = 0; r < 5; ++r)
//		{
//			for (int c = 0; c < 5; ++c)
//			{
//				if (board[r][c] == BLANK)
//				{
//					cout << "\t";
//				}
//				else
//				{
//					cout << board[r][c] << "\t";
//				}
//			}
//
//			cout << "\n";
//		}
//		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다\n";
//
//		// 3. 사용자 입력 받음
//		cout << "숫자를 입력해주세요 : ";
//		int input;
//		cin >> input;
//
//		// 3-1. 오입력 처리
//		if (input < 0 || input > 25)
//		{
//			// 2번부터 다시
//			continue;
//		}
//
//		// 4. 빙고판 업데이트
//		for (int r = 0; r < 5; ++r)
//		{
//			bool isExit = false;
//			for (int c = 0; c < 5; ++c)
//			{
//				if (board[r][c] == input)
//				{
//					board[r][c] = BLANK;
//					isExit = true;
//
//					break;
//				}
//			}
//
//			if (isExit)
//			{
//				break;
//			}
//		}
//
//		// 5. 빙고 개수를 샌다.
//
//		// - 가로의 모든 숫자를 지운 것
//		int count = 0;
//
//		for (int r = 0; r < 5; ++r)
//		{
//			bool isBingo = true;
//			for (int c = 0; c < 5; ++c)
//			{
//				if (board[r][c] != BLANK)
//				{
//					isBingo = false;
//
//					break;
//				}
//			}
//			if (isBingo)
//			{
//				++count;
//			}
//		}
//
//		// - 세로의 모든 숫자를 지운 것
//		for (int r = 0; r < 5; ++r)
//		{
//			bool isBingo = true;
//			for (int c = 0; c < 5; ++c)
//			{
//				if (board[c][r] != BLANK)
//				{
//					isBingo = false;
//
//					break;
//				}
//			}
//			if (isBingo)
//			{
//				++count;
//			}
//		}
//
//		// - 대각선의 모든 숫자를 지운 것
//		// [0][0] / [1][1] / [2][2] / [3][3] / [4][4]
//		{
//			bool isBingo = true;
//			for (int i = 0; i < 5; ++i)
//			{
//				if (board[i][i] != BLANK)
//				{
//					isBingo = false;
//					break;
//				}
//			}
//
//			if (isBingo)
//			{
//				++count;
//			}
//		}
//
//		// [0][4] / [1][3] / [2][2] / [3][1] / [4][0]
//		{
//			bool isBingo = true;
//			for (int i = 0; i < 5; ++i)
//			{
//				if (board[i][4 - i] != BLANK)
//				{
//					isBingo = false;
//
//					break;
//				}
//			}
//
//			if (isBingo)
//			{
//				++count;
//			}
//		}
//
//		bingoCount = count;
//	}
//	// 6. 2번부터 다시 반복한다.
//}
#pragma endregion

#pragma region 모듈화_클래스

#include <iostream>

using namespace std;

#define BLANK 0

bool isUsed[26] = { false };

class Bingo
{
public:

	void Make()
	{
		for (int r = 0; r < 5; ++r)
		{
			for (int c = 0; c < 5; ++c)
			{
				int n = 0;
				do
				{
					n = 1 + rand() % 25;
				} while (isUsed[n]);

				board[r][c] = n;
				isUsed[n] = true;
			}
		}
	}

	void Print()
	{
		for (int r = 0; r < 5; ++r)
		{
			for (int c = 0; c < 5; ++c)
			{
				if (board[r][c] == BLANK)
				{
					cout << "\t";
				}
				else
				{
					cout << board[r][c] << "\t";
				}
			}

			cout << "\n";
		}
		cout << "현재 " << Count << "줄의 빙고가 완성되었습니다\n";
	}

	int Input()
	{
		cout << "숫자를 입력해주세요 : ";
		cin >> _input;
		
		return _input;
	}

	void Update()
	{
		for (int r = 0; r < 5; ++r)
		{
			bool isExit = false;
			for (int c = 0; c < 5; ++c)
			{
				if (board[r][c] == _input)
				{
					board[r][c] = BLANK;
					isExit = true;

					break;
				}
			}

			if (isExit)
			{
				break;
			}
		}
	}

	void SetCount()
	{
		// - 가로의 모든 숫자를 지운 것
		int count = 0;

		for (int r = 0; r < 5; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; ++c)
			{
				if (board[r][c] != BLANK)
				{
					isBingo = false;

					break;
				}
			}
			if (isBingo)
			{
				++count;
			}
		}

		// - 세로의 모든 숫자를 지운 것
		for (int r = 0; r < 5; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; ++c)
			{
				if (board[c][r] != BLANK)
				{
					isBingo = false;

					break;
				}
			}
			if (isBingo)
			{
				++count;
			}
		}

		// - 대각선의 모든 숫자를 지운 것
		// [0][0] / [1][1] / [2][2] / [3][3] / [4][4]
		{
			bool isBingo = true;
			for (int i = 0; i < 5; ++i)
			{
				if (board[i][i] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}

		// [0][4] / [1][3] / [2][2] / [3][1] / [4][0]
		{
			bool isBingo = true;
			for (int i = 0; i < 5; ++i)
			{
				if (board[i][4 - i] != BLANK)
				{
					isBingo = false;

					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}

		Count = count;
	}

	int GetCount()
	{
		return Count;
	}
private:
	int board[5][5] = { 0 };
	int Count = 0;
	int _input = 0;
};

int main()
{
	Bingo bingo;

	// 1. 빙고판 세팅
	bingo.Make();
	
	do
	{
		system("cls");

		// 2. 빙고판 출력
		bingo.Print();

		// 3. 사용자 입력 받음
		int input = bingo.Input();

		// 3-1. 오입력 처리
		if (input < 0 || input > 25)
		{
			// 2번부터 다시
			continue;
		}

		// 4. 빙고판 업데이트
		bingo.Update();

		// 5. 빙고 개수를 샌다.
		bingo.SetCount();
	}
	while (bingo.GetCount() < 12);
	// 6. 2번부터 다시 반복한다.

	return 0;
}

#pragma endregion