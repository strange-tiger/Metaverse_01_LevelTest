#include <iostream>

#include "Lotto-04.h"

using namespace std;

int main()
{
	// 입력 : 최대 번호값과 생성 숫자 개수 입력 받는다.
	cout << "최대 번호 값을 입력하세요. : ";
	int maxValue;
	cin >> maxValue;

	cout << "생성할 숫자의 개수를 입력하세요. : ";
	int digitCount;
	cin >> digitCount;

	// 처리 : 로또 생성 
	LimitedLotto<24> lotto;
	LimitedLotto<50> lotto2;
	LimitedLotto<15> lotto3;

	lotto.Make(maxValue, digitCount);

	// 출력 : 로또 번호 출력
	lotto.Print();

	return 0;
}
