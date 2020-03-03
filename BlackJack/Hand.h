#ifndef HAND_H_
#define HAND_H_
#pragma once

#include <vector>
#include <string>

class Hand {
private:
	std::vector<std::string> cards;
	int get_value(std::string card, int sum);
	void sort_hand();
public:
	Hand();
	void add_card(std::string new_card);
	void remove_card(std::string card);
	int calculate_hand();
	bool bust();
	int size();
	std::vector<std::string> get_cards();
};



#endif