#include <iostream>
#include "Board.hpp"
#include "Constants.hpp"
using std::cout;
using std::endl;

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

vector<char> Board::getHorizontalRun(int row, int column) {
    int runStart = column;
    int runEnd = column;
    vector<char> horizontalRun;

    // find starting position of run
    while (true) {
        if (isInBounds(row, runStart - 1)) {
            if (array[row][runStart - 1] == '.') {
                break;
            } else {
                runStart--;
            }
        } else {
            break;
        }
    }

    // find ending position of array
    while (true) {
        if (isInBounds(row, runEnd + 1)) {
            if (array[row][runEnd + 1] == '.') {
                break;
            } else {
                runEnd++;
            }
        } else {
            break;
        }
    }

    // Use start and end positions to populate vector
    for (int i = runStart; i <= runEnd; i++) {
        horizontalRun.push_back(array[row][i]);
    }

    return horizontalRun;
}

bool Board::isValidMove(int row, int column, char c) {
    bool    above, below, left, right,
            above2, below2, left2, right2,
            aboveConsec, rightConsec, belowConsec, leftConsec;
            
            rightConsec = true;
            belowConsec = true;
            leftConsec = true;
        
    // check above
    if (isInBounds(row - 1, column)) {
        above = isValidPiece(c, array[row - 1][column]);
    } else {
        above = true;
    }
    
    // check below
    if (isInBounds(row + 1, column)) {
        below = isValidPiece(c, array[row + 1][column]);
    } else {
        below = true;
    }
    
    // check left
    if (isInBounds(row, column - 1)) {
        left = isValidPiece(c, array[row][column - 1]);
    } else {
        left = true;
    }
    
    // check right
    if (isInBounds(row, column + 1)) {
        right = isValidPiece(c, array[row][column + 1]);
    } else {
        right = true;
    }
    
    // check above2
    if (isInBounds(row - 2, column)) {
        above2 = isValidPiece(c, array[row - 2][column]);
    } else {
        above2 = true;
    }
    
    // check below2
    if (isInBounds(row + 2, column)) {
        below2 = isValidPiece(c, array[row + 2][column]);
    } else {
        below2 = true;
    }
    
    // check left2
    if (isInBounds(row, column - 2)) {
        left2 = isValidPiece(c, array[row][column - 2]);
    } else {
        left2 = true;
    }
    
    // check right2
    if (isInBounds(row, column + 2)) {
        right2 = isValidPiece(c, array[row][column + 2]);
    } else {
        right2 = true;
    }
    
    // check no more than three pieces in a row above
    if (isInBounds(row - 3, column)) {
        aboveConsec = array[row - 1][column] == '.' || array[row - 2][column] == '.' || array[row - 3][column] == '.';
    } else {
        aboveConsec = true;
    }
    
    // check no more than three pieces in a row below
    if (isInBounds(row + 3, column)) {
        aboveConsec = array[row + 3][column] == '.' || array[row + 3][column] == '.' || array[row + 3][column] == '.';
    } else {
        belowConsec = true;
    }
    
    // check no more than three pieces in a row left
    if (isInBounds(row, column - 3)) {
        aboveConsec = array[row][column - 3] == '.' || array[row][column - 3] == '.' || array[row][column - 3] == '.';
    } else {
        leftConsec = true;
    }
    
    // check no more than three pieces in a row left
    if (isInBounds(row, column + 3)) {
        aboveConsec = array[row][column + 3] == '.' || array[row][column + 3] == '.' || array[row][column + 3] == '.';
    } else {
        rightConsec = true;
    }
    
    return  above && below && left && right && 
            above2 && below2 && left2 && right2 &&
            aboveConsec && rightConsec && belowConsec && leftConsec;
}

// returns true if the char c and the char d are in the same group, 
// either by type (ABC, abc, 123) or by count (Aa1, Bb2, Cc3),
// or if the location is empty
bool Board::isValidPiece(char c, char d) {
	bool b = false;
	
	switch (c) {
	                //  ------ by type -----    ----- by count -----   - empty -
	    case 'A':   if (d == 'B' || d == 'C' || d == 'a' || d == '1' || d == '.')
	                    b = true;
	                    break;
	    case 'B':   if (d == 'A' || d == 'C' || d == 'b' || d == '2' || d == '.')
	                    b = true;
	                    break;
	    case 'C':   if (d == 'A' || d == 'B' || d == 'c' || d == '3' || d == '.')
	                    b = true;
	                    break;
	    case 'a':   if (d == 'b' || d == 'c' || d == 'A' || d == '1' || d == '.')
	                    b = true;
	                    break;
	    case 'b':   if (d == 'a' || d == 'c' || d == 'B' || d == '2' || d == '.')
	                    b = true;
	                    break;
	    case 'c':   if (d == 'a' || d == 'b' || d == 'C' || d == '3' || d == '.')
	                    b = true;
	                    break;
	    case '1':   if (d == '2' || d == '3' || d == 'A' || d == 'a' || d == '.')
	                    b = true;
	                    break;
	    case '2':   if (d == '1' || d == '3' || d == 'B' || d == 'b' || d == '.')
	                    b = true;
	                    break;
	    case '3':   if (d == '1' || d == '2' || d == 'C' || d == 'c' || d == '.')
	                    b = true;
	                    break;
	    }
	
	return b;
}

bool Board::isInBounds(int row, int column) {
    if (row >= 0 && row < ROWS && column >= 0 && column < COLUMNS) {
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