#include <cstdlib>
#include <ctime>
#include <iostream> // for testing
#include "Pool.hpp"
using std::srand;
using std::time;
using std::cout; // testing
using std::endl; // testing

// Constructor
Pool::Pool() {
    pieces = {'A','A','A','A','A','A',
              'B','B','B','B','B','B',
              'C','C','C','C','C','C',
              'a','a','a','a','a','a',
              'b','b','b','b','b','b',
              'c','c','c','c','c','c',
              '1','1','1','1','1','1',
              '2','2','2','2','2','2',
              '3','3','3','3','3','3'};
    
    srand(time(0)); // Seed the random number generator
}

// Pull and remove a piece from the pieces vector
char Pool::pullPiece() {
    if (pieces.empty()) {
        return '\0';    
    } else {
        int randomIndex = rand() % pieces.size();
        char c = pieces[randomIndex]; // Get the piece
        pieces.erase(pieces.begin() + randomIndex); // Remove the piece
    
        return c;
    }
}

// Show the size of the pieces vector
int Pool::size() {
    return pieces.size();
}