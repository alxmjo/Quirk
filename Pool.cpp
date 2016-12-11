#include <cstdlib>
#include <ctime>
#include <iostream> // for testing
#include "Pool.hpp"
using std::srand;
using std::time;
using std::cout; // testing
using std::endl; // testing

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

char Pool::pullPiece() {
    if (pieces.empty()) {
        return '\0';    
    } else {
        int randomIndex = rand() % pieces.size();
        char c = pieces[randomIndex]; // Get the piece
        pieces.erase(pieces.begin() + randomIndex); // Remove the piece from the vector
    
        return c;
    }
}

int Pool::size() {
    return pieces.size();
}

void Pool::print() {
    for (int i = 0; i < pieces.size(); i++) {
        cout << pieces[i] << " ";
    }
}
