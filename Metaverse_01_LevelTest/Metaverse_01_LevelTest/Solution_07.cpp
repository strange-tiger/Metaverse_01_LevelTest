// ������ �ľ��� ���� : ���� �����ϰ� ��ġ�ϰ� ��ġ�� ĭ�� ��ġ�� ���¸� ����Ѵ�. �׸��� �� ĭ�� ��ġ�� ���� ������ ������ ����. �� ��� �� �ݺ��Ǿ� ǥ�õǾ�� �Ѵ�.
// �ذ� ���̵�� : vector�� 1���� 25������ ���� ����Ѵ�. �̸� int�� 2���� �迭�� ���� ������ �����Ѵ�. ���� vector�� ����Ϸ������� �ͼ����� �ʾ� �����ߴ�. �����ϴ� �������� �����ϸ� vector���� ���Ҹ� ���������ν� �ߺ��� ���Ѵ�.

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
		
		// ������ ���� ī��Ʈ
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

		// ������ ���� ī��Ʈ
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

		// ���� �� �밢���� ���� ī��Ʈ
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

		// ������ �� �밢���� ���� ī��Ʈ
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

		std::cout << "���� " << bingoCnt << "���� ���� �ϼ��Ǿ����ϴ�." << std::endl;
		std::cout << "���ڸ� �Է��� �ּ��� : ";

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