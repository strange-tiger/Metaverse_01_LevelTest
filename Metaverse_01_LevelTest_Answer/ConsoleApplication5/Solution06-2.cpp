#include <iostream>
#include <string>
#include <sstream>

using namespace std;



// 0 ~ 12 : �����̵�
// 13 ~ 25 : Ŭ�ι�
// 26 ~ 38 : ��Ʈ
// 38 ~ 51 : ���̾Ƹ��
// 52 : ��Ŀ
bool isUsedCard[53] = { false };

/// <summary>
/// ī�� 7���� �̴´�.
/// </summary>
int* PickCard()
{ //�����Ҵ� 
	int* deck = new int[7];

	// �����
	for (int i = 0; i < 7; i++) // ī�带 7�� �̴´�
	{
		// �ߺ� ó��
		int card = 0;
		do
		{
			// �����ϰ� ī�� �̱�
			card = rand() % 53; // 0~52���� ī��
		} while (isUsedCard[card]); // ī�尡 ������ �Լ� �ݺ�

		// ī��� �ߺ����� �ʾҴ�.

		deck[i] = card; // ī��53���� ��������ī�� 7�� ����
		isUsedCard[card] = true; // ī�尡 �̾Ҵٰ� �˷���
	}

	return deck;
}

/// <summary>
/// ī�� 7���� �̴´�.
/// </summary>
/// <param name="deck">�÷��̾��� ��</param>
void PickCard(int* deck)
{
	// �����
	for (int i = 0; i < 7; i++) // ī�带 7�� �̴´�
	{
		// �ߺ� ó��
		int card = 0;
		do
		{
			// �����ϰ� ī�� �̱�
			card = rand() % 53; // 0~52���� ī��
		} while (isUsedCard[card]); // ī�尡 ������ �Լ� �ݺ�

		// ī��� �ߺ����� �ʾҴ�.

		deck[i] = card; // ī��53���� ��������ī�� 7�� ����
		isUsedCard[card] = true; // ī�尡 �̾Ҵٰ� �˷���
	}
}

/// <summary>
/// cardIndex�� �����Ǵ� card ���ڿ��� �ٲ۴�.
/// // 0 ~ 12 : �����̵� => 0
	// 13 ~ 25 : Ŭ�ι� => 1
	// 26 ~ 38 : ��Ʈ => 2
	// 38 ~ 51 : ���̾Ƹ�� => 3
	// 52 : ��Ŀ =>4

	// 12�� ������ ��12
/// </summary>
/// <param name="cardIndex"></param>
/// <returns></returns>

std::string ConvertToCardString(int cardIndex)
{
	int cardTypeIndex = cardIndex / 13;
	int cardNumberIndex = cardIndex % 13;

	// Lookup Table
	static const string CARD_TYPE[] = { "��", "��", "��", "��" };
	static const string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	string result = CARD_TYPE[cardIndex / 13];
	// CARD_TYPE[0] : "��"
	// CARD_TYPE[1] : "��"
	// CARD_TYPE[2] : "��"
	// CARD_TYPE[3] : "��"
	if (cardIndex / 13 == 0)
		"��";
	else if (cardIndex / 13 == 1)
		"��";
	else if (cardIndex / 13 == 2)
		"��";
	else if (cardIndex / 13 == 3)
		"��";

	switch (cardIndex / 13)
	{
	case 0:
		result += "��";
	case 1:
		result += "��";
	case 2:
		result += "��";
	case 3:
		result += "��";
	}

	int cardNumber = cardIndex % 13;


	if (cardTypeIndex == 4)
	{
		return "Joker";
	}
	else
	{
		return CARD_TYPE[cardTypeIndex] + CARD_NUMBER[cardNumberIndex];
	}
}

int main()
{
	int player1Deck[7] = { 0 };
	PickCard(player1Deck);

	int* player2Deck = PickCard();

	for (int i = 0; i < 7; ++i)
	{
		cout << ConvertToCardString(player1Deck[i]) << " ";
	}
	cout << "\n";

	for (int i = 0; i < 7; ++i)
	{
		cout << ConvertToCardString(player2Deck[i]) << " ";
	}
	cout << "\n";

	delete[] player2Deck;
}