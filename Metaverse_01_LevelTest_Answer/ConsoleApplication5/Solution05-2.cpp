#include <iostream>

#include "Lotto-04.h"

using namespace std;

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
	LimitedLotto<24> lotto;
	LimitedLotto<50> lotto2;
	LimitedLotto<15> lotto3;

	lotto.Make(maxValue, digitCount);

	// ��� : �ζ� ��ȣ ���
	lotto.Print();

	return 0;
}
