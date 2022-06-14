#pragma once

#include <iostream>

// Deck 타입
// ToString()
//   : 현재 덱의 카드를 표현하는 문자열을 만든다.
//     카드가 없는 경우 "The deck is empty" 로 반환한다.

class Deck
{
public:
	/// <summary>
	/// 카드를 7장 뽑아서 덱을 구성한다.
	/// 모든 덱은 카드가 중복되지 않아야 한다.
	/// </summary>
	/// <returns>덱이 성공적으로 구성됐을 경우 true, 아니면 false</returns>
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
			isUsedCard[card] = true; // 카드가 뽑았다고 알려줌
		}
	}

	ToString();
private:
};