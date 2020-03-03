//basic AI for house

#include "House.h"

House::House(Deck &deck) {
	hand.add_card(deck.draw_card());
	hand.add_card(deck.draw_card());
}

void House::stand() {

}

void House::hit(Deck &deck) {
	hand.add_card(deck.draw_card());
}

House::Action House::next_move() {
	int sum = hand.calculate_hand();
	if (sum < 17)
		return House::Action::HIT;
	else
		return House::Action::STAND;
}