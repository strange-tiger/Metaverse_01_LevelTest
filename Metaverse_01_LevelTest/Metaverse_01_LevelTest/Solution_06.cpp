// ������ �ľ��� ���� : 53���� ���ڿ� �� 14���� ������ �ߺ����� �ʴ� ���ڿ��� �̴� ����
// �ذ� ���̵�� : ���� ������ ������ 53�� ���� �� 14���� ���Ƿ� �ߺ����� �ʰ� �̰�, ��ȣ�� 52������ ���� ��ⷯ�� ��Ī�� ����Ѵ�. 53�� ��Ŀ�� �Ѵ�.

#pragma region ����ȣ_�ڵ�
//#include <iostream>
//#include <cstdlib>
//
//int* RandNum(int maxNum, int numCount);	// ������ ���� �� �ڿ����� �迭 : Solution_05�� Ǯ�̸� �Լ���
//void CardPrint(int cardNum);			// ���� ī�� ���� �������� switch������ ī�带 ����ϴ� �Լ�
//
//int main()
//{
//	int* numArr = RandNum(53, 14);		// Solution_05�� Ǯ�̸� �Լ��� �Ͽ� ������ 14�� �� ����
//	
//	// Player 1 ���
//	std::cout << "Player 1 : ";
//	for (size_t i = 0; i < 7; i++)
//	{
//		int cardNum = *(numArr + i);
//
//		if (cardNum == 53)				// 53�� ��Ŀ�� �Ѵ�.
//		{
//			std::cout << "Joker";
//		}
//		else
//		{
//			CardPrint(cardNum);			// ���� ī�� ���� �������� ī�带 ���
//		}
//
//		if (i != 6)
//		{
//			std::cout << ", ";
//		}
//	}
//	std::cout << std::endl;
//
//	// Player 2 ���
//	std::cout << "Player 2 : ";
//	for (size_t i = 7; i < 14; i++)
//	{
//		int cardNum = *(numArr + i);
//
//		if (cardNum == 53)				// 53�� ��Ŀ�� �Ѵ�.
//		{
//			std::cout << "Joker";
//		}
//		else
//		{
//			CardPrint(cardNum);			// ���� ī�� ���� �������� ī�带 ���
//		}
//
//		if (i != 13)
//		{
//			std::cout << ", ";
//		}
//	}
//	std::cout << std::endl;
//
//	// ��ȯ
//	delete[] numArr;
//}
//
//int* RandNum(int maxNum, int numCount)
//{
//	int* numArr = new int[numCount];				// �ߺ����� �ʴ� �ζ� ��ȣ ���� �迭, ���� �Ҵ�
//	int queue = 0;									// ���� ���� �迭�� ����Ǿ��ִ� ���� ���� 
//
//	std::srand(time(NULL));							// rand �õ� ����
//
//	while (queue < numCount)						// queue == numCount�� �� ������ �ݺ�
//	{
//		int randNum = std::rand() % maxNum + 1;		// �ζ� ��ȣ �ĺ� : maxNum�� ���� �ʰ� 1 �̻��� ������ �� ����
//		if (queue)									// queue�� 0�� �ƴ϶��
//		{
//			for (size_t j = 0; j < queue; j++)		// queue��ŭ �ݺ�
//			{
//				if (randNum == *(numArr + j))	// ���� �ζ� ��ȣ �迭�� �ĺ� ��ȣ�� ��
//				{
//					randNum = 0;					// �ߺ��Ǹ� 0 �Ҵ�
//					break;
//				}
//			}
//		}
//
//		if (randNum)								// randNum�� 0�� �ƴ϶��
//		{
//			*(numArr + queue) = randNum;		// �ζ� ��ȣ �迭�� queue��°�� randNum
//			queue++;								// queue ����
//		}
//	}
//
//	return numArr;
//}
//
//void CardPrint(int cardNum)
//{
//	// ��ȣ ���
//	switch (cardNum % 4)
//	{
//	case 0:
//		std::cout << "��";
//		break;
//	case 1:
//		std::cout << "��";
//		break;
//	case 2:
//		std::cout << "��";
//		break;
//	case 3:
//		std::cout << "��";
//		break;
//	}
//
//	// �� (ī�� ��) ���
//	switch (cardNum % 13 + 1)
//	{
//	case 1:
//		std::cout << "A";
//		break;
//	case 11:
//		std::cout << "J";
//		break;
//	case 12:
//		std::cout << "Q";
//		break;
//	case 13:
//		std::cout << "K";
//		break;
//	default:
//		std::cout << cardNum % 13 + 1;
//		break;
//	}
//}
#pragma endregion

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

