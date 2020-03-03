#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

class Deck
{
private:
	int decks;
	std::vector<std::string> deck;
public:
	Deck(int decks = 1);
	void shuffle();
	std::string draw_card();
	int size();
};

