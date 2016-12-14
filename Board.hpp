#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
using std::vector;

class Board {
    private:
        char array[10][10];
        
    public:
        Board();
        bool makeMove(int, int, char);
        bool isValidMove(int, int, char);
        bool isValidPiece(char, char);
        bool isInBounds(int, int);
        vector<char> getHorizontalRun(int,int);
        void print();
};
#endif