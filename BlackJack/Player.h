#pragma once
#include <iostream>
#include "Hand.h"
#include "Deck.h"

class Player
{
private:
	Hand hand;
	int money = 0;
	int bet = 0;
	std::string name = "Player";
public:
	Player(Deck &deck);
	void hit(Deck &deck);
	void stand();
	void double_down(Deck &deck);
	Hand& get_hand();
	void set_name(std::string name);
	std::string get_name();
	int get_money();
	void set_money(int money);
	int get_bet();
	void set_bet(int bet);
	void clear_hand();
};

