
#include "config.h"
#ifdef TEST
#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "card.h"
#include <vector>
#include "adjudicator.h"
#include <time.h> 

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
	std::srand(time(NULL));
	for (int i = 0; i < 100000; ++i) {
		std::vector<Card> a{ 
			Card(std::rand()%13,std::rand()%4) ,
			Card(std::rand() % 13,std::rand() % 4) ,
			Card(std::rand() % 13,std::rand() % 4) ,
			Card(std::rand() % 13,std::rand() % 4) ,
			Card(std::rand() % 13,std::rand() % 4) 
		};
		std::vector<Card> cc{ 
			Card(std::rand() % 13,std::rand() % 4) ,
			Card(std::rand() % 13,std::rand() % 4) 
		};

		Adjudicator::handValue(cc, a);
		//BOOST_TEST(t);
	}
	BOOST_TEST(true);
}
#endif