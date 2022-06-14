#include <iostream>

using namespace std;

/// <summary>
/// �ζ� ��ȣ�� �����.
/// </summary>
/// <param name="maxValue">�ִ� ��ȣ��</param>
/// <param name="digitCount">���� ���� ����</param>
/// <returns>�ζ� ��ȣ�� (���� �Ҵ��) </returns>
int* MakeLotto(int maxValue, int digitCount);

int main()
{
	// �Է� : �ִ� ��ȣ���� ���� ���� ���� �Է� �޴´�.
	cout << "�ִ� ��ȣ ���� �Է��ϼ���. : ";
	int maxValue;
	cin >> maxValue;

	cout << "������ ������ ������ �Է��ϼ���. : ";
	int digitCount;
	cin >> digitCount;

	// ó�� : �ζ� ���� 
	int* lotto = MakeLotto(maxValue, digitCount); // ����? ������

	// ��� : �ζ� ��ȣ ���
	for (int i = 0; i < digitCount; ++i)
	{
		cout << lotto[i] << " ";
	}

	delete[] lotto;

	return 0;
}

int* MakeLotto(int maxValue, int digitCount)
{
	// 1 ~ maxValue ������ �� �� �ߺ����� �ʰ� digitCount��ŭ ����.
	int* lotto = new int[digitCount];

	srand(time(nullptr));

	// �ζ� ��ȣ ���ϱ�
	// 3. 1������ digitCount��ŭ �ݺ��Ѵ�.
	for (int curPos = 0; curPos < digitCount; ++curPos)
	{
		int candidate = 0;
		bool isExist = false;

		do
		{
			// 1. [1, maxValue] ������ ������ �������� �̴´�.
			candidate = 1 + rand() % maxValue;
			isExist = false;

			// 2. �ߺ����� Ȯ���Ѵ�. => �̹� ���� ������ Ȯ���Ѵ�.
			for (int i = 0; i < curPos; ++i)
			{
				// 2-1. �ߺ��̸�? 1���� �ٽ� �����Ѵ�.
				if (candidate == lotto[i])
				{
					isExist = true;

					break;
				}
			}
		} while (isExist);

		// 2-2. �ߺ��� �ƴϸ�? �����͸� �����Ѵ�.
		lotto[curPos] = candidate;
	}

	return lotto;
}
