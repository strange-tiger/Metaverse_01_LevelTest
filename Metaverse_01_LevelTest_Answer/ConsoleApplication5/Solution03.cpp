#include <iostream>

using namespace std;

int main()
{
	// line : 0 - 1 - 2 - 3 - 4
	// 3. �� ���� ���� 5��
	for (int line = 0; line < 5; ++line)
	{
		// 1. ��ĭ�� 4 - 3 - 2 - 1 - 0
		for (int spaceCount = 0; spaceCount < 4 - line; ++spaceCount)
		{
			cout << " ";
		}

		// 2. ���� ������ 1 - 3 - 5 - 7 - 9
		for (int starCount = 0; starCount < line * 2 + 1; ++starCount)
		{
			cout << "*";
		}
		
		cout << "\n";
	}

	return 0;
}