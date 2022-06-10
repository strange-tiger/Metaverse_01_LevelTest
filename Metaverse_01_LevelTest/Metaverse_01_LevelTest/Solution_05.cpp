// 문제를 파악한 내용 : rand()의 사용과 중복의 탐색을 어떻게 하는가
// 해결 아이디어 : 로또 번호를 저장할 int 배열 lottoNumArr를 선언, 생성 숫자 개수 numCount 만큼 동적 할당. 그리고 저장된 중복되지 않는 숫자의 개수를 의미할 변수 queue를 선언하고 이 queue가 numCount에 달할 때까지 rand()를 반복한다. 여기서 randNum에 rand()에 최댓값으로 나머지를 구하고 최솟값인 1 만큼 더한 수를 저장하고, 이 수가 lottoNumArr에 존재하는지 queue만큼 반복해 비교, 존재하면 randNum에 0을 할당하고 randNum이 0이 아니어야만 queue가 증가하고 lottoNumArr에 randNum을 할당하도록 한다.
// 이런 단순한 비교 및 중복 처리가 숫자 개수가 늘어날수록 시간을 쓴다고 알고 있지만, 로또라면 상정한 번호의 개수가 그렇게 많지 않다고 생각하기에 이렇게 구현하였다.

#include <iostream>
#include <cstdlib>

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