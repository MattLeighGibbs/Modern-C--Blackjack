#pragma once
#include "Enums.h"

class Card
{
public:
	Card(const Card&) = delete;
	Card& operator=(const Card&) = delete;
	~Card() = default;

	Card(int newSuit, int newValue)
	{
		suit = (Enums::Suit)newSuit;
		value = (Enums::Value)newValue;
	}

	Enums::Suit GetSuit() const
	{
		return suit;
	}

	int GetValue() const
	{
		if (value == Enums::Value::JACK ||
			value == Enums::Value::QUEEN ||
			value == Enums::Value::KING)
		{
			return 10;
		}
		if (value == Enums::ACE)
		{
			// idk yet
			return overridenValue;
		}

		// this sucks v why magic number 
		// ( need to figure out best way to map val enum )
		return value + 2;
	}

	Enums::Value GetValueEnum() const
	{
		return value;
	}

	int GetOverridenValue() const
	{
		return overridenValue;
	}

	void SetOverridenValue(int val)
	{
		overridenValue = val;
	}
private:
	Enums::Suit suit{ Enums::Suit::CLUBS };
	Enums::Value value{ Enums::Value::TWO};
	int overridenValue{ -1 };
};