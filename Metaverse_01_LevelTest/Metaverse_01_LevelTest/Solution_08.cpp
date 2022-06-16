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
//// 전지윤 코드
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int num;
//
//	printf("배열의 크기를 입력하시오.\n : ");
//	scanf("%d", &num);
//
//	int arr[100][100] = { 0 };
//	int count = 0;
//	arr[0][0] = count;
//
//	int n = 1, x = 0, y = -1;
//	for (int i = 2 * num; i >= 2; --i)
//	{
//		for (int j = 1; j <= i / 2; ++j)
//		{
//			count++;
//
//			switch (n)
//			{
//			case 1:
//				++y;
//				break;
//			case 2:
//				++x;
//				break;
//			case 3:
//				--y;
//				break;
//			case 4:
//				--x;
//				break;
//			}
//
//			arr[x][y] = count;
//
//		}
//
//		if (n == 4)
//		{
//			n = 1;
//		}
//		else
//		{
//			++n;
//		}
//	}
//
//	// 출력
//	for (int i = 0; i < num; i++)
//	{
//		for (int j = 0; j < num; j++)
//		{
//			printf("\t%d\t", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}
#pragma endregion

#pragma region 최선문교수코드
// 최선문 교수 코드
// Solution_08 : Answer
//
//#include <iostream>
//#define NOT_VISITED 0
//
//using namespace std;
//
//int main()
//{
//    // 1. 배열 만들기
//    cout << "배열의 크기를 입력하세요 : ";
//    int size;
//    cin >> size;
//    /*
//    int** arr = new int* [size];
//    for (int i = 0; i < size; ++i)
//    {
//        arr[i] = new int[size];
//    }
//    */
//    // 위의 할당법에는 문제가 있다. -> 일반적인 2차원 배열은 연속적이지만,
//    // 이 할당은 연속적으로 할당 되지 않는다.
//    //
//    // 문제점
//    //
//    // 1. 반환의 불편함
//    /*
//    for (int i = 0; i < size; ++i)
//    {
//        delete[] arr[i];
//    }
//    delete[] arr;
//    */
//    // 2. 중요 : 메모리의 파편화
//    // => 데이터 사이에 빈 공간이 생기고, 그 사이의 공간은 연속적이지 않기에 할당이 어려워진다. 
//    //
//    // 그렇기에 되도록 1차원 배열로 동적 할당한다.
//
//    int* arr = new int[size * size];
//    memset(arr, 0, sizeof(int) * size * size);
//
//    // 2. 달팽이 배열 세팅
//    // 2-1. 달팽이 데이터 초기화
//    int r = 0;
//    int c = 0;
//    int footstep = 1;
//    enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
//    Direction direction = DIR_RIGHT;
//
//    for (int i = 0; i < size * size; ++i)
//    {
//        // 2-2 달팽이 움직임 : 발자국을 남긴다.
//        arr[r * size + c] = footstep;
//        ++footstep;
//
//        // 2-3. 다음 칸으로 이동한다. 이동할 위치를 계산한다.
//        // Lookup Table
//        static const int dr[] = { 0, 1, 0, -1 };
//        static const int dc[] = { 1, 0, -1, 0 };
//
//        int nr = r + dr[(int)direction];
//        int nc = c + dc[(int)direction];
//
//        // 위의 네 줄의 코드로 아래의 switch문을 대체한다.
//        // // 2-3. 다음 칸으로 이동한다.
//        // switch(direction)
//        // {
//        // // 2-3-1. 오른쪽으로 갈 때 => c += 1
//        // case DIR_RIGHT:
//        //     c += 1;
//        //     break;
//        // // 2-3-2. 밑으로 갈 때 => r += 1
//        // case DIR_DOWN:
//        //     r += 1;
//        //     break;
//        // // 2-3-3. 왼쪽으로 갈 때 => c -= 1
//        // case DIR_LEFT:
//        //     c -= 1;
//        //     break;
//        // // 2-3-4. 위로 갈 때 => r -= 1
//        // case DIR_UP:
//        //     r -= 1;
//        //     break;
//        // }
//
//        // 2-4. 이동이 가능한지 판별한다.
//        // 2-4-1. 벽에 닿았을 때 => r, c의 위치가 [0, size)
//        // 2-4-2. 이미 지나온 곳일 때 => arr[nr][nc] != 0
//        if (nr < 0 || nr >= size || nc < 0 || nc >= size
//            || arr[nr * size + nc] != NOT_VISITED)
//        {
//            // 2-5. 이동이 불가능하므로 방향 전환을 한다.
//            direction = (Direction)((direction + 1) % DIR_MAX);
//            // DIR_MAX의 쓰임새 : 모듈러를 사용한 UP -> RIGHT 전환
//
//            // 2-6. 
//            nr = r + dr[(int)direction];
//            nc = c + dc[(int)direction];
//        }
//
//        // 2-7. 이동한다.
//        r = nr;
//        c = nc;
//    }
//    // 3. 출력
//    for (int r = 0; r < size; ++r)
//    {
//        for (int c = 0; c < size; ++c)
//        {
//            cout << arr[r * size + c] << "\t";
//        }
//        cout << "\n";
//    }
//
//    delete[] arr;
//}
#pragma endregion

