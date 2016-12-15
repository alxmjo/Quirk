#include <iostream>
#include "Player.hpp"
#include "Constants.hpp"
using std::cout;

// Constructor
Player::Player() {
    points = 0;
}

// Take an int and add it to the player's score
void Player::addPoints(int i) {
    points += i;
}

// Get the player's current point total
int Player::getPoints() {
    return points;
}

// Take an int and return true if it's in player's hand
bool Player::hasPiece(char c) {
    if (find(hand.begin(), hand.end(), c) != hand.end()) {
        return true;
    } else { 
        return false;
    }
}

// Take a char and remove it from the player's hand
void Player::removePiece(char c) {
    auto piece = std::find(hand.begin(), hand.end(), c);
    if (piece != hand.end())
        hand.erase(piece);
}

// Take a reference to a Pool object and fill player's hand with pieces
void Player::fillHand(Pool& pool) {
    while (hand.size() < HAND_SIZE && pool.size() > 0) {
        hand.push_back(pool.pullPiece());
    }
}

// Get the size of the player's hand
int Player::handSize() {
    return hand.size();
}

// Print the player's hand
void Player::printHand() {
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i];
    }
}