#include <iostream>
#include "Board.hpp"
using std::cout;
using std::endl;

const int ROWS = 10;
const int COLUMNS = 10;

// Constructor
Board::Board() {
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            array[row][column] = '.';
        }
    }
}

bool Board::makeMove(int row, int column, char c) {
    if (array[row][column] == '.') {
        array[row][column] = c;
        return true;
    } else {
        return false;
    }
}

void Board::print() {
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // Print x-axis labels
    for (int row = 0; row < ROWS; row++) {
        cout << row; // Print y-axis labels
        for (int column = 0; column < COLUMNS; column++) {
            cout << ' ';
            cout << array[row][column];
        }
        cout << endl;
    }
}