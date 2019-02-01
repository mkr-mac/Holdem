#pragma once
#include "deck.h"

class Player {
public:
	Player(int id);
	int id;
	void getCard(Card c);
	std::string printHand();
	void emptyHand();

private:
	std::vector<Card> hand;
	int funds;
};