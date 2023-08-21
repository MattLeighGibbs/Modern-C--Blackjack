#include "Dealer.h"

void Dealer::ProdForMove(Player* player)
{
	Enums::Move move = player->GiveMove();

	if (move == Enums::Move::HITME)
	{
		GivePlayerCard(player);
	}
}

void Dealer::GivePlayerCard(Player* player, int count)
{
	for (int i = 0; i < count; i++)
	{
		srand(1);

		int cardsLeft = deck.size();
		int cardIndex = rand() % cardsLeft;
		player->AddToHand(std::move(deck[cardIndex]));
		std::swap(deck[cardIndex], deck.back());
		deck.pop_back();
	}
}

void Dealer::FillDeck()
{
	for (int i = 0; i < (int)Enums::Suit::DIAMONDS; i++)
	{
		for (int j = 0; j < (int)Enums::Value::ACE; j++)
		{
			deck.emplace_back(std::make_unique<Card>(i, j));
		}
	}
}

