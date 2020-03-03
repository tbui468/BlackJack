#pragma once
#include "Hand.h"
#include "Deck.h"


class House
{
private:
	Hand hand;
	enum class Action { STAND, HIT };
public:
	House(Deck &deck);
	void stand();
	void hit(Deck &deck);
	House::Action next_move();
};

