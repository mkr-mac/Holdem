#include "adjudicator.h"

std::vector<Card> Adjudicator::h(5);
//std::vector<Card> Adjudicator::r_h(5);
std::vector<int> Adjudicator::score;

std::vector<int> Adjudicator::handValue(const std::vector<Card>& communityCards, const std::vector<Card>& playerHand) {
	//make one big hand to mess with

	std::vector<Card> bigHand = communityCards;

	for (Card d : playerHand) {
		bigHand.emplace_back(d.getRank(), d.getSuit());
	}

	score.clear();
	h.clear();
	//r_h.clear();


	std::sort	(bigHand.begin(), bigHand.end());
	std::reverse(bigHand.begin(), bigHand.end());

	junkHighCard(bigHand);

	combinationChecker(bigHand);
	
	return score;
}
// Take an iterative approach???
void Adjudicator::combinationChecker(std::vector<Card>& bh, int off, int k) {
	// Recursion.
	// Yeah, I'm supprised it works too.
	if (k == 0) {
		checkHand(h);
		//std::reverse_copy(h.begin(), h.end(), r_h.begin());
		//checkHand(r_h);
		return;
	}
	for (int i = off; i <= bh.size() - k; ++i) {
		h.emplace_back(bh[i]);
		combinationChecker(bh, i + 1, k - 1);
		h.pop_back();
	}

	return;
}

void Adjudicator::checkHand(std::vector<Card>& h) {
	// We only check hands of same or better base score
	int base = score[0];
	// cool
	switch (base) {
	case 0:
		//junkHighCard(h);
		pair(h);
	case 1:
		twoPair(h);
	case 2:
		threeOfAKind(h);
	case 3:
		straight(h);
	case 4:
		flush(h);
	case 5:
		fullHouse(h);
	case 6:
		fourOfAKind(h);
	case 7:
		straightFlush(h);
	case 8:
		royalFlush(h);
	case 9:
		// Royal flush was achieved.
		// Go home my boy, you can do no better.
		return;
	default:
		// Let's not end up here
		printf("ERROR: Adjudicator case default statement reached.");
		break;
	}
	return;
}

void Adjudicator::royalFlush(std::vector<Card>& hand) {

	if (hand[0].getRank()!=12) { return; }

	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != hand[0].getSuit()) ||
			(hand[i].getRank() != hand[0].getRank() - i)) { return; }
	}
	
	score = { 9 };
}

void Adjudicator::straightFlush(std::vector<Card>& hand) {

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != hand[0].getSuit()) ||
			(hand[i].getRank() != hand[0].getRank() - i)) { return; }
	}

	score = std::max(std::vector<int>{ 8, hand[0].getRank() }, score);
}

void Adjudicator::fourOfAKind(std::vector<Card>& hand) {

	for (int i = 0; i < 2; ++i) {
		if (hand[0+i].getRank() == hand[3+i].getRank()) {
			score = std::max(std::vector<int>{ 7, hand[0+i].getRank(), hand[(4+i)%5].getRank() }, score);
			return;
		}
	}

	return;
}

void Adjudicator::fullHouse(std::vector<Card>& hand) {

	if (hand[0].getRank() == hand[1].getRank()) {
		for (int i = 2; i < 5; ++i) {
			if (hand[i].getRank() != hand[2].getRank()) { return; }
		}
	}

	else if (hand[3].getRank() == hand[4].getRank()) {
		for (int i = 0; i < 3; ++i) {
			if (hand[i].getRank() != hand[2].getRank()) { return; }
		}
	}

	else { return; }

	score = std::max(std::vector<int>{ 6, std::max(hand[0].getRank(), hand[3].getRank()), std::min(hand[0].getRank(), hand[3].getRank()) }, score);
}

void Adjudicator::flush(std::vector<Card>& hand) {

	for (int i = 1; i < 5; ++i) {
		if (hand[i].getSuit() != hand[0].getSuit()) { return; }
	}

	score = std::max(std::vector<int>{	5, 
										hand[0].getRank(), 
										hand[1].getRank(), 
										hand[2].getRank(),
										hand[3].getRank(), 
										hand[4].getRank() 
										}
					, score);
}

void Adjudicator::straight(std::vector<Card>& hand) {

	for (int i = 1; i < 5; ++i) {
		if (hand[i].getRank() != hand[0].getRank() - i) { return; }
	}

	score = std::max(std::vector<int> { 4, hand[0].getRank() }, score);
}

void Adjudicator::threeOfAKind(std::vector<Card>& hand) {

	for (int i = 0; i < 3; ++i) {
		if (hand[0+i].getRank() == hand[1+i].getRank() &&
			hand[1+i].getRank() == hand[2+i].getRank()) {

			score = std::max(std::vector<int> { 3,
												hand[0+i].getRank(),
												std::max(hand[3-(i*3)].getRank(), hand[4].getRank()),
												std::min(hand[3-(i*3)].getRank(), hand[4].getRank())
												}
							, score);
			return;
		}
	}

	return;
}

void Adjudicator::twoPair(std::vector<Card>& hand) {

	if (hand[0].getRank() == hand[1].getRank()) {
		if (hand[2].getRank() == hand[3].getRank()) {
			score = std::max(std::vector<int>{	2,
												hand[0].getRank(),
												hand[2].getRank(),
												hand[4].getRank()
												}
							, score);
		}
		else if (hand[3].getRank() == hand[4].getRank()) {
			score = std::max(std::vector<int>{	2,
												hand[0].getRank(),
												hand[3].getRank(),
												hand[2].getRank()
												}
							, score);
		}
	}
	else if (hand[1].getRank() == hand[2].getRank()) {
		if (hand[3].getRank() == hand[4].getRank()) {
			score = std::max(std::vector<int>{	2,
												hand[1].getRank(),
												hand[3].getRank(),
												hand[0].getRank()
												}
							, score);
		}
	}


	return;
}

void Adjudicator::pair(std::vector<Card>& hand) {
	for (int i = 0; i < 4; ++i) {
		if (hand[i].getRank() == hand[i + 1].getRank()) {

			score = std::max(std::vector<int>{	1,
												hand[i].getRank(), 
												std::max(std::max(hand[(i + 2) % 5].getRank(), hand[(i + 3) % 5].getRank()), hand[(i + 4) % 5].getRank())
												}
							, score);
			return;
		}
	}

	return;
}

void Adjudicator::junkHighCard(std::vector<Card>& hand) {
	
	if (hand[0].getRank() >= hand[4].getRank()) {
		score = { 0, hand[0].getRank(), hand[1].getRank(), hand[2].getRank(),
					hand[3].getRank(), hand[4].getRank() };
	}
	return;
}
