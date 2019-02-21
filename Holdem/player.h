#pragma once
#include "deck.h"

class Player {
public:
	Player(int id);
	int id;
	void getCard(Card c);
	std::string printHand();
	void emptyHand();
	std::vector<int> bestHandValue(std::vector<Card> publicHand);
	std::vector<Card> hand;

private:
	int funds;
};