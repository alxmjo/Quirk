#include <iostream>
#include <algorithm>
#include "Game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::find;

// Constructor
Game::Game() {
    state = UNFINISHED;
    turn = PLAYER_1;
    player1.fillHand(pool);
    player2.fillHand(pool);
}

// Print beginning instructions and start game loop
void Game::playGame() {
    
    cout << endl;
    cout << "QUIRK" << endl;
    cout << "Place pieces on the board and score points." << endl << endl;
    
    while (state == UNFINISHED) {
        printStatus();
        promptMove();
        switchPlayer();
        updateState();
    }
    finishGame(state);
}

// Print current status of game
void Game::printStatus() {
    
    // Print board
    board.print();
    cout << endl;
    
    // Print points
    cout << "Current Points:" << endl;
    cout << "   Player 1 - " << player1.getPoints() << endl;
    cout << "   Player 2 - " << player2.getPoints() << endl;
    cout << endl;
    
    // Print turn
    switch (turn) {
        case PLAYER_1:  cout << "Turn: Player 1" << endl;
                        cout << "Hand: ";
                        player1.printHand();
                        cout << endl;
                        break;
        case PLAYER_2:  cout << "Turn: Player 2" << endl;
                        cout << "Hand: ";
                        player2.printHand();
                        cout << endl;
                        break;
    }
};

// Prompt player for move and check for validity
void Game::promptMove() {
    int row, column;
    char piece;
    
    // Create reference to a player
    Player& player = (turn == PLAYER_1) ? player1 : player2;
 
    cout << "Please enter your move: ";
    cin >> row >> column >> piece;
    cout << endl;
    
    // TODO: Validate input before checking if player has piece
    
    if (player.hasPiece(piece)) {
        if (board.makeMove(row, column, piece, player)) {
            player.removePiece(piece);
            player.fillHand(pool);
        } else {
            cout << "That piece can't go there. Try again." << endl << endl;
            promptMove();
        }
    } else {
        cout << "You don't have that piece to play. Try again." << endl << endl;
        promptMove();
    }
}

// Switch players
void Game::switchPlayer() {
    if (turn == PLAYER_1) {
        turn = PLAYER_2;
    } else {
        turn = PLAYER_1;
    }
}

// Update game status (between UNFINISHED, DRAW, PLAYER_1_WINS, PLAYER_2_WINS) 
void Game::updateState() {
    if (player1.handSize() > 0 || player2.handSize() > 0) {
        state = UNFINISHED;
    } else {
        if (player1.getPoints() == player2.getPoints()) {
            state = DRAW;
        } else if (player1.getPoints() > player2.getPoints()) {
            state = PLAYER_1_WINS;
        } else {
            state = PLAYER_2_WINS;
        }
    }
}

// Finish game and print result
void Game::finishGame(State state) {
    // TODO: Print final board configuration
    
    switch (state) {
        case PLAYER_1_WINS: cout << "Player 1 wins!" << endl;
                            break;
        case PLAYER_2_WINS: cout << "Player 2 wins!" << endl;
                            break;
        case DRAW:          cout << "It's a draw." << endl;
                            break;
        case UNFINISHED:    break;
    }
}