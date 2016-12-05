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
        void fillHand(Pool&);
        void printHand();
};

#endif