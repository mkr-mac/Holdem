
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

	for (Player q : players) {
		for (int c = 0; c < 2; ++c) {
			q.getCard(d.deal());
		}
		//std::cout << q.printHand() << "\n";
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
		std::string a = p.printHand();

		std::cout << a << std::endl;

		p.score = adj.handValue(publicHand, p.getHand());
		std::cout << "Score: ";
		for (int i : p.score) {
			std::cout << std::to_string(i) + ", ";
		}
		std::cout << "\n";
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu