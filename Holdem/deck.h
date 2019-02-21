#pragma once
#include "card.h"
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>

class Deck {
public:
	Deck();
	Card deal();
	void shuffle();
	void cut();
private:
	std::vector<Card> cards;
};