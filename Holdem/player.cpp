#include "player.h"

Player::Player(int id) {
	this->id = id;
}

void Player::getCard(Card c) {
	hand.push_back(c);
}