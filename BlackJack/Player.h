#pragma once
#include <iostream>
#include "Hand.h"
#include "Deck.h"

class Player
{
private:
	Hand hand;
	enum class Action { HIT, STAND };
public:
	Player(Deck &deck);
	void hit(Deck &deck);
	Hand get_hand();
};

