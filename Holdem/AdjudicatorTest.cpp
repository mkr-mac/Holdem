
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
std::vector<Card> cc{ Card(2,3) ,Card(3,2) ,Card(4,2) ,Card(8,2) ,Card(6,2) };
std::vector<Card> a{ Card(2,0), Card(2,1) };
std::vector<int> s = Adjudicator::handValue(cc, a);
for(int i : s){
	std::cout << std::to_string(i) << ", ";
}
bool t = s == std::vector<int> {3, 2, 8, 6};
BOOST_TEST(t);
  BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(myTestCase2)
{
	std::vector<int> count{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	srand(time(NULL));

	Deck f_d;
	Deck d;

	f_d.shuffle();

	for (int i = 0; i < 1000000; ++i) {
		f_d.randomSwap();
		d = f_d;

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