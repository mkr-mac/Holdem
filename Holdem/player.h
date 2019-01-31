#pragma onceu
#include "deck.h"

class Player {
public:
	Player(int id);
	int id;
	void getCard(Card c);
private:
	std::vector<Card> hand;
};