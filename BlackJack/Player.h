#pragma once
#include <iostream>
#include "Hand.h"
#include "Deck.h"

class Player
{
private:
	Hand hand;
	bool current_turn = true;
public:
	Player(Deck &deck);
	void hit(Deck &deck);
	void stand();
	void double_down(Deck &deck);
	Hand get_hand();
};

