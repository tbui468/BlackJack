//Game class.  Each game is comprised of multiple rounds
//the deck is replenished after each round, and new bets place

#include "Game.h"

Game::Game(): deck(deck_number), player(deck), house(deck) {
	house.set_name("House");
	player.set_money(100); //default money
}

void Game::start_game() {

	std::cout << "Welcome to BlackJack!" << std::endl;
	int play;
	do {
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
		
		Round round(deck, player, house);
		//need to remove cards from player and house, and remake a new deck!!!!!!!!!!!!!
		round.start_round();
		std::cout << deck.size();
		std::cout << "1. Play   2. Quit    > " << std::endl;
		std::cin >> play;
	} while (play == 1);

}