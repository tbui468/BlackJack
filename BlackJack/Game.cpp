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
		std::cout << std::endl;

		deck.initialize_deck();
		player.clear_hand();
		house.clear_hand();
		player.hit(deck);
		house.hit(deck);
		player.hit(deck);
		house.hit(deck);
		
		Round round(deck, player, house);

		//make bet here
		int bet;
		std::cout << "Money remaining: " << player.get_money() << std::endl;
		std::cout << "Make bet ($1 - $5) > ";
		std::cin >> bet;
		if (bet < 1) bet = 1;
		if (bet > 5) bet = 5;
		std::cout << std::endl;
		int winnings = round.start_round(bet);
		int money = player.get_money();
		player.set_money(money + winnings);
		std::cout << "Money remaining: " << player.get_money() << std::endl << std::endl;

		std::cout << "1. Play   2. Quit    > ";
		std::cin >> play;
	} while (play == 1);

}