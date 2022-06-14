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
	/// 데이터를 지운다.
	/// </summary>
	void Clear()
	{
		delete[] _lotto;
		_lotto = nullptr;

		_digitCount = 0;
	}

	/// <summary>
	/// 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
	/// </summary>
	/// <param name="maxValue">최대 번호값</param>
	/// <param name="digitCount">생성 숫자 개수</param>
	void Make(int maxValue, int digitCount)
	{
		// 1. 이미 생성된 번호를 지워준다.
		Clear();

		// 1 ~ maxValue 사이의 값 중 중복되지 않게 digitCount만큼 뽑음.
		_lotto = new int[digitCount];
		_digitCount = digitCount;

		srand(time(nullptr));

		// 로또 번호 정하기
		// 3. 1번부터 digitCount만큼 반복한다.
		for (int curPos = 0; curPos < digitCount; ++curPos)
		{
			int candidate = 0;
			bool isExist = false;

			do
			{
				// 1. [1, maxValue] 사이의 값으로 무작위로 뽑는다.
				candidate = 1 + rand() % maxValue;
				isExist = false;

				// 2. 중복인지 확인한다. => 이미 나온 값인지 확인한다.
				for (int i = 0; i < curPos; ++i)
				{
					// 2-1. 중복이면? 1번을 다시 수행한다.
					if (candidate == _lotto[i])
					{
						isExist = true;

						break;
					}
				}
			} while (isExist);

			// 2-2. 중복이 아니면? 데이터를 저장한다.
			_lotto[curPos] = candidate;
		}
	}

	/// <summary>
	/// 로또 번호를 출력한다. 만약에 생성된 번호가 없다면 아무것도 출력하지 않는다.
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