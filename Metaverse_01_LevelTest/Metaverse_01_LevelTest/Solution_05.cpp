// 문제를 파악한 내용 : rand()의 사용과 중복의 탐색을 어떻게 하는가
// 해결 아이디어 : 로또 번호를 저장할 int 배열 lottoNumArr를 선언, 생성 숫자 개수 numCount 만큼 동적 할당. 그리고 저장된 중복되지 않는 숫자의 개수를 의미할 변수 queue를 선언하고 이 queue가 numCount에 달할 때까지 rand()를 반복한다. 여기서 randNum에 rand()에 최댓값으로 나머지를 구하고 최솟값인 1 만큼 더한 수를 저장하고, 이 수가 lottoNumArr에 존재하는지 queue만큼 반복해 비교, 존재하면 randNum에 0을 할당하고 randNum이 0이 아니어야만 queue가 증가하고 lottoNumArr에 randNum을 할당하도록 한다.
// 이런 단순한 비교 및 중복 처리가 숫자 개수가 늘어날수록 시간을 쓴다고 알고 있지만, 로또라면 상정한 번호의 개수가 그렇게 많지 않다고 생각하기에 이렇게 구현하였다.

#include <iostream>
#include <cstdlib>
/*
int main()
{
	int maxNum;										// 최대 번호값
	int numCount;									// 생성 숫자 개수
	std::cin >> maxNum;
	std::cin >> numCount;
	int* lottoNumArr = new int[numCount];			// 중복되지 않는 로또 번호 저장 배열, 동적 할당
	int queue = 0;									// 현재 위의 배열에 저장되어있는 수의 개수 

	std::srand(time(NULL));							// rand 시드 설정

	while (queue < numCount)						// queue == numCount가 될 때까지 반복
	{
		int randNum = std::rand() % maxNum + 1;		// 로또 번호 후보 : maxNum을 넘지 않고 1 이상인 임의의 수 생성
		if (queue)									// queue가 0이 아니라면
		{
			for (size_t j = 0; j < queue; j++)		// queue만큼 반복
			{
				if (randNum == *(lottoNumArr + j))	// 현재 로또 번호 배열과 후보 번호를 비교
				{
					randNum = 0;					// 중복되면 0 할당
					break;
				}
			}
		}

		if (randNum)								// randNum이 0이 아니라면
		{
			*(lottoNumArr + queue) = randNum;		// 로또 번호 배열의 queue번째는 randNum
			queue++;								// queue 증가
		}
	}

	// 출력
	for (size_t i = 0; i < numCount; i++)
	{
		std::cout << *(lottoNumArr + i);
		if (i != numCount - 1)std::cout << ", ";
	}
	std::cout << std::endl;

	// 반환
	delete[] lottoNumArr;
}
*/

#pragma region 모듈화_함수

/// <summary>
/// 로또 번호를 만든다.
/// </summary>
/// <param name="maxValue">최대 번호값</param>
/// <param name="digitCount">생성 숫자 개수</param>
/// <returns>로또 번호들</returns>
/*
int* MakeLotto(int maxValue, int digitCount);

using namespace std;

int main()
{
	// 입력 : 최대 번호값, 생성 숫자 개수
	int maxNum;										// 최대 번호값
	int numCount;									// 생성 숫자 개수
	std::cin >> maxNum;
	std::cin >> numCount;

	// 처리 : 로또 생성
	int* lotto = MakeLotto(maxNum, numCount);		// 생성? 생성자
	// Lotto lotto(maxNum, numCount);

	// Lotto lotto;									// 훨씬 유연한 설계
	// lotto.Make(maxNum, numCount);

	// 출력 : 로또 번호 출력
	// lotto.Print();
	for (size_t i = 0; i < numCount; i++)
	{
		std::cout << *(lotto + i);
		if (i != numCount - 1)std::cout << ", ";
	}
	std::cout << std::endl;

	// 반환
	delete[] lotto;

	return 0;
}

int* MakeLotto(int maxNum, int numCount)
{
	int* lottoNumArr = new int[numCount];			// 중복되지 않는 로또 번호 저장 배열, 동적 할당
	int queue = 0;									// 현재 위의 배열에 저장되어있는 수의 개수 

	std::srand(time(NULL));							// rand 시드 설정

	while (queue < numCount)						// queue == numCount가 될 때까지 반복
	{
		int randNum = std::rand() % maxNum + 1;		// 로또 번호 후보 : maxNum을 넘지 않고 1 이상인 임의의 수 생성
		if (queue)									// queue가 0이 아니라면
		{
			for (size_t j = 0; j < queue; j++)		// queue만큼 반복
			{
				if (randNum == *(lottoNumArr + j))	// 현재 로또 번호 배열과 후보 번호를 비교
				{
					randNum = 0;					// 중복되면 0 할당
					break;
				}
			}
		}

		if (randNum)								// randNum이 0이 아니라면
		{
			*(lottoNumArr + queue) = randNum;		// 로또 번호 배열의 queue번째는 randNum
			queue++;								// queue 증가
		}
	}

}
*/
#pragma endregion

