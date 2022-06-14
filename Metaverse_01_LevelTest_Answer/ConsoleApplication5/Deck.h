#pragma once

#include <iostream>

// Deck Ÿ��
// ToString()
//   : ���� ���� ī�带 ǥ���ϴ� ���ڿ��� �����.
//     ī�尡 ���� ��� "The deck is empty" �� ��ȯ�Ѵ�.

class Deck
{
public:
	/// <summary>
	/// ī�带 7�� �̾Ƽ� ���� �����Ѵ�.
	/// ��� ���� ī�尡 �ߺ����� �ʾƾ� �Ѵ�.
	/// </summary>
	/// <returns>���� ���������� �������� ��� true, �ƴϸ� false</returns>
	bool	Make()
	{
		for (int i = 0; i < 7; i++)
		{
			int card = 0;
			do
			{
				card = rand() % 53;
			} while (isUsedCard[card]);

			deck[i] = card;
			isUsedCard[card] = true; // ī�尡 �̾Ҵٰ� �˷���
		}
	}

	ToString();
private:
};