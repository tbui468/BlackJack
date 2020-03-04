//player bets and decisions

#include "Player.h"

Player::Player(Deck &deck) {
	hit(deck);
	hit(deck);
}

void Player::hit(Deck &deck) {
	hand.add_card(deck.draw_card());
}

void Player::stand() {
	current_turn = false;
}

void Player::double_down(Deck& deck) {
	hand.add_card(deck.draw_card());
	current_turn = false;
}

Hand Player::get_hand() {
	return hand;
}



