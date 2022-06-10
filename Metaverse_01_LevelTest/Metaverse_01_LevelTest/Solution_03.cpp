// 문제를 파악한 내용 : for문의 이해
// 해결 아이디어 : 이중 for문으로 줄마다 공백의 출력을 하나씩 줄이고, 별의 개수는 2개씩 늘려 구현

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