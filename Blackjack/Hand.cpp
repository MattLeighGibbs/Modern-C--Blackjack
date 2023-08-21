#include "Hand.h"

void Hand::AddCard(std::unique_ptr<Card>&& card)
{
    cards.push_back(std::move(card));
}

int Hand::GetScore() const
{
    int returnVal = 0;
    for (const std::unique_ptr<Card>& card : cards)
    {
        if (card->GetOverridenValue() == -1)
        {
            returnVal += (int)card->GetValue();
        }
        else
        {
            returnVal += card->GetOverridenValue();
        }

    }

    return returnVal;
}
