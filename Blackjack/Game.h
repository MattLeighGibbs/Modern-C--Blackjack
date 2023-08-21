#pragma once
#include <vector>
#include "player.h"
#include "Dealer.h"

class BlackJack
{
public:	
	BlackJack() {}
	BlackJack(const BlackJack&) = delete;
	BlackJack& operator=(const BlackJack&) = delete;
	~BlackJack() = default;

	void Init(int playerCount)
	{
		players.clear();
		MakePlayers(playerCount);
		dealer->FillDeck();
	}

	void DoRound();
private:
	void MakePlayers(int count);
	std::vector<std::unique_ptr<Player>> players;
	Dealer* dealer{ nullptr };
};