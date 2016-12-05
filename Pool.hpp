#ifndef POOL_HPP
#define POOL_HPP

#include <vector>
using std::vector;

class Pool {
    private:
        vector<char> pieces;
    public:
        Pool();
        int getPoolSize(); // for testing
        void printPool(); // for testing
        char pullPiece();
};

#endif