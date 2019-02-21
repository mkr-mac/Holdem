#include "adjudicator.h"

std::vector<Card> h(5);

std::vector<int> Adjudicator::handValue(std::vector<Card> publicHand, std::vector<Card> playerHand) {
	//make one big hand to mess with
	std::vector<Card> bigHand;

	for (Card c : publicHand) {
		bigHand.push_back(c);
	}
	for (Card d : playerHand) {
		bigHand.push_back(d);
	}

	std::vector<int> score { 0, 0, 0, 0, 0, 0 };

	h.clear();

	std::sort(bigHand.begin(), bigHand.end());

	return combinationChecker(bigHand, score);
}

std::vector<int> Adjudicator::combinationChecker(std::vector<Card> bh, std::vector<int> score, int off, int k) {

	if (k == 0) {
		checkHand(h, score);
		std::vector<Card> t_h(5);
		std::reverse_copy(h.begin(), h.end(), t_h.begin());
		checkHand(t_h, score);
		return;
	}
	for (int i = off; i <= bh.size() - k; ++i) {
		h.push_back(bh[i]);
		combinationChecker(bh, score, i + 1, k - 1);
		h.pop_back();
	}
}

std::vector<int> Adjudicator::checkHand(std::vector<Card> h, std::vector<int> score) {

	// cool
	switch (score[0]) {
	case 0:
		junkHighCard(h);
	case 1:
		pair(h);
	case 2:
		twoPair(h);
	case 3:
		threeOfAKind(h);
	case 4:
		straight(h);
	case 5:
		flush(h);
	case 6:
		fullHouse(h);
	case 7:
		fourOfAKind(h);
	case 8:
		straightFlush(h);
		royalFlush(h);
		break;
	case 9:
		// Royal flush was achieved.
		// Go home my boy, you can do no better.
		return score;
	default:
		// Let's not end up here
		printf("ERROR: Adjudicator case default statement reached.");
		break;
	}
}

std::vector<int> Adjudicator::royalFlush(std::vector<Card> hand) {
	int r = hand[0].getRank();
	if (r!=12) { return; }

	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) || 
			(hand[i].getRank() != r - i)) { return; }
	}
	
	return { 9, 0, 0, 0, 0, 0 };
}

std::vector<int> Adjudicator::straightFlush(std::vector<Card> hand) {
	int r = hand[0].getRank();
	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) ||
			(hand[i].getRank() != r - i)) { return; }
	}

	return { 8, r, 0, 0, 0, 0 };
}

std::vector<int> Adjudicator::fourOfAKind(std::vector<Card> hand) {
	int r = hand[0].getRank();

	for (int i = 1; i < 4; ++i) {
		if (hand[i].getRank() != r) { return; }
	}

	return { 7, r, hand[4].getRank(), 0, 0, 0 };
}

std::vector<int> Adjudicator::fullHouse(std::vector<Card> hand) {
	int r = hand[0].getRank();

	for (int i = 1; i < 3; ++i) {
		if (hand[i].getRank() != r) { return; }
	}

	if (hand[3].getRank() != hand[4].getRank()) { return; }

	return { 6, r, hand[3].getRank(), 0, 0, 0 };
}

std::vector<int> Adjudicator::flush(std::vector<Card> hand) {
	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) ||
			(hand[i].getRank() >= hand[i-1].getRank())) { return; }
	}

	return { 5, hand[0].getRank(), hand[1].getRank(), hand[2].getRank(),
				hand[3].getRank(), hand[4].getRank() };
}

std::vector<int> Adjudicator::straight(std::vector<Card> hand) {
	int r = hand[0].getRank();

	for (int i = 1; i < 5; ++i) {
		if (hand[i].getRank() != r - i) { return; }
	}

	return { 4, r, 0, 0, 0, 0 };
}

std::vector<int> Adjudicator::threeOfAKind(std::vector<Card> hand) {

	if (hand[0].getRank() == hand[1].getRank() &&
		hand[1].getRank() == hand[2].getRank()) {
		 return {	3, hand[0].getRank(), std::max(hand[3].getRank(), hand[4].getRank()),
					std::min(hand[3].getRank(), hand[4].getRank()), 0, 0 };
	}
	else if (hand[1].getRank() == hand[2].getRank() &&
			hand[2].getRank() == hand[3].getRank()) {
		 return {	3,
					hand[1].getRank(), 
					std::max(hand[0].getRank(), hand[4].getRank()),
					std::min(hand[0].getRank(), hand[4].getRank()), 
					0, 0 };
	}
	return;
}

std::vector<int> Adjudicator::twoPair(std::vector<Card> hand) {

	if ((hand[0].getRank() == hand[1].getRank()) &&
		(hand[2].getRank() == hand[3].getRank())) {

		return {	2,
					std::max(hand[0].getRank(), hand[2].getRank()), 
					std::min(hand[0].getRank(), hand[2].getRank()),
					hand[4].getRank(), 0, 0 };
	}

	else if ((hand[0].getRank() == hand[1].getRank()) &&
		(hand[3].getRank() == hand[4].getRank())) {
		 return {	2,
					std::max(hand[0].getRank(), hand[3].getRank()),
					std::min(hand[0].getRank(), hand[3].getRank()),
					hand[2].getRank(), 0, 0 };
	}

	else if ((hand[1].getRank() == hand[2].getRank()) &&
		(hand[3].getRank() == hand[4].getRank())) {

		 return { 2,
					std::max(hand[1].getRank(), hand[3].getRank()),
					std::min(hand[1].getRank(), hand[3].getRank()),
					hand[0].getRank(), 0, 0 };
	}
	return;
}

std::vector<int> Adjudicator::pair(std::vector<Card> hand) {
	for (int i = 0; i < 4; ++i) {
		if (hand[i].getRank() == hand[i + 1].getRank()) {
			return { 1, hand[i].getRank(), 0, 0, 0, 0 };
		}
	}
	return;
}

std::vector<int> Adjudicator::junkHighCard(std::vector<Card> hand) {
	
	if (hand[0].getRank() >= hand[4].getRank()) {
		return { 0, hand[0].getRank(), hand[1].getRank(), hand[2].getRank(),
					hand[3].getRank(), hand[4].getRank() };
	}
}
