// ������ �ľ��� ���� : for���� ����
// �ذ� ���̵�� : ���� for������ �ٸ��� ������ ����� �ϳ��� ���̰�, ���� ������ 2���� �÷� ����

#include <iostream>

using namespace std;

int main()
{
	int lineNum = 5;

	// cin >> lineNum;

	for (int i = 0; i < lineNum; i++)
	{
		for (int j = lineNum - 1; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}