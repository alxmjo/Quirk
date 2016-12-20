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
    
    turnCount = 0;
}

bool Board::makeMove(int row, int column, char piece) {
    
    if (array[row][column] == '.') {
        array[row][column] = piece;   
        
        if (isValidSet(getHorizontalRun(row, column)) && isNoRepeats(getHorizontalRun(row, column), getVerticalRun(row, column)) && isValidRunLength(getHorizontalRun(row, column), getVerticalRun(row, column)) && isValidSet(getVerticalRun(row, column))) {
            turnCount++;
            return true;
        } else {
            array[row][column] = '.';
            return false;
        }
    } else {
        return false;
    }
}

// for testing
void Board::printVector(vector<char> v) {
  for (int i = 0; i < v.size(); i++){
    cout << v[i] << ' ';
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

    // find ending position of run
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

// Take coordinates and return a vector of the adjacent vertical pieces
vector<char> Board::getVerticalRun(int row, int column) {
    int runStart = row;
    int runEnd = row;
    vector<char> verticalRun;

    // find starting position of run
    while (true) {
        if (isInBounds(runStart - 1, column)) {
            if (array[runStart - 1][column] == '.') {
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
        if (isInBounds(runEnd + 1, column)) {
            if (array[runEnd + 1][column] == '.') {
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
        verticalRun.push_back(array[i][column]);
    }

    return verticalRun;
}

// Take run vectors and ensure that one of them is greater than one (unless it's the first move) 
// and that none are longer than 3 
bool Board::isValidRunLength(vector<char> h, vector<char> v) {
    if (turnCount == 0) {
        return true;
    } else if ((h.size() > 1 || v.size() > 1) && h.size() <= 3 && v.size() <= 3) {
        return true; 
    } else {
        return false;
    }
}

// Take run vectors and ensure that no chars are repeated
bool Board::isNoRepeats(vector<char> horizontal, vector<char> vertical) {
    bool h, v;
    
    sort(horizontal.begin(), horizontal.end());
    h = adjacent_find(horizontal.begin(), horizontal.end()) == horizontal.end();
    
    sort(vertical.begin(), vertical.end());
    v = adjacent_find(vertical.begin(), vertical.end()) == vertical.end();
    
    return h && v;
}

// Take a run vector and ensure that it contains a valid set (ABC, 123, Aa1, etc.)
bool Board::isValidSet(vector<char> v) {
    CharCase charcase0;
    CharCase charcase1;
    CharCase charcase2;
    CharCount charcount0;
    CharCount charcount1;
    CharCount charcount2;

    if (v.size() == 1) {
        return true;
    } else if (v.size() == 2) {
        CharCase charcase0 = getCharCase(v[0]);
        CharCase charcase1 = getCharCase(v[1]);
        CharCount charcount0 = getCharCount(v[0]);
        CharCount charcount1 = getCharCount(v[1]);
        
        if ((charcase0 == charcase1) || (charcount0 == charcount1)) {
            return true;
        } else {
            return false;
        }
    } else if (v.size() == 3) {
        CharCase charcase0 = getCharCase(v[0]);
        CharCase charcase1 = getCharCase(v[1]);
        CharCase charcase2 = getCharCase(v[2]);
        CharCount charcount0 = getCharCount(v[0]);
        CharCount charcount1 = getCharCount(v[1]);
        CharCount charcount2 = getCharCount(v[2]);
        
        if ((charcase0 == charcase1 && charcase1 == charcase2) || (charcount0 == charcount1 && charcount1 == charcount2)) {
            return true;       
        } else {
            return false;
        }
    }
    
    // this should never run
    return false;
}

CharCase Board::getCharCase(char c) {
    CharCase charcase;
    
    if (c == 'A' || c == 'B' || c == 'C') 
        charcase = UPPER;
    if (c == 'a' || c == 'b' || c == 'c')
        charcase = LOWER;
    if (c == '1' || c == '2' || c == '3')
        charcase = NUMBER; 
        
    return charcase;
}

CharCount Board::getCharCount(char c) {
    CharCount charcount;
    
    if (c == 'A' || c == 'a' || c == '1') 
        charcount = FIRST;
    if (c == 'B' || c == 'b' || c == '2')
        charcount = SECOND;
    if (c == 'C' || c == 'c' || c == '3')
        charcount = THIRD;
    
    return charcount; 
}

bool Board::isValidMove(int row, int column, char c) {
    return false;
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