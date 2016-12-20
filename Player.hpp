#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Pool.hpp"
using std::vector;

class Player {
    private:
        int points;
        vector<char> hand;
    public:
        Player();
        void addPoints(int);
        int getPoints();
        bool hasPiece(char);
        void removePiece(char);
        void fillHand(Pool&);
        int handSize();
        void printHand();
};

#endif