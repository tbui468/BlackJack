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
	bool round_end = false;
	Deck deck;
	Player player;
	House house;
public:
	Round();
	Deck get_deck();
	House get_house();
	void display_cards();
	bool has_blackjack(Player player);
	bool has_blackjack(House house);
};

