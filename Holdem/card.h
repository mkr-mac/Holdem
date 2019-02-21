#pragma once
#include<string>

class Card {
public:
	Card(int rank, int suit); 
	Card();
	std::string getName();
	int getRank();
	int getSuit();
private:
	int rank;
	int suit;	//Heart♥, Diamond♦, Club♣, Spade♠
	std::string name;
};