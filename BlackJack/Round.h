#pragma once
#include <iostream>
#include "Deck.h"
#include "Player.h"

class Round
{
private:
	int round = 0;
	int deck_number = 1;
	bool round_end = false;
	Deck deck;
	Player player;
	Player house;
public:
	Round();
	void start_round();
	Deck get_deck();
	void display_cards();
	bool has_blackjack(Hand hand);
};