#pragma region �ּ�������_�ڵ�
//#include <iostream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//
//
//// 0 ~ 12 : �����̵�
//// 13 ~ 25 : Ŭ�ι�
//// 26 ~ 38 : ��Ʈ
//// 38 ~ 51 : ���̾Ƹ��
//// 52 : ��Ŀ
//bool isUsedCard[53] = { false };
//
///// <summary>
///// ī�� 7���� �̴´�.
///// </summary>
//int* PickCard()
//{ //�����Ҵ� 
//	int* deck = new int[7];
//
//	// �����
//	for (int i = 0; i < 7; i++) // ī�带 7�� �̴´�
//	{
//		// �ߺ� ó��
//		int card = 0;
//		do
//		{
//			// �����ϰ� ī�� �̱�
//			card = rand() % 53; // 0~52���� ī��
//		} while (isUsedCard[card]); // ī�尡 ������ �Լ� �ݺ�
//
//		// ī��� �ߺ����� �ʾҴ�.
//
//		deck[i] = card; // ī��53���� ��������ī�� 7�� ����
//		isUsedCard[card] = true; // ī�尡 �̾Ҵٰ� �˷���
//	}
//
//	return deck;
//}
//
///// <summary>
///// ī�� 7���� �̴´�.
///// </summary>
///// <param name="deck">�÷��̾��� ��</param>
//void PickCard(int* deck)
//{
//	// �����
//	for (int i = 0; i < 7; i++) // ī�带 7�� �̴´�
//	{
//		// �ߺ� ó��
//		int card = 0;
//		do
//		{
//			// �����ϰ� ī�� �̱�
//			card = rand() % 53; // 0~52���� ī��
//		} while (isUsedCard[card]); // ī�尡 ������ �Լ� �ݺ�
//
//		// ī��� �ߺ����� �ʾҴ�.
//
//		deck[i] = card; // ī��53���� ��������ī�� 7�� ����
//		isUsedCard[card] = true; // ī�尡 �̾Ҵٰ� �˷���
//	}
//}
//
///// <summary>
///// cardIndex�� �����Ǵ� card ���ڿ��� �ٲ۴�.
///// // 0 ~ 12 : �����̵� => 0
//	// 13 ~ 25 : Ŭ�ι� => 1
//	// 26 ~ 38 : ��Ʈ => 2
//	// 38 ~ 51 : ���̾Ƹ�� => 3
//	// 52 : ��Ŀ =>4
//
//	// 12�� ������ ��12
///// </summary>
///// <param name="cardIndex"></param>
///// <returns></returns>
//
//std::string ConvertToCardString(int cardIndex)
//{
//	int cardTypeIndex = cardIndex / 13;
//	int cardNumberIndex = cardIndex % 13;
//
//	// Lookup Table
//	static const string CARD_TYPE[] = { "��", "��", "��", "��" };
//	static const string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
//
//	string result = CARD_TYPE[cardIndex / 13];
//	// CARD_TYPE[0] : "��"
//	// CARD_TYPE[1] : "��"
//	// CARD_TYPE[2] : "��"
//	// CARD_TYPE[3] : "��"
//	if (cardIndex / 13 == 0)
//		"��";
//	else if (cardIndex / 13 == 1)
//		"��";
//	else if (cardIndex / 13 == 2)
//		"��";
//	else if (cardIndex / 13 == 3)
//		"��";
//
//	switch (cardIndex / 13)
//	{
//	case 0:
//		result += "��";
//	case 1:
//		result += "��";
//	case 2:
//		result += "��";
//	case 3:
//		result += "��";
//	}
//
//	int cardNumber = cardIndex % 13;
//
//
//	if (cardTypeIndex == 4)
//	{
//		return "Joker";
//	}
//	else
//	{
//		return CARD_TYPE[cardTypeIndex] + CARD_NUMBER[cardNumberIndex];
//	}
//}
//
//int main()
//{
//	int player1Deck[7] = { 0 };
//	PickCard(player1Deck);
//
//	int* player2Deck = PickCard();
//
//	for (int i = 0; i < 7; ++i)
//	{
//		cout << ConvertToCardString(player1Deck[i]) << " ";
//	}
//	cout << "\n";
//
//	for (int i = 0; i < 7; ++i)
//	{
//		cout << ConvertToCardString(player2Deck[i]) << " ";
//	}
//	cout << "\n";
//
//	delete[] player2Deck;
//}
#pragma endregion

