#include "Deck.h"


Deck::Deck(int decks) {
	this->decks = decks;
	deck.reserve(decks * 52);
	//fill deck with cards 2-10, 4 each per deck
	for (int i = 2; i < 11; ++i) {
		for (int j = 0; j < (4*decks); ++j) {
			deck.push_back(std::to_string(i));
		}
	}
	//fill deck with cards J,Q,K,A, 4 per deck
	for (int i = 0; i < (4 * decks); ++i) {
		deck.push_back("J");
		deck.push_back("Q");
		deck.push_back("K");
		deck.push_back("A");
	}
	this->shuffle();
}

void Deck::shuffle() {
	std::default_random_engine engine;
	engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::shuffle(deck.begin(), deck.end(), engine);
}

//draws card from end of vector
std::string Deck::draw_card() {
	std::string card = deck.back();
	deck.pop_back();
	return card;
}

int Deck::size() {
	return deck.size();
}
