// 문제를 파악한 내용 : 배열의 동적 할당, 달팽이 배열의 패턴 파악
// 해결 아이디어 : way와 wayCount, shellNum이라는 변수들로 제어문에서 제어하여 계산 및 배열 할당 등등

/*
#include <iostream>

int main()
{
	int arrSize;
	std::cout << "배열의 크기를 입력하세요 : ";
	std::cin >> arrSize;

	// 2차원 배열의 동적 할당
	int** arr = new int*[arrSize];
	for (size_t i = 0; i < arrSize; i++)
	{
		arr[i] = new int[arrSize];
	}

	int shellNum = (arrSize + 1) / 2;					// 배열 패턴의 반복 -> shellNum (껍데기 갯수)마다 way가 4가지 존재
	int way = 0;										// 패턴의 종류 -> 어느 방향으로 좌표가 이동하는가, 오른쪽 / 아래 / 왼쪽 / 위 의 4가지 패턴 존재
	int wayCount = 0;									// 좌표를 이동하는 횟수
	for (size_t i = 0; i < arrSize * arrSize; i++)		// 수를 arrSize * arrSize까지 할당한다.
	{
		int n = i + 1;
		
		int fixCoord_1 = (arrSize + 1) / 2 - shellNum;	// 첫 고정 좌표 값 : way == 0, 3 일때 각각 행과 열의 고정 좌표 값
		int fixCoord_2 = arrSize - fixCoord_1 - 1;		// 두번째 고정 좌표 값 : way == 1, 2 일때 각각 열과 행의 고정 좌표 값

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

	// 출력
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
#pragma region 전지윤코드
// 전지윤 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int num;

	printf("배열의 크기를 입력하시오.\n : ");
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

	// 출력
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