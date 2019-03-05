#include "adjudicator.h"

std::vector<Card> Adjudicator::h(5);
std::vector<Card> Adjudicator::r_h(5);
<<<<<<< HEAD
std::vector<int> Adjudicator::score;
=======
>>>>>>> c22c7bf083552bb84c6b0a9d9b86574d75f47b6a

std::vector<int> Adjudicator::handValue(const std::vector<Card>& communityCards, const std::vector<Card>& playerHand) {
	//make one big hand to mess with
	std::vector<Card> bigHand;

	for (Card c : communityCards) {
		bigHand.emplace_back(c.getRank(), c.getSuit());
	}
	for (Card d : playerHand) {
		bigHand.emplace_back(d.getRank(), d.getSuit());
	}

	score.clear();
	score.emplace_back(0);
	h.clear();
	r_h.clear();

<<<<<<< HEAD
=======
	Adjudicator::h.clear();
	Adjudicator::r_h.clear();
>>>>>>> c22c7bf083552bb84c6b0a9d9b86574d75f47b6a

	std::sort(bigHand.begin(), bigHand.end());

	combinationChecker(bigHand);
	
	return score;
}
// Take an iterative approach???
void Adjudicator::combinationChecker(std::vector<Card>& bh, int off, int k) {
	// Recursion.
	//Yeah, I'm supprised it works too.
	if (k == 0) {
<<<<<<< HEAD
		checkHand(h);
		std::reverse_copy(h.begin(), h.end(), r_h.begin());
		checkHand(r_h);
		return;
=======
		score = std::max(checkHand(Adjudicator::h, score), score);
		reverse_copy(Adjudicator::h.begin(), Adjudicator::h.end(), Adjudicator::r_h.begin());
		score = std::max(checkHand(Adjudicator::r_h, score), score);
		return score;
>>>>>>> c22c7bf083552bb84c6b0a9d9b86574d75f47b6a
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

<<<<<<< HEAD
	int r = hand[0].getRank();
	if (r!=12) { return; }

	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) || 
			(hand[i].getRank() != r - i)) { return; }
=======
	if (hand[0].getRank() !=12) { return{}; }

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != hand[0].getSuit()) ||
			(hand[i].getRank() != hand[0].getRank()- i)) { return{}; }
>>>>>>> c22c7bf083552bb84c6b0a9d9b86574d75f47b6a
	}
	
	score = { 9 };
}

<<<<<<< HEAD
void Adjudicator::straightFlush(std::vector<Card>& hand) {
	int r = hand[0].getRank();
	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) ||
			(hand[i].getRank() != r - i)) { return; }
	}

	score = std::max(std::vector<int>{ 8, r }, score);
}

void Adjudicator::fourOfAKind(std::vector<Card>& hand) {
	int r = hand[0].getRank();

	for (int i = 1; i < 4; ++i) {
		if (hand[i].getRank() != r) { return; }
	}

	score = std::max(std::vector<int>{ 7, r, hand[4].getRank() }, score);
}

void Adjudicator::fullHouse(std::vector<Card>& hand) {
	int r = hand[0].getRank();

	for (int i = 1; i < 3; ++i) {
		if (hand[i].getRank() != r) { return; }
=======
std::vector<int> Adjudicator::straightFlush(std::vector<Card>& hand) {

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != hand[0].getSuit()) ||
			(hand[i].getRank() != hand[0].getRank() - i)) { return{}; }
	}

	return { 8, hand[0].getRank() };
}

std::vector<int> Adjudicator::fourOfAKind(std::vector<Card>& hand) {

	for (int i = 1; i < 4; ++i) {
		if (hand[i].getRank() != hand[0].getRank()) { return{}; }
	}

	return { 7, hand[0].getRank(), hand[4].getRank() };
}

std::vector<int> Adjudicator::fullHouse(std::vector<Card>& hand) {

	for (int i = 1; i < 3; ++i) {
		if (hand[i].getRank() != hand[0].getRank()) { return{}; }
>>>>>>> c22c7bf083552bb84c6b0a9d9b86574d75f47b6a
	}

	if (hand[3].getRank() != hand[4].getRank()) { return; }

<<<<<<< HEAD
	score = std::max(std::vector<int>{ 6, std::max(r, hand[3].getRank()), std::min(r, hand[3].getRank()) }, score);
}

void Adjudicator::flush(std::vector<Card>& hand) {
	int s = hand[0].getSuit();

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != s) ||
			(hand[i].getRank() >= hand[i-1].getRank())) { return; }
=======
	return { 6, std::max(hand[0].getRank(), hand[3].getRank()), std::min(hand[0].getRank(), hand[3].getRank()) };
}

std::vector<int> Adjudicator::flush(std::vector<Card>& hand) {

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != hand[0].getSuit()) ||
			(hand[i].getRank() >= hand[i-1].getRank())) { return {}; }
>>>>>>> c22c7bf083552bb84c6b0a9d9b86574d75f47b6a
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

<<<<<<< HEAD
void Adjudicator::straight(std::vector<Card>& hand) {
	int r = hand[0].getRank();

	for (int i = 1; i < 5; ++i) {
		if (hand[i].getRank() != r - i) { return; }
	}

	score = std::max(std::vector<int> { 4, r }, score);
=======
std::vector<int> Adjudicator::straight(std::vector<Card>& hand) {

	for (int i = 1; i < 5; ++i) {
		if (hand[i].getRank() != hand[0].getRank() - i) { return {}; }
	}

	return { 4, hand[0].getRank() };
>>>>>>> c22c7bf083552bb84c6b0a9d9b86574d75f47b6a
}

void Adjudicator::threeOfAKind(std::vector<Card>& hand) {

	for (int i = 0; i < 2; ++i) {
		if (hand[0+i].getRank() == hand[1+i].getRank() &&
			hand[1+i].getRank() == hand[2+i].getRank()) {

			score = std::max(std::vector<int> { 3,
												hand[0+i].getRank(),
												std::max(hand[3-(i*3)].getRank(), hand[4].getRank()),
												std::min(hand[3-(i*3)].getRank(), hand[4].getRank())
												}
							, score);
		}
	}

	return;
}

void Adjudicator::twoPair(std::vector<Card>& hand) {

	for (int i = 0; i < 2; ++i) {
		if ((hand[ 0 ].getRank() == hand[ 1 ].getRank()) &&
			(hand[2+i].getRank() == hand[3+i].getRank())) {

			score = std::max(std::vector<int>{	2,
												std::max(hand[0].getRank(), hand[2+i].getRank()),
												std::min(hand[0].getRank(), hand[2+i].getRank()),
												hand[4 - (i*2)].getRank() 
												}
							, score);
		}
	}

	return;
}

<<<<<<< HEAD
void Adjudicator::pair(std::vector<Card>& hand) {
=======
std::vector<int> Adjudicator::pair(std::vector<Card>& hand) {

>>>>>>> c22c7bf083552bb84c6b0a9d9b86574d75f47b6a
	for (int i = 0; i < 2; ++i) {
		if (hand[i].getRank() == hand[i + 1].getRank()) {

			score = std::max(std::vector<int>{	1,
												hand[i].getRank(), 
												std::max(std::max(hand[(i + 2)].getRank(), hand[(i + 3)].getRank()), hand[(i + 4) % 5].getRank())
												}
							, score);
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
