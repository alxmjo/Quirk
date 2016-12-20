#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Player.hpp"
using std::vector;

enum CharCase {UPPER, LOWER, NUMBER};
enum CharCount {FIRST, SECOND, THIRD};

class Board {
    private:
        char array[10][10];
        int turnCount;
        
    public:
        Board();
        bool makeMove(int, int, char, Player&);
        int getMovePoints(vector<char>, vector<char>);
        bool isValidRunLength(vector<char>, vector<char>);
        bool isNoRepeats(vector<char>, vector<char>);
        bool isValidSet(vector<char>);
        CharCase getCharCase(char);
        CharCount getCharCount(char);
        bool isValidMove(int, int, char);
        bool isInBounds(int, int);
        vector<char> getHorizontalRun(int, int);
        vector<char> getVerticalRun(int, int);
        void print();
        void printVector(vector<char>);
};
#endif