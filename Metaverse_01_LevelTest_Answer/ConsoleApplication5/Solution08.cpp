#include <iostream>

using namespace std;

#define NOT_VISITED 0

int main()
{
	// 1. �迭 �����
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	int size;
	cin >> size;	

	int* arr = new int[size * size];
	memset(arr, 0, sizeof(int) * size * size);

	// 2. ������ �迭 ����
	// 2-1. ������ ������ �ʱ�ȭ
	int r = 0; // �������� ��ġ(y ��ǥ)
	int c = 0; // �������� ��ġ(x ��ǥ)
	int footstep = 1; // ���ڱ�
	enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
	Direction direction = DIR_RIGHT; // �����̰� �����̴� ����

	for (int i = 0; i < size * size; ++i)
	{
		// 2-2. ���ڱ��� �����.
		arr[r * size + c] = footstep;
		++footstep;

		// 2-3. �̵��� ��ġ�� ����Ѵ�.
		static const int dr[] = { 0, 1, 0, -1 };	
		static const int dc[] = { 1, 0, -1, 0 };

		int nr = r + dr[(int)direction]; 
		int nc = c + dc[(int)direction];
		
		// 2-4. �̵��� �������� �Ǻ��Ѵ�. 
		// 2-4-1. ���� ����� �� => r, c�� ��ġ�� [0, size)
		// 2-4-2. �̹� ������ ���� �� => arr[nr][nc] != 0
		if (nr < 0 || nr >= size || nc < 0 || nc >= size ||
			arr[nr * size + nc] != NOT_VISITED)
		{
			// 2-5. �̵��� �Ұ����ϹǷ� ���� ��ȯ�� �Ѵ�.
			direction = (Direction)((direction + 1) % DIR_MAX);

			// 2-6. ��ġ���� �ٽ� ����Ѵ�.
			nr = r + dr[(int)direction];
			nc = c + dc[(int)direction];
		}

		// 2-7. �̵��Ѵ�.
		r = nr;
		c = nc;
	}

	// 3. ���
	for (int r = 0; r < size; ++r)
	{
		for (int c = 0; c < size; ++c)
		{
			cout << arr[r * size + c] << "\t";
		}
		cout << "\n";
	}


	delete[] arr;
}