#pragma once
#include "card.h"
#include <vector>
#include <algorithm>
#include <math.h>

class Adjudicator {
public:
	static std::vector<int> handValue (const std::vector<Card>& communityCards, const std::vector<Card>& playerHand);

private:

	// The hand used in checking combinations
	static std::vector<Card> h;
	//static std::vector<Card> r_h;
	static std::vector<int> score;
	static void				combinationChecker	(std::vector<Card>& bh, int off = 0, int k = 5);
	static void				checkHand			(std::vector<Card>& hand);
	//static void			royalFlush			(std::vector<Card>& hand);
	static void				straightFlush		(std::vector<Card>& hand);
	static void				fourOfAKind			(std::vector<Card>& hand);
	static void				fullHouse			(std::vector<Card>& hand);
	static void				flush				(std::vector<Card>& hand);
	static void				straight			(std::vector<Card>& hand);
	static void				threeOfAKind		(std::vector<Card>& hand);
	static void				twoPair				(std::vector<Card>& hand);
	static void				pair				(std::vector<Card>& hand);
	static void				junkHighCard		(std::vector<Card>& hand);
};