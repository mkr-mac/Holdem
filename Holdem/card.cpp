#include "card.h"

const std::string r = "23456789TJQKA";
const std::string s = "HDCS";	//"♥♦♣♠";

Card::Card(int rank, int suit) {
	this->rank = rank;
	this->suit = suit;
};

Card::Card() {
	//PLZ NO
}

std::string Card::getName() {
	return "[" + r.substr(rank, 1) + s.substr(suit, 1) + "]";
};

int Card::getRank() {
	return rank;
}

int Card::getSuit() {
	return suit;
}