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

bool Player::hasPiece(char c) {
    if (find(hand.begin(), hand.end(), c) != hand.end()) {
        return true;
    } else { 
        return false;
    }
}

void Player::removePiece(char c) {
    auto piece = std::find(hand.begin(), hand.end(), c);
    if (piece != hand.end())
        hand.erase(piece);
}

void Player::fillHand(Pool& pool) {
    while (hand.size() < HAND_SIZE && pool.size() > 0) {
        hand.push_back(pool.pullPiece());
    }
}

int Player::handSize() {
    return hand.size();
}

void Player::printHand() {
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i];
    }
}