#include <iostream>
#include "Board.hpp"
using std::cout;
using std::endl;

const int ROWS = 10;
const int COLUMNS = 10;

    // A B C
    // a b c
    // 1 2 3
    //          r-1c
    //  rc-1     rc     rc+1
    //          r+1c
    // if A, B C || a 1
    // if B, A C || b 2
    // if C, A B || c 3
    // if a, b c || A 1
    // if b, a c || B 2
    // if c, a b || C 3
    // if 1, 2 3 || A a
    // if 2, 1 3 || B b
    // if 3, 1 2 || C c

// Constructor
Board::Board() {
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            array[row][column] = '.';
        }
    }
}

bool Board::makeMove(int row, int column, char c) {
    if (array[row][column] == '.' && isValidMove(row, column, c)) {
        array[row][column] = c;
        return true;
    } else {
        return false;
    }
}

bool Board::isValidMove(int row, int column, char c) {
    bool above, below, left, right;
    
    // check above
    if (isInBounds(row - 1, column)) {
        cout << "above is in bounds" << endl;
    } else {
        above = true;
    }
    
    // check below
    if (isInBounds(row + 1, column)) {
        cout << "below is in bounds" << endl;
    } else {
        below = true;
    }
    
    // check left
    if (isInBounds(row, column - 1)) {
        cout << "left is in bounds" << endl;
    } else {
        left = true;
    }
    
    // check right
    if (isInBounds(row, column + 1)) {
        cout << "right is in bounds" << endl;
    } else {
        right = true;
    }
    
    return above && below && left && right;
}

bool Board::isInBounds(int row, int column) {
    if (row >= 0 && row <= 9 && column >= 0 && column <= 9) {
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