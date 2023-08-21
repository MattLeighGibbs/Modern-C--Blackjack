#include "Game.h"
#include "Dealer.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>         // std::this_thread::sleep_for

std::string SuitToText(Enums::Suit suit)
{
	switch (suit)
	{
	case Enums::Suit::CLUBS:
		return "Clubs";
	case Enums::Suit::DIAMONDS:
		return "Diamonds";
	case Enums::Suit::HEARTS:
		return "Hearts";
	case Enums::Suit::SPADES:
		return "Spades";
	}
}
std::string ValueToText(Enums::Value value)
{
	switch (value)
	{
		case Enums::Value::ACE:
			return "A";
		case Enums::Value::TWO:
			return "2";
		case Enums::Value::THREE:
			return "3";
		case Enums::Value::FOUR:
			return "4";
		case Enums::Value::FIVE:
			return "5";
		case Enums::Value::SIX:
			return "6";
		case Enums::Value::SEVEN:
			return "7";
		case Enums::Value::EIGHT:
			return "8";
		case Enums::Value::NINE:
			return "9";
		case Enums::Value::TEN:
			return "10";
		case Enums::Value::JACK:
			return "J";
		case Enums::Value::QUEEN:
			return "Q";
		case Enums::Value::KING:
			return "K";
	}
}


void BlackJack::MakePlayers(int count)
{
	std::vector<std::string> playerNames({ "Jim", "Nancy", "Billy" });
	for (int i = 0; i < playerNames.size(); i++)
	{
		if (i == 0)
		{
			players.push_back(std::make_unique<Dealer>("Don Corleone"));
			dealer = (Dealer*)players[i].get();
			players[i]->SetIsDealer(true);
		}
		else 
		{
			Player pl(playerNames[i]);
			players.push_back(std::make_unique<Player>(playerNames[i]));
		}
	}
}

void BlackJack::DoRound()
{
	// give players initial cards
	for (int i = 0; i < players.size(); i++)
	{
		dealer->GivePlayerCard(players[i].get(), 2);
	}

	bool stillPlaying = false;

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	
		int playersStillPlaying = 0;
		for (int i = 0; i < players.size(); i++)
		{			
			if (players[i]->IsStillPlaying())
			{
				playersStillPlaying++;
			}
		}

		for (auto& player : players)
		{
			std::cout << "Player: " << player->GetName() << std::endl;
			if (player->GetIsDealer())
			{
				std::cout << " (Dealer)" << std::endl;
			}

			std::cout << "Cards: " << std::endl;
			Hand* hand = player->GetHand();
			for (int i = 0; i < hand->GetNumberOfCards(); i++)
			{
				Card* card = hand->GetCardAtIndex(i);
				std::cout << ValueToText(card->GetValueEnum()) << " " <<
					SuitToText(card->GetSuit()) << std::endl;
			}

			std::cout << "Score: " << hand->GetScore() << "\n\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));

			if (player->IsStillPlaying())
			{
				dealer->ProdForMove(player.get());
			}
		}
		std::cout << "---------------------------------------------" << "\n\n";

		if (playersStillPlaying <= 1)
		{
			break;
		}
	}
}