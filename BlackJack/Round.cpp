#include "Round.h"

Round::Round() : deck(deck_number), player(deck), house(deck) {

	//player goes first
	std::cout << "Your cards" << std::endl;
	std::cout << "**********" << std::endl;
	Hand player_hand = player.get_hand();
	std::vector<std::string> player_cards = player_hand.get_cards();
	for (unsigned int i = 0; i < player_cards.size(); ++i) {
		std::cout << player_cards[i] << std::endl;
	}

	std::cout << std::endl;

	//House goes second
	std::cout << "House cards" << std::endl;
	std::cout << "***********" << std::endl;
	Hand hand = house.get_hand();
	std::vector<std::string> cards = hand.get_cards();
	for (unsigned int i = 0; i < cards.size(); ++i) {
		std::cout << cards[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Deck" << std::endl;
	std::cout << "****" << std::endl;
	std::cout << deck.size() << std::endl;
}

Deck Round::get_deck() {
	return deck;
}

House Round::get_house() {
	return house;
}

void Round::my_print() {
	std::cout << "Test" << std::endl;
}