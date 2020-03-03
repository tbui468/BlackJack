#include "Round.h"

Round::Round() : deck(deck_number), house(deck) {
	house.hit(deck);
}

Deck Round::get_deck() {
	return deck;
}

House Round::get_house() {
	return house;
}