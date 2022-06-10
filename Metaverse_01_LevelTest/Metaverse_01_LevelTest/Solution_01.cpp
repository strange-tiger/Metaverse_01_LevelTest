// 문제 : 포인터, 레퍼런스로 외부에서 선언된 두 정수형 변수의 값을 서로 바꾸는 Swap 함수를 각각 구현
// 문제 파악 내용 : 포인터와 레퍼런스의 차이
// 해결 아이디어 : 1. int temp를 이용, swap
//				  2. 간접 참조를 위해, 포인터는 역참조를 해야하나 레퍼런스는 안 한다.

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
