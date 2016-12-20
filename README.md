# Quirk
A command-line game inspired by the board game Qwirkle.

### Objective
I made this game to cement some of the concepts I learned in Introduction to Computer Science (CS 161) at Oregon State. It 

### Gameplay
The object of the game is to place the following characters on the board and create runs. A run is one, two, or three adjacent characters, all from the same group. The groups are as follows:
  - Upper case letters: **A B C**
  - Lower case letters: **a b c**
  - Numbers: **1 2 3**
  - First ordinal characters: **A a 1**
  - Second ordinal characters: **B b 2**
  - Third ordinal characters: **C c 3**
  
In order for two or more pieces to be adjacent, they must be from the same group, and not already used in that run.

A board might look like this:

      0 1 2 3 4 5 6 7 8 9
    0 . . . . . . . . . .
    1 . . . . . . . . . .
    2 . . 1 3 . . . . . .
    3 . . . C A B . . . .
    4 . . . c . . . . . .
    5 . . . . . . . . . .
    6 . . . . . . . . . .
    7 . . . . . . . . . .
    8 . . . . . . . . . .
    9 . . . . . . . . . .
