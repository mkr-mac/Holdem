#pragma once
#include<string>

class Card {
public:
	Card(int rank, int suit); 
	Card();  //delete?
	const int getRank();
	const int getSuit();

	const std::string getName();	// [8D] is 8 of diamonds

	bool operator< (const Card &other) const {
		return rank < other.rank;
	}

private:
	int rank;
	int suit;	// Heart♥, Diamond♦, Club♣, Spade♠
	const static std::string r;
	const static std::string s;	// "♥♦♣♠"
};