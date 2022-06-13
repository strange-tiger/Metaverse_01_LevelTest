// ������ �ľ��� ���� : 53���� ���ڿ� �� 14���� ������ �ߺ����� �ʴ� ���ڿ��� �̴� ����
// �ذ� ���̵�� : ���� ������ ������ 53�� ���� �� 14���� ���Ƿ� �ߺ����� �ʰ� �̰�, ��ȣ�� 52������ ���� ��ⷯ�� ��Ī�� ����Ѵ�. 53�� ��Ŀ�� �Ѵ�.
#include <iostream>
#include <cstdlib>

int* RandNum(int maxNum, int numCount);	// ������ ���� �� �ڿ����� �迭 : Solution_05�� Ǯ�̸� �Լ���
void CardPrint(int cardNum);			// ���� ī�� ���� �������� switch������ ī�带 ����ϴ� �Լ�

int main()
{
	int* numArr = RandNum(53, 14);		// Solution_05�� Ǯ�̸� �Լ��� �Ͽ� ������ 14�� �� ����
	
	// Player 1 ���
	std::cout << "Player 1 : ";
	for (size_t i = 0; i < 7; i++)
	{
		int cardNum = *(numArr + i);

		if (cardNum == 53)				// 53�� ��Ŀ�� �Ѵ�.
		{
			std::cout << "Joker";
		}
		else
		{
			CardPrint(cardNum);			// ���� ī�� ���� �������� ī�带 ���
		}

		if (i != 6)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;

	// Player 2 ���
	std::cout << "Player 2 : ";
	for (size_t i = 7; i < 14; i++)
	{
		int cardNum = *(numArr + i);

		if (cardNum == 53)				// 53�� ��Ŀ�� �Ѵ�.
		{
			std::cout << "Joker";
		}
		else
		{
			CardPrint(cardNum);			// ���� ī�� ���� �������� ī�带 ���
		}

		if (i != 13)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;

	// ��ȯ
	delete[] numArr;
}

int* RandNum(int maxNum, int numCount)
{
	int* numArr = new int[numCount];				// �ߺ����� �ʴ� �ζ� ��ȣ ���� �迭, ���� �Ҵ�
	int queue = 0;									// ���� ���� �迭�� ����Ǿ��ִ� ���� ���� 

	std::srand(time(NULL));							// rand �õ� ����

	while (queue < numCount)						// queue == numCount�� �� ������ �ݺ�
	{
		int randNum = std::rand() % maxNum + 1;		// �ζ� ��ȣ �ĺ� : maxNum�� ���� �ʰ� 1 �̻��� ������ �� ����
		if (queue)									// queue�� 0�� �ƴ϶��
		{
			for (size_t j = 0; j < queue; j++)		// queue��ŭ �ݺ�
			{
				if (randNum == *(numArr + j))	// ���� �ζ� ��ȣ �迭�� �ĺ� ��ȣ�� ��
				{
					randNum = 0;					// �ߺ��Ǹ� 0 �Ҵ�
					break;
				}
			}
		}

		if (randNum)								// randNum�� 0�� �ƴ϶��
		{
			*(numArr + queue) = randNum;		// �ζ� ��ȣ �迭�� queue��°�� randNum
			queue++;								// queue ����
		}
	}

	return numArr;
}

void CardPrint(int cardNum)
{
	// ��ȣ ���
	switch (cardNum % 4)
	{
	case 0:
		std::cout << "��";
		break;
	case 1:
		std::cout << "��";
		break;
	case 2:
		std::cout << "��";
		break;
	case 3:
		std::cout << "��";
		break;
	}

	// �� (ī�� ��) ���
	switch (cardNum % 13 + 1)
	{
	case 1:
		std::cout << "A";
		break;
	case 11:
		std::cout << "J";
		break;
	case 12:
		std::cout << "Q";
		break;
	case 13:
		std::cout << "K";
		break;
	default:
		std::cout << cardNum % 13 + 1;
		break;
	}
}

#pragma region �������ڵ�
// ������ �ڵ�
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//void CreatCardDeck(int* pCard);
//void PrintCardDeck(int num);
//
//#define play 14
//
//int main()
//{
//	srand(time(NULL));
//
//	int pCard[play] = { 0 };
//	//CardArray(pCard);
//
//	CreatCardDeck(pCard);
//
//	for (int i = 0; i < 14; i++)
//	{
//		PrintCardDeck(pCard[i]);
//		if (i % 7 == 6)
//			printf("\n");
//		else
//			printf(", ");
//	}
//}
//
//void CreatCardDeck(int* pCard)
//{
//	int count = 0;
//
//	while (count < 14)
//	{
//		bool isNoCard = true;
//		int randCard = rand() % 53;
//
//		for (int i = count; i >= 0; --i)
//		{
//			if (pCard[count] == randCard)
//			{
//				isNoCard = false;
//				break;
//			}
//		}
//
//		if (isNoCard)
//		{
//			pCard[count] = randCard;
//			++count;
//		}
//	}
//}
//
//void PrintCardDeck(int num)
//{
//	switch (num / 13)
//	{
//	case 0:
//		printf("��");
//		break;
//	case 1:
//		printf("��");
//		break;
//	case 2:
//		printf("��");
//		break;
//	case 3:
//		printf("��");
//		break;
//	case 4:
//		printf("Joker");
//		break;
//	}
//
//	if ((num / 13) < 4)
//	{
//		switch (num % 13)
//		{
//		case 0:
//			printf("A");
//			break;
//		case 10:
//			printf("J");
//			break;
//		case 11:
//			printf("Q");
//			break;
//		case 12:
//			printf("K");
//			break;
//		default:
//			printf("%d", num % 13 + 1);
//			break;
//		}
//	}
//}
#pragma endregion