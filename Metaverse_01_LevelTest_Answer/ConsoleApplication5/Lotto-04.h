#pragma once
#pragma once

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

template <size_t MAX_DIGIT_COUNT>
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
		_digitCount = 0;
	}

	/// <summary>
	/// �ζ� ��ȣ�� �����Ѵ�. �̹� ������ ��ȣ�� �ִٸ� ����� ���� �����.
	/// </summary>
	/// <param name="maxValue">�ִ� ��Ȥ��</param>
	/// <param name="digitCount">���� ���� ����. �ִ� ���� ���ڴ� 100��</param>
	void Make(int maxValue, int digitCount)
	{
		// digitCount : [1, 100]
		// 1. digitCount�� �ּڰ�(1) ���� ���� ��
		// 1-1. std::min(digitCount, MAX_DIGIT_COUNT); => digitCount
		// 1-2. std::max(1, digitCount); => 1

		// 2. digitCount�� �ִ�(100) ���� Ŭ ��
		// 2-1. std::min(digitCount, MAX_DIGIT_COUNT); => MAX_DIGIT_COUNT
		// 2-2. std::max(1, MAX_DIGIT_COUNT); => MAX_DIGIT_COUNT

		// 3. digitCount�� �ּڰ��� �ִ� ���̿� ���� ��
		// 3-1. std::min(digitCount, MAX_DIGIT_COUNT); => digitCount
		// 3-2. std::max(1, digitCount); => digitCount

		digitCount = std::max(1, std::min(digitCount, MAX_DIGIT_COUNT));

		// 1 ~ maxValue ������ �� �� �ߺ����� �ʰ� digitCount��ŭ ����.
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
	int		_lotto[MAX_DIGIT_COUNT] = { 0 };
	int		_digitCount = 0;
};