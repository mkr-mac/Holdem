#include "deck.h"

Deck::Deck() {
	for (int r=0; r<13; ++r) {
		for (int s=0; s<4; ++s) {
			cards.emplace_back(r, s);
		}
	}
};

Card Deck::deal() {
	Card c = cards[cards.size()-1];
	cards.pop_back();
	return c;
}

void Deck::shuffle() {
	std::random_shuffle(cards.begin(), cards.end());
}

void Deck::randomSwap() {
	std::swap(cards[rand()%cards.size()], cards[rand() % cards.size()]);
}

void Deck::cut() {
	// Not yet. Why does a virtual deck need cut?
}