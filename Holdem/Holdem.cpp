
//
//#include "pch.h"
#include <iostream>
#include "player.h"
#include "adjudicator.h"

int main(){
	system("CLS");
	std::cout << "Welcome to Holdem!\n\n";
	std::cout << "How many players? ";

	//int sockfd = socket(domain, type, protocol);

	int n = 0;
	while(n<1){
		std::cin >> n;
	}
	
	std::vector<Player> players;
	for (int i = 0; i < n; ++i) {
		players.push_back(Player(i));
	}

	Deck d = Deck();
	d.shuffle();

	std::vector<Card> publicHand;

	for (Player p : players) {
		for (int c = 0; c < 2; ++c) {
			p.getCard(d.deal());
		}
		std::cout << p.printHand() << "\n";
	}

	for (int c = 0; c < 5; ++c) {
		publicHand.push_back(d.deal());
	}

	std::string h = "";

	for (Card c : publicHand) {
		h += c.getName();
	}

	Adjudicator adj = Adjudicator();
	
	std::cout << "Public: " << h << std::endl;

	
	for (Player p : players) {
		std::cout << "Player " << std::to_string(p.getId()) << ": " ;
		std::cout << p.printHand() << std::endl;
		p.score = adj.handValue(publicHand, p.getHand());
		std::cout << "Score: ";
		for (int i : p.score) {
			std::cout << std::to_string(i) + ", ";
		}
		std::cout << "\n";
	}

	for (Player p : players) {

	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
