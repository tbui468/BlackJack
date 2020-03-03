//player bets and decisions

#include "Player.h"

Player::Player(Deck &deck) {
	hit(deck);
	hit(deck);
}

void Player::hit(Deck &deck) {
	hand.add_card(deck.draw_card());
}

Hand Player::get_hand() {
	return hand;
}