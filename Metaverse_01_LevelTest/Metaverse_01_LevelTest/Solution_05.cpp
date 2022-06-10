// ������ �ľ��� ���� : rand()�� ���� �ߺ��� Ž���� ��� �ϴ°�
// �ذ� ���̵�� : �ζ� ��ȣ�� ������ int �迭 lottoNumArr�� ����, ���� ���� ���� numCount ��ŭ ���� �Ҵ�. �׸��� ����� �ߺ����� �ʴ� ������ ������ �ǹ��� ���� queue�� �����ϰ� �� queue�� numCount�� ���� ������ rand()�� �ݺ��Ѵ�. ���⼭ randNum�� rand()�� �ִ����� �������� ���ϰ� �ּڰ��� 1 ��ŭ ���� ���� �����ϰ�, �� ���� lottoNumArr�� �����ϴ��� queue��ŭ �ݺ��� ��, �����ϸ� randNum�� 0�� �Ҵ��ϰ� randNum�� 0�� �ƴϾ�߸� queue�� �����ϰ� lottoNumArr�� randNum�� �Ҵ��ϵ��� �Ѵ�.
// �̷� �ܼ��� �� �� �ߺ� ó���� ���� ������ �þ���� �ð��� ���ٰ� �˰� ������, �ζǶ�� ������ ��ȣ�� ������ �׷��� ���� �ʴٰ� �����ϱ⿡ �̷��� �����Ͽ���.

#include <iostream>
#include <cstdlib>

int main()
{
	int maxNum;										// �ִ� ��ȣ��
	int numCount;									// ���� ���� ����
	std::cin >> maxNum;
	std::cin >> numCount;
	int* lottoNumArr = new int[numCount];			// �ߺ����� �ʴ� �ζ� ��ȣ ���� �迭, ���� �Ҵ�
	int queue = 0;									// ���� ���� �迭�� ����Ǿ��ִ� ���� ���� 

	std::srand(time(NULL));							// rand �õ� ����

	while (queue < numCount)						// queue == numCount�� �� ������ �ݺ�
	{
		int randNum = std::rand() % maxNum + 1;		// �ζ� ��ȣ �ĺ� : maxNum�� ���� �ʰ� 1 �̻��� ������ �� ����
		if (queue)									// queue�� 0�� �ƴ϶��
		{
			for (size_t j = 0; j < queue; j++)		// queue��ŭ �ݺ�
			{
				if (randNum == *(lottoNumArr + j))	// ���� �ζ� ��ȣ �迭�� �ĺ� ��ȣ�� ��
				{
					randNum = 0;					// �ߺ��Ǹ� 0 �Ҵ�
					break;
				}
			}
		}

		if (randNum)								// randNum�� 0�� �ƴ϶��
		{
			*(lottoNumArr + queue) = randNum;		// �ζ� ��ȣ �迭�� queue��°�� randNum
			queue++;								// queue ����
		}
	}

	// ���
	for (size_t i = 0; i < numCount; i++)
	{
		std::cout << *(lottoNumArr + i);
		if (i != numCount - 1)std::cout << ", ";
	}
	std::cout << std::endl;

	// ��ȯ
	delete[] lottoNumArr;
}