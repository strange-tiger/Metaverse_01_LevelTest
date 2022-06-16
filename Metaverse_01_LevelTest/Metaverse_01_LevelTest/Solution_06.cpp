// 문제를 파악한 내용 : 53개의 문자열 중 14개의 임의의 중복하지 않는 문자열을 뽑는 문제
// 해결 아이디어 : 이전 문제를 응용해 53개 숫자 중 14개를 임의로 중복하지 않게 뽑고, 기호와 52까지의 수를 모듈러로 매칭해 출력한다. 53은 조커로 한다.

#pragma region 이진호_코드
//#include <iostream>
//#include <cstdlib>
//
//int* RandNum(int maxNum, int numCount);	// 임의의 범위 안 자연수의 배열 : Solution_05의 풀이를 함수로
//void CardPrint(int cardNum);			// 받은 카드 값을 바탕으로 switch문으로 카드를 출력하는 함수
//
//int main()
//{
//	int* numArr = RandNum(53, 14);		// Solution_05의 풀이를 함수로 하여 임의의 14개 수 생성
//	
//	// Player 1 출력
//	std::cout << "Player 1 : ";
//	for (size_t i = 0; i < 7; i++)
//	{
//		int cardNum = *(numArr + i);
//
//		if (cardNum == 53)				// 53은 조커로 한다.
//		{
//			std::cout << "Joker";
//		}
//		else
//		{
//			CardPrint(cardNum);			// 받은 카드 값을 바탕으로 카드를 출력
//		}
//
//		if (i != 6)
//		{
//			std::cout << ", ";
//		}
//	}
//	std::cout << std::endl;
//
//	// Player 2 출력
//	std::cout << "Player 2 : ";
//	for (size_t i = 7; i < 14; i++)
//	{
//		int cardNum = *(numArr + i);
//
//		if (cardNum == 53)				// 53은 조커로 한다.
//		{
//			std::cout << "Joker";
//		}
//		else
//		{
//			CardPrint(cardNum);			// 받은 카드 값을 바탕으로 카드를 출력
//		}
//
//		if (i != 13)
//		{
//			std::cout << ", ";
//		}
//	}
//	std::cout << std::endl;
//
//	// 반환
//	delete[] numArr;
//}
//
//int* RandNum(int maxNum, int numCount)
//{
//	int* numArr = new int[numCount];				// 중복되지 않는 로또 번호 저장 배열, 동적 할당
//	int queue = 0;									// 현재 위의 배열에 저장되어있는 수의 개수 
//
//	std::srand(time(NULL));							// rand 시드 설정
//
//	while (queue < numCount)						// queue == numCount가 될 때까지 반복
//	{
//		int randNum = std::rand() % maxNum + 1;		// 로또 번호 후보 : maxNum을 넘지 않고 1 이상인 임의의 수 생성
//		if (queue)									// queue가 0이 아니라면
//		{
//			for (size_t j = 0; j < queue; j++)		// queue만큼 반복
//			{
//				if (randNum == *(numArr + j))	// 현재 로또 번호 배열과 후보 번호를 비교
//				{
//					randNum = 0;					// 중복되면 0 할당
//					break;
//				}
//			}
//		}
//
//		if (randNum)								// randNum이 0이 아니라면
//		{
//			*(numArr + queue) = randNum;		// 로또 번호 배열의 queue번째는 randNum
//			queue++;								// queue 증가
//		}
//	}
//
//	return numArr;
//}
//
//void CardPrint(int cardNum)
//{
//	// 기호 출력
//	switch (cardNum % 4)
//	{
//	case 0:
//		std::cout << "♠";
//		break;
//	case 1:
//		std::cout << "♣";
//		break;
//	case 2:
//		std::cout << "♥";
//		break;
//	case 3:
//		std::cout << "◆";
//		break;
//	}
//
//	// 수 (카드 값) 출력
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

#pragma region 전지윤코드
// 전지윤 코드
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
//		printf("♠");
//		break;
//	case 1:
//		printf("♣");
//		break;
//	case 2:
//		printf("♥");
//		break;
//	case 3:
//		printf("◆");
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

