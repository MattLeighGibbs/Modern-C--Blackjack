#pragma once
#include <vector>
#include "player.h"
#include "card.h"
#include "Enums.h"

// maybe call "table" ?       
class Dealer : public Player
{
public:
	Dealer() {}
	Dealer(const std::string& newName) { name = newName; }
	Dealer(const Dealer&) = delete;
	Dealer& operator=(const Dealer&) = delete;
	~Dealer() = default;

	void ProdForMove(Player* player);
	void GivePlayerCard(Player* player, int count = 1);
	void FillDeck();

private:
	std::vector<std::unique_ptr<Card>> deck{};
};