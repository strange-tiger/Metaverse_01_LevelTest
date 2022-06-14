#include <iostream>

using namespace std;

#define BLANK 0

int main()
{
	// 1. ������ ����
	bool isUsed[26] = { false };
	int board[5][5];
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

	int bingoCount = 0;
	while (bingoCount < 12)
	{
		system("cls");

		// 2. ������ ���
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
		cout << "���� " << bingoCount << "���� ���� �ϼ��Ǿ����ϴ�\n";

		// 3. ����� �Է� ����
		cout << "���ڸ� �Է����ּ��� : ";
		int input;
		cin >> input;

		// 3-1. ���Է� ó��
		if (input < 0 || input > 25)
		{
			// 2������ �ٽ�
			continue;
		}

		// 4. ������ ������Ʈ
		for (int r = 0; r < 5; ++r)
		{
			bool isExit = false;
			for (int c = 0; c < 5; ++c)
			{
				if (board[r][c] == input)
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

		// 5. ���� ������ ����.

		// - ������ ��� ���ڸ� ���� ��
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

		// - ������ ��� ���ڸ� ���� ��
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

		// - �밢���� ��� ���ڸ� ���� ��
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

		bingoCount = count;
	}
	// 6. 2������ �ٽ� �ݺ��Ѵ�.
}