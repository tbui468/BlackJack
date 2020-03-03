#pragma once
#include "Deck.h"
#include "House.h"

class Round
{
private:
	int round = 0;
	int deck_number = 1;
	Deck deck;
	House house;
public:
	Round();
	Deck get_deck();
	House get_house();
};

