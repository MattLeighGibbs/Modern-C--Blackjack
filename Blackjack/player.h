#pragma once
#include <vector>
#include "Hand.h"
#include "Enums.h"
#include <string>

class Player
{
public:	
	Player() {}
	Player(const std::string& name)
	{
		SetName(name);
	}
	Player(const Player&) = delete;

	Player& operator=(const Player&) = delete;
	~Player() = default;

	Enums::Move GiveMove();
	
	void AddToHand(std::unique_ptr<Card>&& card)
	{
		if (card->GetValue() == Enums::Value::ACE)
		{
			int overridenValue = 11 + hand.GetScore() > 21 ? 1 : 11;
			card->SetOverridenValue(overridenValue);
		}
		hand.AddCard(std::move(card));
		lost = hand.GetScore() > 21;
	}
	Hand* GetHand() 
	{
		return &hand;
	}

	int GetScore() const
	{
		return hand.GetScore();
	}

	bool IsStillPlaying() const
	{
		return !lost && !holding;
	}

	std::string GetName() const
	{
		return name;
	}

	void SetName(const std::string& newName)
	{
		name = newName;
	}

	bool GetIsDealer() const
	{
		return isDealer;
	}

	void SetIsDealer(bool newVal)
	{
		isDealer = newVal;
	}

protected:
	bool lost{ false };
	bool holding{ false };
	bool isDealer{ false };
	Hand hand;
	std::string name;
}; 