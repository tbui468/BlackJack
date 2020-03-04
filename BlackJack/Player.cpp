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
}

void Player::double_down(Deck& deck) {
	hand.add_card(deck.draw_card());
}

Hand Player::get_hand() {
	return hand;
}

void Player::set_name(std::string name) {
	this->name = name;
}

std::string Player::get_name() {
	return name;
}

void Player::set_money(int money) {
	this->money = money;
}

int Player::get_money() {
	return money;
}

void Player::set_bet(int bet) {
	this->bet = bet;
}

int Player::get_bet() {
	return bet;
}