#include "player.h"

Enums::Move Player::GiveMove() 
{
	if (hand.GetScore() > 15)
	{
		holding = true;
		return Enums::Move::STAY;
	}
	else
	{
		return Enums::Move::HITME;
	}
}