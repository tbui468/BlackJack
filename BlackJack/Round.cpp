#include <sstream>
#include "Round.h"


const std::string Round::lost_message = "You lost!";
const std::string Round::won_message = "You won!";
const std::string Round::tied_message = "You tied!";
const std::string Round::blackjack_message = "Blackjack!";

Round::Round(Deck &deck, Player &player, Player &house ): deck(deck), player(player), house(house) {
	card_back.push_back("**********");
	card_back.push_back("* ****** *");
	card_back.push_back("* ****** *");
	card_back.push_back("* ****** *");
	card_back.push_back("* ****** *");
	card_back.push_back("* ****** *");
	card_back.push_back("**********");

}

int Round::start_round(int bet) {
	int choice;

	bool player_blackjack = has_blackjack(player.get_hand());
	bool house_blackjack = has_blackjack(house.get_hand());

	//print_card(card_back);


	//checks for blackjacks after dealing
	if (player_blackjack || house_blackjack) {
		round_end = true;
		display_cards();
		std::cout << blackjack_message << std::endl;
		if (player_blackjack && !house_blackjack) return won(bet);
		else if (!player_blackjack && house_blackjack) return lost(bet);
		else return tied(bet);
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
			std::cout << std::endl;
			if (choice == 1) { //hit
				player.hit(deck);
				display_cards();
			}
			else if (player.get_hand().size() == 2 && choice == 3) { //double down
				bet = (bet * 2);
				player.hit(deck);
				if(player.get_hand().bust()) display_cards();
				break;
			}
			else { //stand
				break;
			}
		}
		if (player.get_hand().bust()) {
			return lost(bet);
		}
		else {
			while (house.get_hand().calculate_hand() < 17) {
				house.hit(deck);
				std::cout << "House draws a card" << std::endl;
			}
			std::cout << std::endl;
			//check if player or house won
			round_end = true;
			display_cards();

			int house_score = house.get_hand().calculate_hand();
			int player_score = player.get_hand().calculate_hand();

			if (house.get_hand().bust()) {
				return won(bet);
			}
			else if (house_score > player_score) {
				return lost(bet);
			}
			else if (house_score < player_score) {
				return won(bet);
			}
			else {
				return tied(bet);
			}
		}
	}

}

Deck Round::get_deck() {
	return deck;
}

void Round::display_player_cards(Player player, bool hide_card) {
	std::cout << player.get_name() << " cards" << std::endl;
	std::cout << std::endl;

	print_cards(player.get_hand(), hide_card);
}


void Round::display_cards() {


	//House goes second
	//will only display one card during player turn
	display_player_cards(house, !round_end);
	std::cout << std::endl;

	//player goes first
	display_player_cards(player, false);
	
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

int Round::won(int bet) {
	std::cout << won_message << std::endl;
	return (bet);
}

int Round::lost(int bet) {
	std::cout << lost_message << std::endl;
	return (-1*bet);
}

int Round::tied(int bet) {
	std::cout << tied_message << std::endl;
	return 0;
}



void Round::print_cards(Hand hand, bool hide_card) {
	pic cards;
	//makes ASCII card pictures from Hand hand and concatenates horizontally
	for (unsigned int row = 0; row < 7; ++row) {
		std::stringstream ss;
		for (unsigned int i = 0; i < hand.get_cards().size(); ++i) {
			std::string value = (hand.get_cards())[i];
			switch (row) {
			case 0:
				ss << " ********** ";
				break;
			case 1:
				ss << " * ";
				if (hide_card && i == 1) ss << "******";
				else if (value == "10") ss << "10  10";
				else ss << value << "    " << value;
				ss << " * ";
				break;
			case 2:
				if (hide_card && i == 1) ss << " * ****** * ";
				else ss << " *        * ";
				break;
			case 3:
				if (hide_card && i == 1) ss << " * ****** * ";
				else ss << " *        * ";
				break;
			case 4:
				if (hide_card && i == 1) ss << " * ****** * ";
				else ss << " *        * ";
				break;
			case 5:
				ss << " * ";
				if (hide_card && i == 1) ss << "******";
				else if (value == "10") ss << "10  10";
				else ss << value << "    " << value;
				ss << " * ";
				break;
			case 6:
				ss << " ********** ";
				break;
			default:
				break;
			}

		}
		cards.push_back(ss.str());
	}

	print_pic(cards);
}

void Round::print_pic(pic pic) {
	for (unsigned int i = 0; i < pic.size(); ++i) {
		std::cout << pic[i] << std::endl;
	}
}