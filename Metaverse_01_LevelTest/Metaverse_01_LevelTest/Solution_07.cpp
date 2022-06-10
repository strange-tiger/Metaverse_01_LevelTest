// 문제를 파악한 내용 : 수를 랜덤하게 배치하고 배치된 칸의 위치와 상태를 기록한다. 그리고 그 칸의 위치에 따라 빙고의 개수를 센다. 이 모든 건 반복되어 표시되어야 한다.
// 해결 아이디어 : vector로 1부터 25까지의 수를 기록한다. 이를 int의 2차원 배열에 임의 순서로 저장한다. 이중 vector를 사용하려했지만 익숙하지 않아 실패했다. 저장하는 과정에서 저장하면 vector에서 원소를 지워감으로써 중복을 피한다.

#include <iostream>
#include <vector>
#include <cstdlib>

//int BingoCount(int** bingoNum, int size);

int main()
{
	std::vector<int> v(25);

	for (size_t i = 0; i < 25; i++)
	{
		v[i] = i + 1;
	}

	std::srand(time(NULL));

	int bingoNum[5][5] = { 0 };
	for (size_t i = 0; i < 25; i++)
	{
		int tempNum = rand() % v.size();
		bingoNum[i / 5][i % 5] = v[tempNum];
		v.erase(v.begin() + tempNum);
	}

	int bingoCnt = 0;
	while (1)
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				bingoNum[i][j] != 0 ? std::cout << bingoNum[i][j] : std::cout << "";
				
				j != 4 ? std::cout << "\t" : std::cout << std::endl;
			}
		}
		
		int bingoCnt = 0;
		
		// 가로의 빙고 카운트
		for (size_t i = 0; i < 5; i++)
		{
			bool rowBingo = true;
			for (size_t j = 0; j < 5; j++)
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

		// 세로의 빙고 카운트
		for (size_t i = 0; i < 5; i++)
		{
			bool columnBingo = true;
			for (size_t j = 0; j < 5; j++)
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

		// 왼쪽 위 대각선의 빙고 카운트
		bool crossBingo = true;
		for (size_t i = 0; i < 5; i++)
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

		// 오른쪽 위 대각선의 빙고 카운트
		crossBingo = true;
		for (size_t i = 0; i < 5; i++)
		{
			if (bingoNum[i][4 - i] != 0)
			{
				crossBingo = false;
				break;
			}
		}
		if (crossBingo)
		{
			bingoCnt++;
		}

		std::cout << "현재 " << bingoCnt << "줄의 빙고가 완성되었습니다." << std::endl;
		std::cout << "숫자를 입력해 주세요 : ";

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
}