#pragma once
#include <vector>
#include <memory>
#include "card.h"

class Hand
{
public:
	Hand() {}
	Hand(const Hand&) = delete;
	Hand& operator=(const Hand&) = delete;
	~Hand() = default;

	void AddCard(std::unique_ptr<Card>&& card);
	
	int GetScore() const;

	int GetNumberOfCards() const
	{
		return cards.size();
	}

	Card* GetCardAtIndex(int i)
	{
		return cards[i].get();
	}
private:
	std::vector<std::unique_ptr<Card>> cards;
};