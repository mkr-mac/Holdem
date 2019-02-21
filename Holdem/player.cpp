#include "player.h"

Player::Player(int id) {
	this->id = id;
}

void Player::getCard(Card c) {
	hand.push_back(c);
}

std::string Player::printHand() {

	std::string h = "";

	for (Card c : hand) {
		h += c.getName(); 
	}

	return h;
}

void Player::emptyHand() {
	hand.clear();
}

std::vector<Card> Player::getHand() {
	return hand;
}

int Player::getId() {
	return id;
}