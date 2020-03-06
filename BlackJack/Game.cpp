//Game class.  Each game is comprised of multiple rounds
//the deck is replenished after each round, and new bets place

#include "Game.h"
#include <fstream>
#include <map>

Game::Game(): deck(DECK_NUMBER), player(deck), house(deck) {
	//load profile
	std::cout << "Welcome to Blackjack!" << std::endl << std::endl;

	bool previous_profile = false;
	std::ifstream my_file("profiles.txt");
	std::string line;
	std::string name;
	int money;
	while (std::getline(my_file,line)) {
		previous_profile = true;
		name = line;
		std::getline(my_file, line);
		money = std::stoi(line);
		if (money <= 0) money = 100;
	}

	int choose = 0;
	if (previous_profile) {
		std::cout << "1. Load previous profile  2. Create new profile  > " << std::flush;
		std::cin >> choose;
	}
	if(!previous_profile || choose == 2) {
		std::cout << "Enter your name > " << std::flush;
		std::cin >> name;
		money = 100;
	}

	player.set_name(name);
	player.set_money(money); //default money
	house.set_name("House");
}

void Game::start_game() {

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
		//save profile
		std::ofstream my_file("profiles.txt");
		if (my_file.is_open()) {
			my_file << player.get_name() << "\n";
			my_file << player.get_money();
			my_file.close();
		}
	} while (play == 1);

}