#pragma region 최선문교수_코드
//#include <iostream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//
//
//// 0 ~ 12 : 스페이드
//// 13 ~ 25 : 클로버
//// 26 ~ 38 : 하트
//// 38 ~ 51 : 다이아몬드
//// 52 : 조커
//bool isUsedCard[53] = { false };
//
///// <summary>
///// 카드 7장을 뽑는다.
///// </summary>
//int* PickCard()
//{ //동적할당 
//	int* deck = new int[7];
//
//	// 김재민
//	for (int i = 0; i < 7; i++) // 카드를 7개 뽑는다
//	{
//		// 중복 처리
//		int card = 0;
//		do
//		{
//			// 랜덤하게 카드 뽑기
//			card = rand() % 53; // 0~52까지 카드
//		} while (isUsedCard[card]); // 카드가 있으면 게속 반복
//
//		// 카드는 중복되지 않았다.
//
//		deck[i] = card; // 카드53개중 내가뽑은카드 7개 저장
//		isUsedCard[card] = true; // 카드가 뽑았다고 알려줌
//	}
//
//	return deck;
//}
//
///// <summary>
///// 카드 7장을 뽑는다.
///// </summary>
///// <param name="deck">플레이어의 덱</param>
//void PickCard(int* deck)
//{
//	// 김재민
//	for (int i = 0; i < 7; i++) // 카드를 7개 뽑는다
//	{
//		// 중복 처리
//		int card = 0;
//		do
//		{
//			// 랜덤하게 카드 뽑기
//			card = rand() % 53; // 0~52까지 카드
//		} while (isUsedCard[card]); // 카드가 있으면 게속 반복
//
//		// 카드는 중복되지 않았다.
//
//		deck[i] = card; // 카드53개중 내가뽑은카드 7개 저장
//		isUsedCard[card] = true; // 카드가 뽑았다고 알려줌
//	}
//}
//
///// <summary>
///// cardIndex를 대응되는 card 문자열로 바꾼다.
///// // 0 ~ 12 : 스페이드 => 0
//	// 13 ~ 25 : 클로버 => 1
//	// 26 ~ 38 : 하트 => 2
//	// 38 ~ 51 : 다이아몬드 => 3
//	// 52 : 조커 =>4
//
//	// 12가 들어오면 ♠12
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
//	static const string CARD_TYPE[] = { "♠", "♣", "♥", "◆" };
//	static const string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
//
//	string result = CARD_TYPE[cardIndex / 13];
//	// CARD_TYPE[0] : "♠"
//	// CARD_TYPE[1] : "♣"
//	// CARD_TYPE[2] : "♥"
//	// CARD_TYPE[3] : "◆"
//	if (cardIndex / 13 == 0)
//		"♠";
//	else if (cardIndex / 13 == 1)
//		"♣";
//	else if (cardIndex / 13 == 2)
//		"♥";
//	else if (cardIndex / 13 == 3)
//		"◆";
//
//	switch (cardIndex / 13)
//	{
//	case 0:
//		result += "♠";
//	case 1:
//		result += "♣";
//	case 2:
//		result += "♥";
//	case 3:
//		result += "◆";
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

#pragma region 모듈화_클래스

#include <iostream>
#include <string>
#include <sstream>

#define DECK_CARD_NUM 7
#define PLAYER_NUM 8

using namespace std;
// Deck 타입
// Make()
//	 :	카드를 7장 뽑아서 덱을 구성한다.
//		모든 덱은 카드가 중복되지 않아야 한다.
//		단 카드가 충분치 않은 경우 만들어지지 못할 수 있다.
// ToString()
//	 :	현재 덱의 카드를 표현하는 문자열을 만든다.
//		카드가 없는 경우 "The deck is empty"로 반환한다.

// 0 ~ 12 : 스페이드
// 13 ~ 25 : 클로버
// 26 ~ 38 : 하트
// 38 ~ 51 : 다이아몬드
// 52 : 조커

class Deck
{
	static bool			isUsedCard[54];	// 정적 데이터는 초기화하지 않으면 초기값이 0이다.
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
	/// 카드를 7장 뽑아서 덱을 구성한다.
	///	모든 덱은 카드가 중복되지 않아야 한다.
	/// </summary>
	/// <returns>덱이 성공적으로 구성됐을 경우 true, 아니면 false</returns>
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
		const string	CARD_TYPE[4] = { "♠", "♣", "♥", "◆" };
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