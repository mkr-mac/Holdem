#pragma once
#include "card.h"
#include <vector>
#include <algorithm>

class Adjudicator {
public:
	static std::vector<int> handValue		(std::vector<Card>& communityCards, std::vector<Card>& playerHand);

private:
	static std::vector<int> combinationChecker	(std::vector<Card>& bh, std::vector<int>& score, int off = 0, int k = 5);
	static std::vector<int> checkHand			(std::vector<Card>& hand, std::vector<int>& score);
	static std::vector<int> royalFlush			(std::vector<Card>& hand);
	static std::vector<int> straightFlush		(std::vector<Card>& hand);
	static std::vector<int> fourOfAKind			(std::vector<Card>& hand);
	static std::vector<int> fullHouse			(std::vector<Card>& hand);
	static std::vector<int> flush				(std::vector<Card>& hand);
	static std::vector<int> straight			(std::vector<Card>& hand);
	static std::vector<int> threeOfAKind		(std::vector<Card>& hand);
	static std::vector<int> twoPair				(std::vector<Card>& hand);
	static std::vector<int> pair				(std::vector<Card>& hand);
	static std::vector<int> junkHighCard		(std::vector<Card>& hand);
};