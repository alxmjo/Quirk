#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "Pool.hpp"
#include "Player.hpp"

enum State {PLAYER_1_WINS, PLAYER_2_WINS, DRAW, UNFINISHED};
enum Turn {PLAYER_1, PLAYER_2};

class Game {
    private:
        Board board;
        Pool pool;
        Player player1;
        Player player2;
        State state;
        Turn turn;

    public:
        Game();
        void playGame();
        void printStatus();
        void promptMove();
        void switchPlayer();
        void updateState();
        void finishGame(State);
};

#endif