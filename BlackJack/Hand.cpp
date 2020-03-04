#include "Hand.h"

Hand::Hand(){
}

//puts all Aces at end of cards<std::string> so calculate_hand() works properly
void Hand::sort_hand() {
	int aces = 0;
	//delete all aces
	for (unsigned int i = 0; i < cards.size(); ++i) {
		if (cards[i] == "A") {
			aces += 1;
			cards.erase(cards.begin()+i);
			--i;
		}
	}
	//add aces to back of vector
	while (aces > 0) {
		cards.push_back("A");
		--aces;
	}

}

//calculate sum of all cards in hand
//J,Q,K = 10.  A = 1 or 11, to get as close to 21 as possible, without exceeding 21
//sort array so that all aces are in the end of cards[]
int Hand::calculate_hand() {
	sort_hand();
	int sum = 0;
	for (unsigned int i = 0; i < cards.size(); ++i) {
		sum += get_value(cards[i], sum);
	}
	return sum;
}

void Hand::add_card(std::string new_card) {
	this->cards.push_back(new_card);
}

void Hand::remove_card(std::string card) {

}



int Hand::get_value(std::string card, int sum) {
	if (card.compare("K") == 0 || card.compare("Q") == 0 || card.compare("J") == 0)
		return 10;
	else if (card.compare("A") == 0) {
		if ((sum + 11) > 21)
			return 1;
		else
			return 11;
	}
	else
		return std::stoi(card);
}

bool Hand::bust() {
	return (this->calculate_hand() > 21);
}

int Hand::size() {
	return cards.size();
}

std::vector<std::string> Hand::get_cards() {
	return cards;
}

void Hand::clear_hand() {
	cards.clear();
}