#pragma once
#include<string>

class Card {
public:
	Card(int rank, int suit); 
	Card();  //delete?
	std::string getName();
	int getRank();
	int getSuit();

	bool operator< (const Card &other) const {
		return rank < other.rank;
	}

private:
	int rank;
	int suit;	//Heart♥, Diamond♦, Club♣, Spade♠
};