// 문제를 파악한 내용 : for문 이해했는가
// 해결 아이디어 : for문으로 조건을 두고 반복마다 3을 곱하여 해결

#include <iostream>

int main()
{
	for (int i = 3; i < 1000; i *= 3)
	{
		std::cout << i << std::endl;
	}
}