#pragma region 모듈화_클래스
//#include <iostream>
//
//using namespace std;
//
//class SnailArr
//{
//    static const int NOT_VISITED = 0;
//public:
//    SnailArr() = default;
//    SnailArr(int size)
//    {
//        _size = size;
//    }
//
//    SnailArr(const SnailArr& other)
//    {
//        *_arr = *other._arr;
//        _size = other._size;
//        _r = other._r;
//        _c = other._c;
//    }
//    SnailArr& operator=(const SnailArr& other)
//    {
//        *_arr = *other._arr;
//        _size = other._size;
//        _r = other._r;
//        _c = other._c;
//    }
//
//    ~SnailArr()
//    {
//        Clear();
//    }
//
//    void Clear()
//    {
//        delete[] _arr;
//        _arr = nullptr;
//
//        _size = 0;
//        _r = 0;
//        _c = 0;
//    }
//    void Make(int size)
//    {
//        size = size;
//        int footstep = 1;
//        Direction direction = DIR_RIGHT;
//
//        _arr = new int[size * size];
//        memset(_arr, 0, sizeof(int) * size * size);
//
//        for (int i = 0; i < size * size; ++i)
//        {
//            // 2-2 달팽이 움직임 : 발자국을 남긴다.
//            _arr[_r * size + _c] = footstep;
//            ++footstep;
//
//            // 2-3. 다음 칸으로 이동한다. 이동할 위치를 계산한다.
//            // Lookup Table
//            static const int dr[] = { 0, 1, 0, -1 };
//            static const int dc[] = { 1, 0, -1, 0 };
//
//            int nr = _r + dr[(int)direction];
//            int nc = _c + dc[(int)direction];
//
//            // 2-4. 이동이 가능한지 판별한다.
//            // 2-4-1. 벽에 닿았을 때 => r, c의 위치가 [0, size)
//            // 2-4-2. 이미 지나온 곳일 때 => arr[nr][nc] != 0
//            if (nr < 0 || nr >= size || nc < 0 || nc >= size
//                || _arr[nr * size + nc] != NOT_VISITED)
//            {
//                // 2-5. 이동이 불가능하므로 방향 전환을 한다.
//                direction = (Direction)((direction + 1) % DIR_MAX);
//                // DIR_MAX의 쓰임새 : 모듈러를 사용한 UP -> RIGHT 전환
//
//                // 2-6. 
//                nr = _r + dr[(int)direction];
//                nc = _c + dc[(int)direction];
//            }
//
//            // 2-7. 이동한다.
//            _r = nr;
//            _c = nc;
//        }
//    }
//
//    void Print()
//    {
//        for (int r = 0; r < _size; ++r)
//        {
//            for (int c = 0; c < _size; ++c)
//            {
//                cout << _arr[r * _size + c] << "\t";
//            }
//            cout << "\n";
//        }
//    }
//private:
//    int* _arr = nullptr;
//    int _size = 0;
//    int _r = 0;
//    int _c = 0;
//    enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
//};
//
//int main()
//{
//    // 1. 배열 만들기
//    cout << "배열의 크기를 입력하세요 : ";
//    int size;
//    cin >> size;
//    
//    SnailArr snailArr;
//    snailArr.Make(size);
//
//    snailArr.Print();
//
//    return 0;
//}

#pragma endregion

#pragma region 최선문교수_모듈화
#include <iostream>

using namespace std;

class Snail
{
    static const int NOT_VISITED = 0;
    enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
public:
    void MoveOn(int* ground, int size)
    {
        int _footstep = 1;

        for (int i = 0; i < size * size; ++i)
        {
            // 2-2 달팽이 움직임 : 발자국을 남긴다.
            ground[_r * size + _c] = _footstep;
            ++_footstep;

            // 2-3. 다음 칸으로 이동한다. 이동할 위치를 계산한다.
            // Lookup Table
            static const int dr[] = { 0, 1, 0, -1 };
            static const int dc[] = { 1, 0, -1, 0 };

            int nr = _r + dr[(int)_direction];
            int nc = _c + dc[(int)_direction];

            // 2-4. 이동이 가능한지 판별한다.
            // 2-4-1. 벽에 닿았을 때 => r, c의 위치가 [0, size)
            // 2-4-2. 이미 지나온 곳일 때 => arr[nr][nc] != 0
            if (nr < 0 || nr >= size || nc < 0 || nc >= size
                || ground[nr * size + nc] != NOT_VISITED)
            {
                // 2-5. 이동이 불가능하므로 방향 전환을 한다.
                _direction = (Direction)((_direction + 1) % DIR_MAX);
                // DIR_MAX의 쓰임새 : 모듈러를 사용한 UP -> RIGHT 전환

                // 2-6. 
                nr = _r + dr[(int)_direction];
                nc = _c + dc[(int)_direction];
            }

            // 2-7. 이동한다.
            _r = nr;
            _c = nc;
        }
    }

private:
    int _footstep = 0;
    int _r = 0;
    int _c = 0;
    Direction _direction = DIR_RIGHT;
};

int main()
{
    // 1. 배열 만들기
    cout << "배열의 크기를 입력하세요 : ";
    int size;
    cin >> size;

    int* arr = new int[size * size];
    memset(arr, 0, sizeof(int) * size * size);

    Snail snail;
    snail.MoveOn(arr, size);

	for (int r = 0; r < size; ++r)
	{
		for (int c = 0; c < size; ++c)
		{
			cout << arr[r * size + c] << "\t";
		}
		cout << "\n";
	}

	delete[] arr;

    return 0;
}

#pragma endregion