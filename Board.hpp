#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
    private:
        char array[10][10];
        
    public:
        Board();
        bool makeMove(int, int, char);
        bool isValidMove(int, int, char);
        bool isInBounds(int, int);
        void print();
};
#endif