#pragma region 모듈화_클래스

// Lotto 타입 class Lotto
// Make() : 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
// Print() : 로또 번호를 출력한다. 만약에 생성된 번호가 없다면 아무것도 출력하지 않는다.

class Lotto
{
public:
	// 생성자 / 소멸자 / 복사 생성자 / 복사 할당 연산자
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
	/// 데이터를 지운다.
	/// </summary>
	void Clear()
	{
		delete[] _lotto;	// 해제를 해도, 여전히 그 메모리를 가리키고 있다.
		_lotto = nullptr;	// 그렇기에 초기화를 해줄 필요가 있다.

		_maxValue = 0;
		_digitCount = 0;
	}

	/// <summary>
	/// 로또 번호를 생성한다. 이미 생성된 번호가 있다면 지우고 새로 만든다.
	/// </summary>
	/// <param name="maxValue"></param>
	/// <param name="digitCount"></param>
	void Make(int maxValue, int digitCount)
	{
		// 1. 이미 생성된 번호를 지워준다.
		Clear();

		_maxValue = maxValue;
		_digitCount = digitCount;

		_lotto = new int[_digitCount];					// 중복되지 않는 로또 번호 저장 배열, 동적 할당
		int queue = 0;									// 현재 위의 배열에 저장되어있는 수의 개수 

		std::srand(time(NULL));							// rand 시드 설정

		while (queue < _digitCount)						// queue == numCount가 될 때까지 반복
		{
			int randNum = std::rand() % _maxValue + 1;		// 로또 번호 후보 : maxNum을 넘지 않고 1 이상인 임의의 수 생성
			if (queue)									// queue가 0이 아니라면
			{
				for (size_t j = 0; j < queue; j++)		// queue만큼 반복
				{
					if (randNum == _lotto[j])			// 현재 로또 번호 배열과 후보 번호를 비교
					{
						randNum = 0;					// 중복되면 0 할당
						break;
					}
				}
			}

			if (randNum)								// randNum이 0이 아니라면
			{
				_lotto[queue] = randNum;				// 로또 번호 배열의 queue번째는 randNum
				queue++;								// queue 증가
			}
		}
	}

	/// <summary>
	/// 로또 번호를 출력한다. 만약에 생성된 번호가 없다면 아무것도 출력하지 않는다.
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
	// 입력 : 최대 번호값, 생성 숫자 개수
	int maxNum;										// 최대 번호값
	std::cin >> maxNum;

	int numCount;									// 생성 숫자 개수
	std::cin >> numCount;

	// 처리 : 로또 생성
	Lotto lotto;
	lotto.Make(maxNum, numCount);

	// 출력 : 로또 번호 출력
	lotto.Print();

	// 반환
	// lotto.~Lotto();

	return 0;
}

// 동적 할당의 문제점. 즉, 메모리를 수동으로 관리할 때의 문제점.
// 1. 할당은 했는데 해제를 안했다. => 메모리 누수 (Memory Leak)
// 2. 이미 해제한 메모리에 대해서 또 해제했다. => 이중 해제 (Double Free)
//		- 이미 해제한 메모리를 가리키는 포인터 => 댕글링 포인터 (Dangling Pointer)
// 3. 너무 빨리 해제했다. => 조기 해제, 조숙한 해제, 너무 급한 해제 (Premature Free)

#pragma endregion