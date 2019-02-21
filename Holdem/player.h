#pragma once
#include "deck.h"

class Player {
public:
	Player(int id);
	void				getCard(Card c);
	std::string			printHand();
	void				emptyHand();
	std::vector<Card>	getHand();
	int					getId();
	std::vector<int>    score{ 0,0,0,0,0,0 };

private:
	int					id;
	int					funds;
	std::vector<Card> 	hand;
};