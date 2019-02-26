
#include "config.h"
#ifdef TEST
#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "card.h"
#include <vector>
#include "adjudicator.h"
#include <time.h> 
#include <iostream>
#include "deck.h"

BOOST_AUTO_TEST_CASE(myTestCase)
{
std::vector<Card> a{ Card(2,2) ,Card(2,2) ,Card(2,2) ,Card(2,2) ,Card(2,2) };
std::vector<Card> cc;
bool t = Adjudicator::handValue(cc, a) == std::vector<int> {7, 2, 2};
BOOST_TEST(t);
  BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(myTestCase2)
{
	std::vector<int> count{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	srand(time(NULL));

	Deck d;
	for (int i = 0; i < 100000; ++i) {
		d = Deck();
		d.shuffle();
		std::vector<Card> p{ 
			d.deal(),
			d.deal()
		};

		std::vector<Card> com{
			d.deal(),
			d.deal(),
			d.deal(),
			d.deal(),
			d.deal()
		};

		++count[Adjudicator::handValue(com, p)[0]];

		//BOOST_TEST(t);
	}

	for (int r = 0; r < 10; ++r) {
		std::cout << std::to_string(r) << ": " << std::to_string(count[r]) << std::endl;
	}

	BOOST_TEST(true);
}
#endif