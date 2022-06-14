// ������ �ľ��� ���� : rand()�� ���� �ߺ��� Ž���� ��� �ϴ°�
// �ذ� ���̵�� : �ζ� ��ȣ�� ������ int �迭 lottoNumArr�� ����, ���� ���� ���� numCount ��ŭ ���� �Ҵ�. �׸��� ����� �ߺ����� �ʴ� ������ ������ �ǹ��� ���� queue�� �����ϰ� �� queue�� numCount�� ���� ������ rand()�� �ݺ��Ѵ�. ���⼭ randNum�� rand()�� �ִ����� �������� ���ϰ� �ּڰ��� 1 ��ŭ ���� ���� �����ϰ�, �� ���� lottoNumArr�� �����ϴ��� queue��ŭ �ݺ��� ��, �����ϸ� randNum�� 0�� �Ҵ��ϰ� randNum�� 0�� �ƴϾ�߸� queue�� �����ϰ� lottoNumArr�� randNum�� �Ҵ��ϵ��� �Ѵ�.
// �̷� �ܼ��� �� �� �ߺ� ó���� ���� ������ �þ���� �ð��� ���ٰ� �˰� ������, �ζǶ�� ������ ��ȣ�� ������ �׷��� ���� �ʴٰ� �����ϱ⿡ �̷��� �����Ͽ���.

#include <iostream>
#include <cstdlib>
/*
int main()
{
	int maxNum;										// �ִ� ��ȣ��
	int numCount;									// ���� ���� ����
	std::cin >> maxNum;
	std::cin >> numCount;
	int* lottoNumArr = new int[numCount];			// �ߺ����� �ʴ� �ζ� ��ȣ ���� �迭, ���� �Ҵ�
	int queue = 0;									// ���� ���� �迭�� ����Ǿ��ִ� ���� ���� 

	std::srand(time(NULL));							// rand �õ� ����

	while (queue < numCount)						// queue == numCount�� �� ������ �ݺ�
	{
		int randNum = std::rand() % maxNum + 1;		// �ζ� ��ȣ �ĺ� : maxNum�� ���� �ʰ� 1 �̻��� ������ �� ����
		if (queue)									// queue�� 0�� �ƴ϶��
		{
			for (size_t j = 0; j < queue; j++)		// queue��ŭ �ݺ�
			{
				if (randNum == *(lottoNumArr + j))	// ���� �ζ� ��ȣ �迭�� �ĺ� ��ȣ�� ��
				{
					randNum = 0;					// �ߺ��Ǹ� 0 �Ҵ�
					break;
				}
			}
		}

		if (randNum)								// randNum�� 0�� �ƴ϶��
		{
			*(lottoNumArr + queue) = randNum;		// �ζ� ��ȣ �迭�� queue��°�� randNum
			queue++;								// queue ����
		}
	}

	// ���
	for (size_t i = 0; i < numCount; i++)
	{
		std::cout << *(lottoNumArr + i);
		if (i != numCount - 1)std::cout << ", ";
	}
	std::cout << std::endl;

	// ��ȯ
	delete[] lottoNumArr;
}
*/

#pragma region ���ȭ_�Լ�

/// <summary>
/// �ζ� ��ȣ�� �����.
/// </summary>
/// <param name="maxValue">�ִ� ��ȣ��</param>
/// <param name="digitCount">���� ���� ����</param>
/// <returns>�ζ� ��ȣ��</returns>
/*
int* MakeLotto(int maxValue, int digitCount);

using namespace std;

int main()
{
	// �Է� : �ִ� ��ȣ��, ���� ���� ����
	int maxNum;										// �ִ� ��ȣ��
	int numCount;									// ���� ���� ����
	std::cin >> maxNum;
	std::cin >> numCount;

	// ó�� : �ζ� ����
	int* lotto = MakeLotto(maxNum, numCount);		// ����? ������
	// Lotto lotto(maxNum, numCount);

	// Lotto lotto;									// �ξ� ������ ����
	// lotto.Make(maxNum, numCount);

	// ��� : �ζ� ��ȣ ���
	// lotto.Print();
	for (size_t i = 0; i < numCount; i++)
	{
		std::cout << *(lotto + i);
		if (i != numCount - 1)std::cout << ", ";
	}
	std::cout << std::endl;

	// ��ȯ
	delete[] lotto;

	return 0;
}

int* MakeLotto(int maxNum, int numCount)
{
	int* lottoNumArr = new int[numCount];			// �ߺ����� �ʴ� �ζ� ��ȣ ���� �迭, ���� �Ҵ�
	int queue = 0;									// ���� ���� �迭�� ����Ǿ��ִ� ���� ���� 

	std::srand(time(NULL));							// rand �õ� ����

	while (queue < numCount)						// queue == numCount�� �� ������ �ݺ�
	{
		int randNum = std::rand() % maxNum + 1;		// �ζ� ��ȣ �ĺ� : maxNum�� ���� �ʰ� 1 �̻��� ������ �� ����
		if (queue)									// queue�� 0�� �ƴ϶��
		{
			for (size_t j = 0; j < queue; j++)		// queue��ŭ �ݺ�
			{
				if (randNum == *(lottoNumArr + j))	// ���� �ζ� ��ȣ �迭�� �ĺ� ��ȣ�� ��
				{
					randNum = 0;					// �ߺ��Ǹ� 0 �Ҵ�
					break;
				}
			}
		}

		if (randNum)								// randNum�� 0�� �ƴ϶��
		{
			*(lottoNumArr + queue) = randNum;		// �ζ� ��ȣ �迭�� queue��°�� randNum
			queue++;								// queue ����
		}
	}

}
*/
#pragma endregion

