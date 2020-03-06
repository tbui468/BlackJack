#pragma once
#include <fstream> // to read and write to text files
#include "Deck.h"
#include "Player.h"
#include "Round.h"



class Game
{
private:
	static const int deck_number = 1;
	Deck deck;
	Player player;
	Player house;
public:
	Game();
	void start_game();
};

