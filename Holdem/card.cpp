#include "card.h"

const std::string r = "23456789TJQKA";
const std::string s = "HDCS";	//"♥♦♣♠";

Card::Card(int rank, int suit) {
	this->rank = rank;
	this->suit = suit;
	name = "[" + r.substr(this->rank, 1) + s.substr(this->suit, 1) + "]";
};

Card::Card() {
	//PLZ NO
}

std::string Card::getName() {
	return name;
};