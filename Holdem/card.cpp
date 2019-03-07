#include "card.h"

const std::string Card::r = "23456789TJQKA";
const std::string Card::s = "HDCS";	//"♥♦♣♠"

Card::Card(int rank, int suit) {
	this->rank = rank;
	this->suit = suit;
};

Card::Card() {
	//PLZ NO
}

const std::string Card::getName() {
	return "[" + r.substr(rank, 1) + s.substr(suit, 1) + "]";
};

const int Card::getRank() {
	return rank;
}

const int Card::getSuit() {
	return suit;
}