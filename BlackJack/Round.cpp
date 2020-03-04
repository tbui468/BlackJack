#include "Round.h"

const std::string Round::lost_message = "You lost!";
const std::string Round::won_message = "You won!";
const std::string Round::tied_message = "You tied!";
const std::string Round::blackjack_message = "Blackjack!";

Round::Round() : deck(deck_number), player(deck), house(deck) {
	house.set_name("House");
}

void Round::start_round() {
	int choice;

	bool player_blackjack = has_blackjack(player.get_hand());
	bool house_blackjack = has_blackjack(house.get_hand());

	//checks for blackjacks after dealing
	if (player_blackjack || house_blackjack) {
		round_end = true;
		display_cards();
		if (player_blackjack && !house_blackjack) std::cout << won_message << std::endl;
		else if (!player_blackjack && house_blackjack) std::cout << lost_message << std::endl;
		else std::cout << tied_message << std::endl;
	}
	else {
		//player turn
		display_cards();
		while (!player.get_hand().bust())
		{
			std::cout << "1. Hit  2. Stand";
			if (player.get_hand().size() == 2) std::cout << "  3. Double down";
			std::cout << std::endl;
			std::cout << "Enter choice > " << std::flush;
			std::cin >> choice;
			std::cout << std::endl << std::endl;
			if (choice == 1) { //hit
				player.hit(deck);
				display_cards();
			}
			else if (player.get_hand().size() == 2 && choice == 3) { //double down
				player.hit(deck);
				display_cards();
				break;
			}
			else { //stand
				break;
			}
		}
		if (player.get_hand().bust()) {
			std::cout << lost_message << std::endl;
		}
		else {
			while (house.get_hand().calculate_hand() < 17) {
				house.hit(deck);
			}
			//check if player or house won
			round_end = true;
			display_cards();

			int house_score = house.get_hand().calculate_hand();
			int player_score = player.get_hand().calculate_hand();

			if (house.get_hand().bust()) {
				std::cout << won_message << std::endl;
			}
			else if (house_score > player_score) {
				std::cout << lost_message << std::endl;
			}
			else if (house_score < player_score) {
				std::cout << won_message << std::endl;
			}
			else {
				std::cout << tied_message << std::endl;
			}
		}
	}

}

Deck Round::get_deck() {
	return deck;
}

void Round::display_player_cards(Player player, bool hide_card) {
	std::cout << player.get_name() << " cards" << std::endl;
	std::cout << "**********" << std::endl;
	Hand player_hand = player.get_hand();
	std::vector<std::string> player_cards = player_hand.get_cards();
	for (unsigned int i = 0; i < player_cards.size(); ++i) {
		if (i == 1 && hide_card) {
			std::cout << "?" << std::endl;
			break;
		}
		std::cout << player_cards[i] << std::endl;
	}
}


void Round::display_cards() {
	//player goes first
	display_player_cards(player, false);

	std::cout << std::endl;

	//House goes second
	//will only display one card during player turn
	display_player_cards(house, !round_end);

	std::cout << std::endl;


}



bool Round::has_blackjack(Hand hand) {
	if (hand.size() > 2) return false;
	std::vector<std::string> c = hand.get_cards();
	std::string a = c[0];
	std::string b = c[1];
	if (a == "A" && (b == "10" || b == "J" || b == "Q" || b == "K"))
		return true;
	if (b == "A" && (a == "10" || a == "J" || a == "Q" || a == "K"))
		return true;
	return false;
}
