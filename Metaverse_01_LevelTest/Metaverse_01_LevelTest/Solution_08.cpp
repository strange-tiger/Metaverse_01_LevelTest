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
//// ������ �ڵ�
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	int num;
//
//	printf("�迭�� ũ�⸦ �Է��Ͻÿ�.\n : ");
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
//	// ���
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

#pragma region �ּ��������ڵ�
// �ּ��� ���� �ڵ�
// Solution_08 : Answer
//
//#include <iostream>
//#define NOT_VISITED 0
//
//using namespace std;
//
//int main()
//{
//    // 1. �迭 �����
//    cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
//    int size;
//    cin >> size;
//    /*
//    int** arr = new int* [size];
//    for (int i = 0; i < size; ++i)
//    {
//        arr[i] = new int[size];
//    }
//    */
//    // ���� �Ҵ������ ������ �ִ�. -> �Ϲ����� 2���� �迭�� ������������,
//    // �� �Ҵ��� ���������� �Ҵ� ���� �ʴ´�.
//    //
//    // ������
//    //
//    // 1. ��ȯ�� ������
//    /*
//    for (int i = 0; i < size; ++i)
//    {
//        delete[] arr[i];
//    }
//    delete[] arr;
//    */
//    // 2. �߿� : �޸��� ����ȭ
//    // => ������ ���̿� �� ������ �����, �� ������ ������ ���������� �ʱ⿡ �Ҵ��� ���������. 
//    //
//    // �׷��⿡ �ǵ��� 1���� �迭�� ���� �Ҵ��Ѵ�.
//
//    int* arr = new int[size * size];
//    memset(arr, 0, sizeof(int) * size * size);
//
//    // 2. ������ �迭 ����
//    // 2-1. ������ ������ �ʱ�ȭ
//    int r = 0;
//    int c = 0;
//    int footstep = 1;
//    enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
//    Direction direction = DIR_RIGHT;
//
//    for (int i = 0; i < size * size; ++i)
//    {
//        // 2-2 ������ ������ : ���ڱ��� �����.
//        arr[r * size + c] = footstep;
//        ++footstep;
//
//        // 2-3. ���� ĭ���� �̵��Ѵ�. �̵��� ��ġ�� ����Ѵ�.
//        // Lookup Table
//        static const int dr[] = { 0, 1, 0, -1 };
//        static const int dc[] = { 1, 0, -1, 0 };
//
//        int nr = r + dr[(int)direction];
//        int nc = c + dc[(int)direction];
//
//        // ���� �� ���� �ڵ�� �Ʒ��� switch���� ��ü�Ѵ�.
//        // // 2-3. ���� ĭ���� �̵��Ѵ�.
//        // switch(direction)
//        // {
//        // // 2-3-1. ���������� �� �� => c += 1
//        // case DIR_RIGHT:
//        //     c += 1;
//        //     break;
//        // // 2-3-2. ������ �� �� => r += 1
//        // case DIR_DOWN:
//        //     r += 1;
//        //     break;
//        // // 2-3-3. �������� �� �� => c -= 1
//        // case DIR_LEFT:
//        //     c -= 1;
//        //     break;
//        // // 2-3-4. ���� �� �� => r -= 1
//        // case DIR_UP:
//        //     r -= 1;
//        //     break;
//        // }
//
//        // 2-4. �̵��� �������� �Ǻ��Ѵ�.
//        // 2-4-1. ���� ����� �� => r, c�� ��ġ�� [0, size)
//        // 2-4-2. �̹� ������ ���� �� => arr[nr][nc] != 0
//        if (nr < 0 || nr >= size || nc < 0 || nc >= size
//            || arr[nr * size + nc] != NOT_VISITED)
//        {
//            // 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
//            direction = (Direction)((direction + 1) % DIR_MAX);
//            // DIR_MAX�� ���ӻ� : ��ⷯ�� ����� UP -> RIGHT ��ȯ
//
//            // 2-6. 
//            nr = r + dr[(int)direction];
//            nc = c + dc[(int)direction];
//        }
//
//        // 2-7. �̵��Ѵ�.
//        r = nr;
//        c = nc;
//    }
//    // 3. ���
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

#pragma region ���ȭ_Ŭ����
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
//            // 2-2 ������ ������ : ���ڱ��� �����.
//            _arr[_r * size + _c] = footstep;
//            ++footstep;
//
//            // 2-3. ���� ĭ���� �̵��Ѵ�. �̵��� ��ġ�� ����Ѵ�.
//            // Lookup Table
//            static const int dr[] = { 0, 1, 0, -1 };
//            static const int dc[] = { 1, 0, -1, 0 };
//
//            int nr = _r + dr[(int)direction];
//            int nc = _c + dc[(int)direction];
//
//            // 2-4. �̵��� �������� �Ǻ��Ѵ�.
//            // 2-4-1. ���� ����� �� => r, c�� ��ġ�� [0, size)
//            // 2-4-2. �̹� ������ ���� �� => arr[nr][nc] != 0
//            if (nr < 0 || nr >= size || nc < 0 || nc >= size
//                || _arr[nr * size + nc] != NOT_VISITED)
//            {
//                // 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
//                direction = (Direction)((direction + 1) % DIR_MAX);
//                // DIR_MAX�� ���ӻ� : ��ⷯ�� ����� UP -> RIGHT ��ȯ
//
//                // 2-6. 
//                nr = _r + dr[(int)direction];
//                nc = _c + dc[(int)direction];
//            }
//
//            // 2-7. �̵��Ѵ�.
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
//    // 1. �迭 �����
//    cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
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

#pragma region �ּ�������_���ȭ
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
            // 2-2 ������ ������ : ���ڱ��� �����.
            ground[_r * size + _c] = _footstep;
            ++_footstep;

            // 2-3. ���� ĭ���� �̵��Ѵ�. �̵��� ��ġ�� ����Ѵ�.
            // Lookup Table
            static const int dr[] = { 0, 1, 0, -1 };
            static const int dc[] = { 1, 0, -1, 0 };

            int nr = _r + dr[(int)_direction];
            int nc = _c + dc[(int)_direction];

            // 2-4. �̵��� �������� �Ǻ��Ѵ�.
            // 2-4-1. ���� ����� �� => r, c�� ��ġ�� [0, size)
            // 2-4-2. �̹� ������ ���� �� => arr[nr][nc] != 0
            if (nr < 0 || nr >= size || nc < 0 || nc >= size
                || ground[nr * size + nc] != NOT_VISITED)
            {
                // 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
                _direction = (Direction)((_direction + 1) % DIR_MAX);
                // DIR_MAX�� ���ӻ� : ��ⷯ�� ����� UP -> RIGHT ��ȯ

                // 2-6. 
                nr = _r + dr[(int)_direction];
                nc = _c + dc[(int)_direction];
            }

            // 2-7. �̵��Ѵ�.
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
    // 1. �迭 �����
    cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
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