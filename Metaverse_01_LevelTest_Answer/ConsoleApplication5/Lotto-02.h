#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

class LimitedLotto
{
public:
	LimitedLotto() = default;
	LimitedLotto(const LimitedLotto& other) = delete;
	LimitedLotto& operator=(const LimitedLotto& other) = delete;
	~LimitedLotto()
	{
		Clear();
	}

	/// <summary>
	/// �����͸� �����.
	/// </summary>
	void Clear()
	{
		delete[] _lotto;
		_lotto = nullptr;

		_digitCount = 0;
	}

	/// <summary>
	/// �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
	/// </summary>
	/// <param name="maxValue">�ִ� ��ȣ��</param>
	/// <param name="digitCount">���� ���� ����</param>
	void Make(int maxValue, int digitCount)
	{
		// 1. �̹� ������ ��ȣ�� �����ش�.
		Clear();

		// 1 ~ maxValue ������ �� �� �ߺ����� �ʰ� digitCount��ŭ ����.
		_lotto = new int[digitCount];
		_digitCount = digitCount;

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
					if (candidate == _lotto[i])
					{
						isExist = true;

						break;
					}
				}
			} while (isExist);

			// 2-2. �ߺ��� �ƴϸ�? �����͸� �����Ѵ�.
			_lotto[curPos] = candidate;
		}
	}

	/// <summary>
	/// �ζ� ��ȣ�� ����Ѵ�. ���࿡ ������ ��ȣ�� ���ٸ� �ƹ��͵� ������� �ʴ´�.
	/// </summary>
	void Print()
	{
		for (int i = 0; i < _digitCount; ++i)
		{
			std::cout << _lotto[i] << " ";
		}
		std::cout << "\n";
	}

private:
	int*	_lotto = nullptr;
	int		_digitCount = 0;
	int		_maxDigitCount = 0;
};