#pragma region ���ȭ_Ŭ����

#include <iostream>
#include <string>
#include <sstream>

#define DECK_CARD_NUM 7
#define PLAYER_NUM 8

using namespace std;
// Deck Ÿ��
// Make()
//	 :	ī�带 7�� �̾Ƽ� ���� �����Ѵ�.
//		��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
//		�� ī�尡 ���ġ ���� ��� ��������� ���� �� �ִ�.
// ToString()
//	 :	���� ���� ī�带 ǥ���ϴ� ���ڿ��� �����.
//		ī�尡 ���� ��� "The deck is empty"�� ��ȯ�Ѵ�.

// 0 ~ 12 : �����̵�
// 13 ~ 25 : Ŭ�ι�
// 26 ~ 38 : ��Ʈ
// 38 ~ 51 : ���̾Ƹ��
// 52 : ��Ŀ

class Deck
{
	static bool			isUsedCard[54];	// ���� �����ʹ� �ʱ�ȭ���� ������ �ʱⰪ�� 0�̴�.
	static int			remainCard;
public:
	Deck()
	{
		srand(time(nullptr));
	}

	Deck(const Deck& other) = delete;
	Deck& operator=(const Deck& other) = delete;
	~Deck() = default;
		
	/// <summary>
	/// ī�带 7�� �̾Ƽ� ���� �����Ѵ�.
	///	��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
	/// </summary>
	/// <returns>���� ���������� �������� ��� true, �ƴϸ� false</returns>
	bool Make()
	{
		if (remainCard < DECK_CARD_NUM)
		{
			return false;
		}
		for (int i = 0; i < 53; i++)
		{
			int count = 0;
			if (!isUsedCard[i])
			{
				count++;

				if (count >= DECK_CARD_NUM)
				{
					break;
				}
			}
		}
		
		for (int i = 0; i < DECK_CARD_NUM; i++)
		{
			int card = 0;

			/*bool failToMake = false;
			for (int j = 0; j < 53; j++)
			{
				if (!isUsedCard[j])
				{
					failToMake = true;
					break;
				}
			}

			if (failToMake)
			{
				return false;
			}*/

			do
			{
				card = rand() % 53 + 1;
			} while (isUsedCard[card]);

			_deck[i] = card;
			isUsedCard[card] = true;
		}

		remainCard -= DECK_CARD_NUM;
		return true;
	}

	string ToString()
	{
		// stringstream _ss;
		string result;

		// Lookup Table
		const string	CARD_TYPE[4] = { "��", "��", "��", "��" };
		const string	CARD_NUMBER[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };


		int cardType	= _cardIndex / 13;
		int cardNumber	= _cardIndex % 13;
		if (cardType == 4)
		{
			// _ss << "Joker";
			result += "Joker";
		}
		else
		{
			// _ss << CARD_TYPE[cardType] + CARD_NUMBER[cardNumber];
			result += CARD_TYPE[cardType] + CARD_NUMBER[cardNumber];
		}
		
		// return _ss.str();
		return result;
	}

	void Print()
	{
		for (int i = 0; i < DECK_CARD_NUM; ++i)
		{

			if (_deck[0] == 0)
			{
				cout << "The deck is empty" << endl;
				return;
			}

			_cardIndex = _deck[i];
			cout << ToString() << " ";
		}
		cout << "\n";
	}

private:
	int			_deck[DECK_CARD_NUM] = { 0 };
	int			_cardIndex = 0;
};

bool			Deck::isUsedCard[54] = { false };
int				Deck::remainCard = 53;

int main()
{
	Deck playerDeck[PLAYER_NUM];
	
	for (int i = 0; i < PLAYER_NUM; i++)
	{
		playerDeck[i].Make();
		playerDeck[i].Print();
	}
	
	return 0;
}

#pragma endregion