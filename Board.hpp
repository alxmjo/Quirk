#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
    private:
        char array[10][10];
        
    public:
        Board();
        bool makeMove(int, int, char);
        void print();
};
#endif