#pragma region ���ȭ_Ŭ����

// Lotto Ÿ�� class Lotto
// Make() : �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
// Print() : �ζ� ��ȣ�� ����Ѵ�. ���࿡ ������ ��ȣ�� ���ٸ� �ƹ��͵� ������� �ʴ´�.

class Lotto
{
public:
	// ������ / �Ҹ��� / ���� ������ / ���� �Ҵ� ������
	Lotto() = default;
	Lotto(const Lotto& other) = delete;
	Lotto& operator=(const Lotto& other) = delete;
	
	Lotto(int maxValue, int digitCount)
		: _maxValue(maxValue), _digitCount(digitCount), _lotto(nullptr)
	{
		_lotto = new int[_digitCount];
	}

	~Lotto()
	{
		Clear();
	}

	/// <summary>
	/// �����͸� �����.
	/// </summary>
	void Clear()
	{
		delete[] _lotto;	// ������ �ص�, ������ �� �޸𸮸� ����Ű�� �ִ�.
		_lotto = nullptr;	// �׷��⿡ �ʱ�ȭ�� ���� �ʿ䰡 �ִ�.

		_maxValue = 0;
		_digitCount = 0;
	}

	/// <summary>
	/// �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
	/// </summary>
	/// <param name="maxValue"></param>
	/// <param name="digitCount"></param>
	void Make(int maxValue, int digitCount)
	{
		// 1. �̹� ������ ��ȣ�� �����ش�.
		Clear();

		_maxValue = maxValue;
		_digitCount = digitCount;

		_lotto = new int[_digitCount];					// �ߺ����� �ʴ� �ζ� ��ȣ ���� �迭, ���� �Ҵ�
		int queue = 0;									// ���� ���� �迭�� ����Ǿ��ִ� ���� ���� 

		std::srand(time(NULL));							// rand �õ� ����

		while (queue < _digitCount)						// queue == numCount�� �� ������ �ݺ�
		{
			int randNum = std::rand() % _maxValue + 1;		// �ζ� ��ȣ �ĺ� : maxNum�� ���� �ʰ� 1 �̻��� ������ �� ����
			if (queue)									// queue�� 0�� �ƴ϶��
			{
				for (size_t j = 0; j < queue; j++)		// queue��ŭ �ݺ�
				{
					if (randNum == _lotto[j])			// ���� �ζ� ��ȣ �迭�� �ĺ� ��ȣ�� ��
					{
						randNum = 0;					// �ߺ��Ǹ� 0 �Ҵ�
						break;
					}
				}
			}

			if (randNum)								// randNum�� 0�� �ƴ϶��
			{
				_lotto[queue] = randNum;				// �ζ� ��ȣ �迭�� queue��°�� randNum
				queue++;								// queue ����
			}
		}
	}

	/// <summary>
	/// �ζ� ��ȣ�� ����Ѵ�. ���࿡ ������ ��ȣ�� ���ٸ� �ƹ��͵� ������� �ʴ´�.
	/// </summary>
	void Print()
	{
		for (size_t i = 0; i < _digitCount; i++)
		{
			std::cout << *(_lotto + i);
			if (i != _digitCount - 1)std::cout << ", ";
		}
		std::cout << std::endl;
	}

private:
	int*	_lotto = nullptr;
	int		_digitCount = 0;
	int		_maxValue = 0;
};

int main()
{
	// �Է� : �ִ� ��ȣ��, ���� ���� ����
	int maxNum;										// �ִ� ��ȣ��
	std::cin >> maxNum;

	int numCount;									// ���� ���� ����
	std::cin >> numCount;

	// ó�� : �ζ� ����
	Lotto lotto;
	lotto.Make(maxNum, numCount);

	// ��� : �ζ� ��ȣ ���
	lotto.Print();

	// ��ȯ
	// lotto.~Lotto();

	return 0;
}

// ���� �Ҵ��� ������. ��, �޸𸮸� �������� ������ ���� ������.
// 1. �Ҵ��� �ߴµ� ������ ���ߴ�. => �޸� ���� (Memory Leak)
// 2. �̹� ������ �޸𸮿� ���ؼ� �� �����ߴ�. => ���� ���� (Double Free)
//		- �̹� ������ �޸𸮸� ����Ű�� ������ => ��۸� ������ (Dangling Pointer)
// 3. �ʹ� ���� �����ߴ�. => ���� ����, ������ ����, �ʹ� ���� ���� (Premature Free)

#pragma endregion