
//
//#include "pch.h"
#include <iostream>
#include "player.h"
#include "adjudicator.h"
#include "config.h"

#ifndef TEST

int main(){
	system("CLS");
	std::cout << "Welcome to Holdem!" << std::endl << std::endl;
	std::cout << "How many players? ";

	//int sockfd = socket(domain, type, protocol);

	int n = 0;
	while(n<1 || n>=10){
		std::cin >> n;
	}
	
	std::vector<Player> players;

	for (int i = 0; i < n; ++i) {
		players.emplace_back(i);
	}

	std::cout << "How many games? ";

	int games = 0;
	while (games < 1 || games>99) {
		std::cin >> games;
	}

	std::system("CLS");

	while (games > 0) {

		Deck d;
		d.shuffle();

		// TODO: Ante

		for (Player& p : players) {
			for (int c = 0; c < 2; ++c) {
				p.giveCard(d.deal());
			}
		}

		std::vector<Card> communityCards;
		
		for (int br = 0; br < 4; ++br) {
			// TODO: Betting round here

			// Cards dealt by round
			switch (br) {
			case 0:
				// Pre-flop
				break;
			case 1:
				// Flop
				for (int c = 0; c < 3; ++c) { communityCards.push_back( d.deal() ); }
				break;
			case 2:
				// Turn
			case 3:
				// River
				communityCards.push_back( d.deal() );
				break;
			}

			std::string h = "";
			for (Card& c : communityCards) {
				h += c.getName();
			}

			std::cout << "Community: " << h << std::endl << std::endl;

			for (Player& p : players) {
				std::cout << "Player " << std::to_string(p.getId()) << ": "  << p.printHand() << std::endl << std::endl;
			}

			std::cin.get();

			std::system("CLS");
		}

		std::string h = "";
		for (Card& c : communityCards) { h += c.getName(); }
		std::cout << "Community: " << h << std::endl << std::endl;

		for (Player& p : players) {
			std::cout << "Player " << std::to_string(p.getId()) << ": " << p.printHand() << std::endl;

			p.score = Adjudicator::handValue(communityCards, p.getHand());
			std::cout << "Score:    ";
			for (int i : p.score) {
				std::cout << std::to_string(i) + ", ";
			}
			std::cout << std::endl;
			p.emptyHand();
		}

		std::cin.get();

		std::system("CLS");

		--games;
		
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#endif // !1