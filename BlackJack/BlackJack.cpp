// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
#include "Hand.h"
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include "Round.h"

int main()
{
	Deck deck1(1);
	Deck deck2(2);
	Deck deck3(3);
	Deck deck4(4);

	while (deck1.size() > 0) {
		std::cout << deck1.draw_card() << std::flush;
	}

	std::cout << std::endl << deck1.size();
	std::cout << std::endl << deck2.size();
	std::cout << std::endl << deck3.size();
	std::cout << std::endl << deck4.size();

	std::cout << "Hello World!" << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
