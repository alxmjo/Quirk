#include <iostream>
#include "Game.hpp"

using std::cout;
using std::endl;

Game::Game() {
    state = UNFINISHED;
}

void Game::startGame() {
    playGame();
}

void Game::playGame() {
    while (state == UNFINISHED) {
        cout << "this will only print once" << endl;
        state = PLAYER_1_WINS;
    }
}