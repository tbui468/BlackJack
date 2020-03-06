#pragma once
#include <iostream>
#include "Deck.h"
#include "Player.h"

typedef std::vector<std::string> pic;

class Round
{
private:
	int round = 0;
	int deck_number = 1;
	bool round_end = false;
	Deck deck;
	Player player;
	Player house;
	static const std::string lost_message;
	static const std::string won_message;
	static const std::string tied_message;
	static const std::string blackjack_message;
	pic card_back;
	pic card_front;
	void print_pic(pic pic);

public:
	Round(Deck &deck, Player &player, Player &house);
	int start_round(int bet); //returns amount of player winnings
	Deck get_deck();
	void display_cards();
	void display_player_cards(Player player, bool hide_card);
	bool has_blackjack(Hand hand);
	int won(int bet);
	int lost(int bet);
	int tied(int bet);
	void print_cards(Hand hand, bool hide_card);
};

