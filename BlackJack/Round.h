#pragma once
#include <iostream>
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Round
{
private:
	int round = 0;
	int deck_number = 1;
	Deck deck;
	Player player;
	House house;
public:
	Round();
	Deck get_deck();
	House get_house();
	void my_print();
};

