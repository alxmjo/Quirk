#include <iostream>
#include "Player.hpp"
#include "Constants.hpp"
using std::cout;

// Constructor
Player::Player() {
    points = 0;
}

void Player::addPoints(int i) {
    points += i;
}

int Player::getPoints() {
    return points;
}

void Player::fillHand(Pool& pool) {
    while (hand.size() < HAND_SIZE) {
        hand.push_back(pool.pullPiece());
    }
}

void Player::printHand() {
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i];
    }
}