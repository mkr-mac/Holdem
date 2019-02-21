#include "adjudicator.h"

std::vector<Card> h(5);

std::vector<int> Adjudicator::handValue(std::vector<Card> publicHand, std::vector<Card> playerHand) {
	//make one big hand to mess with
	std::vector<Card> bigHand(7);
	std::merge(publicHand.begin(), publicHand.end(), playerHand.begin(), playerHand.end(), bigHand);

	std::vector<int> score { 0, 0, 0, 0, 0, 0 };

	h.clear();

	std::sort(bigHand.begin(), bigHand.end());

	combinationChecker(bigHand, score);

	return score;
}

void combinationChecker(std::vector<Card> bh, std::vector<int> score, int off = 0, int k = 5) {

	if (k == 0) {
		checkHand(h, score);
		std::vector<Card> t_h(5);
		std::reverse_copy(h.begin(), h.end(), t_h);
		checkHand(t_h, score);
		return;
	}
	for (int i = off; i <= bh.size() - k; ++i) {
		h.push_back(bh[i]);
		combinationChecker(bh, score, i + 1, k - 1);
		h.pop_back();
	}
}

void checkHand(std::vector<Card> h, std::vector<int> score) {

	// cool
	switch (score[0]) {
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
		return;
	default:
		// Let's not end up here
		printf("ERROR: Adjudicator case default statement reached.");
		break;
	}
}

void royalFlush(std::vector<Card> hand, std::vector<int> score) {
	int r = hand[0].getRank();
	if (r!=12) { return; }

	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) || 
			(hand[i].getRank() != r - i)) { return; }
	}
	
	score = { 9, 0, 0, 0, 0, 0 };
}

void straightFlush(std::vector<Card> hand, std::vector<int> score) {
	int r = hand[0].getRank();
	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) ||
			(hand[i].getRank() != r - i)) { return; }
	}

	score = { 8, r, 0, 0, 0, 0 };
}

void fourOfAKind(std::vector<Card> hand, std::vector<int> score) {
	int r = hand[0].getRank();

	for (int i = 1; i < 4; ++i) {
		if (hand[i].getRank() != r) { return; }
	}

	score = { 7, r, hand[4].getRank(), 0, 0, 0 };
}

void fullHouse(std::vector<Card> hand, std::vector<int> score) {
	int r = hand[0].getRank();

	for (int i = 1; i < 3; ++i) {
		if (hand[i].getRank() != r) { return; }
	}

	if (hand[3].getRank() != hand[4].getRank()) { return; }

	score = { 6, r, hand[3].getRank(), 0, 0, 0 };
}

void flush(std::vector<Card> hand, std::vector<int> score) {
	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) ||
			(hand[i].getRank() >= hand[i-1].getRank())) { return; }
	}

	score = { 5, 0, 0, 0, 0, 0 };
	std::merge(score.begin(), score.begin() + 1, hand.begin(), hand.end(), score);
}

void straight(std::vector<Card> hand, std::vector<int> score) {
	int r = hand[0].getRank();

	for (int i = 1; i < 5; ++i) {
		if (hand[i].getRank() != r - i) { return; }
	}

	score = { 4, r, 0, 0, 0, 0 };
}

//bugged
void threeOfAKind(std::vector<Card> hand, std::vector<int> score) {
	int r = hand[0].getRank();

	for (int i = 1; i < 3; ++i) {
		if (hand[i].getRank() != r) { return; }
	}

	score = { 7, r, std::max(hand[4].getRank(), hand[5].getRank()), std::min(hand[4].getRank(), hand[5].getRank()), 0, 0 };
}