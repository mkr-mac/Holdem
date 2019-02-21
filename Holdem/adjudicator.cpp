#include "adjudicator.h"

std::vector<int> Adjudicator::handValue(std::vector<Card> publicHand, std::vector<Card> playerHand) {
	//make one big hand to mess with
	std::vector<Card> bigHand(7);
	std::merge(publicHand.begin(), publicHand.end(), playerHand.begin(), playerHand.end(), bigHand);

	// Hand being tested
	std::vector<Card> h(5);

	std::vector<int> score { 0, 0, 0, 0, 0, 0 };

	// There are 2520 hand combinations.
	// We only need to try every 4th because of the way
	// next_permutation operates.
	for (int i = 0; i < 630; ++i) {
		// Get slice of the vector
		std::copy(bigHand.begin(), bigHand.begin() + 5, h.begin());

		// This is gonna be cool
		switch (score.at(0)) {
		case 0:
			junkHighCard(h, score);
		case 1:
			pair(h, score);
		case 2:
			twoPair(h, score);
		case 3:
			threeOfAKind(h, score);
		case 4:
			straight(h, score);
		case 5:
			flush(h, score);
		case 6:
			fullHouse(h, score);
		case 7:
			fourOfAKind(h, score);
		case 8:
			straightFlush(h, score);
			royalFlush(h, score);
			break;
		case 9:
			// Royal flush was achieved.
			// Go home my boy, you can do no better.
			return score;
			break;
		default:
			// Let's not end up here
			printf("ERROR: Adjudicator case default statement reached.");
			break;
		}
		for (int p = 0; p < 4; ++p) {
			std::next_permutation(bigHand.begin(), bigHand.end());
		}
	}

	return score;
}


void royalFlush(std::vector<Card> hand, std::vector<int> score) {
	int r = hand.at(0).getRank();
	if (r!=12) { return; }

	int s = hand.at(0).getSuit();

	for (int i = 1; i < 5; ++i) {
		if (!(hand.at(i).getSuit() == s) || 
			!(hand.at(i).getRank() == r - i)) { return; }
	}
	
	score = { 9, 0, 0, 0, 0, 0 };
}

void straightFlush(std::vector<Card> hand, std::vector<int> score) {
	int r = hand.at(0).getRank();
	int s = hand.at(0).getSuit();

	for (int i = 1; i < 5; ++i) {
		if (!(hand.at(i).getSuit() == s) ||
			!(hand.at(i).getRank() == r - i)) { return; }
	}

	if (score.at(1) < r) {
		score = { 8, r, 0, 0, 0, 0 };
	}
}

void fourOfAKind(std::vector<Card> hand, std::vector<int> score) {
	int r = hand.at(0).getRank();

	for (int i = 1; i < 4; ++i) {
		if (!(hand.at(i).getRank() == r)) { return; }
	}

	if (score.at(1) < r) {
		score = { 7, r, hand.at(4).getRank(), 0, 0, 0 };
	}
}