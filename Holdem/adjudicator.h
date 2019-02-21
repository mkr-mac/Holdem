#pragma once
#include "card.h"
#include <vector>
#include <algorithm>

static class Adjudicator {
public:
	std::vector<int> handValue(std::vector<Card> publicHand, std::vector<Card> playerHand);

private:
	void combinationChecker	(std::vector<Card> bh, std::vector<int> score, int off = 0, int k = 5);
	void checkHand			(std::vector<Card> hand, std::vector<int> score);
	void royalFlush			(std::vector<Card> hand, std::vector<int> score);
	void straightFlush		(std::vector<Card> hand, std::vector<int> score);
	void fourOfAKind		(std::vector<Card> hand, std::vector<int> score);
	void fullHouse			(std::vector<Card> hand, std::vector<int> score);
	void flush				(std::vector<Card> hand, std::vector<int> score);
	void straight			(std::vector<Card> hand, std::vector<int> score);
	void threeOfAKind		(std::vector<Card> hand, std::vector<int> score);
	void twoPair			(std::vector<Card> hand, std::vector<int> score);
	void pair				(std::vector<Card> hand, std::vector<int> score);
	void junkHighCard		(std::vector<Card> hand, std::vector<int> score);
};