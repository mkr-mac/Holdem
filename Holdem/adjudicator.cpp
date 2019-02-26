#include "adjudicator.h"

std::vector<Card> Adjudicator::h(5);
std::vector<Card> Adjudicator::r_h(5);

std::vector<int> Adjudicator::handValue(const std::vector<Card>& communityCards, const std::vector<Card>& playerHand) {
	//make one big hand to mess with
	std::vector<Card> bigHand;

	for (const Card& c : communityCards) {
		bigHand.emplace_back(c);
	}
	for (const Card& d : playerHand) {
		bigHand.emplace_back(d);
	}

	std::vector<int> score { 0, 0, 0, 0, 0, 0 };

	Adjudicator::h.clear();
	Adjudicator::r_h.clear();

	std::sort(bigHand.begin(), bigHand.end());

	return combinationChecker(bigHand, score);
}
// Take an iterative approach???
std::vector<int> Adjudicator::combinationChecker(std::vector<Card>& bh, std::vector<int>& score, int off, int k) {
	// Recursion.
	//Yeah, I'm supprised it works too.
	if (k == 0) {
		score = std::max(checkHand(Adjudicator::h, score), score);
		reverse_copy(Adjudicator::h.begin(), Adjudicator::h.end(), Adjudicator::r_h.begin());
		score = std::max(checkHand(Adjudicator::r_h, score), score);
		return score;
	}
	for (size_t i = off; i <= bh.size() - k; ++i) {
		Adjudicator::h.emplace_back(bh[i]);
		score = std::max(combinationChecker(bh, score, i + 1, k - 1), score);
		Adjudicator::h.pop_back();
	}

	return score;
}

std::vector<int> Adjudicator::checkHand(std::vector<Card>& h, std::vector<int>& score) {
	// We only check hands of same or better base score
	int base = score[0];
	// cool
	switch (base) {
	case 0:
		score = std::max(junkHighCard(h), score);
	case 1:
		score = std::max(pair(h), score);
	case 2:
		score = std::max(twoPair(h), score);
	case 3:
		score = std::max(threeOfAKind(h), score);
	case 4:
		score = std::max(straight(h), score);
	case 5:
		score = std::max(flush(h), score);
	case 6:
		score = std::max(fullHouse(h), score);
	case 7:
		score = std::max(fourOfAKind(h), score);
	case 8:
		score = std::max(straightFlush(h), score);
		score = std::max(royalFlush(h), score);
	case 9:
		// Royal flush was achieved.
		// Go home my boy, you can do no better.
		return score;
	default:
		// Let's not end up here
		printf("ERROR: Adjudicator case default statement reached.");
		break;
	}
	return score;
}

std::vector<int> Adjudicator::royalFlush(std::vector<Card>& hand) {

	if (hand[0].getRank() !=12) { return{}; }

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != hand[0].getSuit()) ||
			(hand[i].getRank() != hand[0].getRank()- i)) { return{}; }
	}
	
	return { 9 };
}

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
	}

	if (hand[3].getRank() != hand[4].getRank()) { return{}; }

	return { 6, std::max(hand[0].getRank(), hand[3].getRank()), std::min(hand[0].getRank(), hand[3].getRank()) };
}

std::vector<int> Adjudicator::flush(std::vector<Card>& hand) {

	for (int i = 1; i < 5; ++i) {
		if ((hand[i].getSuit() != hand[0].getSuit()) ||
			(hand[i].getRank() >= hand[i-1].getRank())) { return {}; }
	}

	return { 5, hand[0].getRank(), hand[1].getRank(), hand[2].getRank(),
				hand[3].getRank(), hand[4].getRank() };
}

std::vector<int> Adjudicator::straight(std::vector<Card>& hand) {

	for (int i = 1; i < 5; ++i) {
		if (hand[i].getRank() != hand[0].getRank() - i) { return {}; }
	}

	return { 4, hand[0].getRank() };
}

std::vector<int> Adjudicator::threeOfAKind(std::vector<Card>& hand) {

	for (int i = 0; i < 2; ++i) {
		if (hand[0+i].getRank() == hand[1+i].getRank() &&
			hand[1+i].getRank() == hand[2+i].getRank()) {

			return { 3, 
					hand[0+i].getRank(),
					std::max(hand[3-(i*3)].getRank(), hand[4].getRank()),
					std::min(hand[3-(i*3)].getRank(), hand[4].getRank())
			};
		}
	}

	return {};
}

std::vector<int> Adjudicator::twoPair(std::vector<Card>& hand) {

	for (int i = 0; i < 2; ++i) {
		if ((hand[ 0 ].getRank() == hand[ 1 ].getRank()) &&
			(hand[2+i].getRank() == hand[3+i].getRank())) {

			return	{ 2,
						std::max(hand[0].getRank(), hand[2+i].getRank()),
						std::min(hand[0].getRank(), hand[2+i].getRank()),
						hand[4 - (i*2)].getRank() 
			};
		}
	}

	return {};
}

std::vector<int> Adjudicator::pair(std::vector<Card>& hand) {

	for (int i = 0; i < 2; ++i) {
		if (hand[i].getRank() == hand[i + 1].getRank()) {

			return { 1, 
					hand[i].getRank(), 
					std::max(std::max(hand[(i + 2)].getRank(), hand[(i + 3)].getRank()), hand[(i + 4) % 5].getRank())
			};
		}
	}

	return {};
}

std::vector<int> Adjudicator::junkHighCard(std::vector<Card>& hand) {
	
	if (hand[0].getRank() >= hand[4].getRank()) {
		return { 0, hand[0].getRank(), hand[1].getRank(), hand[2].getRank(),
					hand[3].getRank(), hand[4].getRank() };
	}
	return {};
}
