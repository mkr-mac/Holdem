#pragma once
#include "card.h"
#include <vector>
#include <algorithm>

class Adjudicator {
public:
	std::vector<int> handValue		(std::vector<Card> publicHand, std::vector<Card> playerHand);

private:
	std::vector<int> combinationChecker	(std::vector<Card> bh, std::vector<int> score, int off = 0, int k = 5);
	std::vector<int> checkHand			(std::vector<Card> hand, std::vector<int> score);
	std::vector<int> royalFlush			(std::vector<Card> hand);
	std::vector<int> straightFlush		(std::vector<Card> hand);
	std::vector<int> fourOfAKind		(std::vector<Card> hand);
	std::vector<int> fullHouse			(std::vector<Card> hand);
	std::vector<int> flush				(std::vector<Card> hand);
	std::vector<int> straight			(std::vector<Card> hand);
	std::vector<int> threeOfAKind		(std::vector<Card> hand);
	std::vector<int> twoPair			(std::vector<Card> hand);
	std::vector<int> pair				(std::vector<Card> hand);
	std::vector<int> junkHighCard		(std::vector<Card> hand);
};