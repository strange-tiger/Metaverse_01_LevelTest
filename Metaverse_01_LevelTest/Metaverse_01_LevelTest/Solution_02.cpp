// ������ �ľ��� ���� : for�� �����ߴ°�
// �ذ� ���̵�� : for������ ������ �ΰ� �ݺ����� 3�� ���Ͽ� �ذ�

#include <iostream>

int main()
{
	for (int i = 3; i < 1000; i *= 3)
	{
		std::cout << i << std::endl;
	}
}