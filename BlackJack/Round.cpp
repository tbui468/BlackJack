#include "Round.h"

Round::Round() : deck(deck_number), player(deck), house(deck) {
	int choice;
	display_cards();

	while (!player.get_hand().bust())
	{
		std::cout << "1. Hit  2. Stand" << std::endl;
		std::cout << "Enter choice > " << std::flush;
		std::cin >> choice;
		std::cout << std::endl << std::endl;
		if (choice == 1) {
			player.hit(deck);
			display_cards();
		}
		else {
			break;
		}
	}
	if (player.get_hand().bust()) {
		std::cout << "You lost!" << std::endl;
	}else{
		while (house.get_hand().calculate_hand() < 17) {
			house.hit(deck);
		}
		//check if player or house won
		round_end = true;
		display_cards();
		
		if (house.get_hand().bust()) {
			std::cout << "You won!" << std::endl;
		}else if (house.get_hand().calculate_hand() > player.get_hand().calculate_hand()) {
			std::cout << "You lost!" << std::endl;
		}
		else if (house.get_hand().calculate_hand() < player.get_hand().calculate_hand()) {
			std::cout << "You won!" << std::endl;
		}
		else {
			std::cout << "It's a tie!" << std::endl;
		}
	}

}

Deck Round::get_deck() {
	return deck;
}

House Round::get_house() {
	return house;
}

void Round::display_cards() {
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
	//will only display one card during player turn
	std::cout << "House cards" << std::endl;
	std::cout << "***********" << std::endl;
	Hand hand = house.get_hand();
	std::vector<std::string> cards = hand.get_cards();

	for (unsigned int i = 0; i < cards.size(); ++i) {
		if (i == 1 && !round_end) {
			std::cout << "?" << std::endl;
			break;
		}
		std::cout << cards[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Deck" << std::endl;
	std::cout << "****" << std::endl;
	std::cout << deck.size() << std::endl;
}

bool Round::has_blackjack(Player player) {
	return true;
}

bool Round::has_blackjack(House house) {
	return true;
}
