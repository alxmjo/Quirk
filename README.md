# Quirk
Quirk is a command-line game inspired by the board game Qwirkle.

### Objective
I made this game to cement some of the concepts I learned in Introduction to Computer Science (CS 161) at Oregon State. It includes all of the basic pieces of a C++ program, including headers and classes, for loops and while loops, if and switch statements, arrays, and vectors. I also employ several libraries including random, iostream, and algorithm.

### Successes

Creating this game required solving a few big problems and many small problems (of course, by solving, I mean finding the solution, not inventing it). 

The first big problem I had to figure out was how to draw random pieces from the pool of available pieces. I used a `rand()` to get a random integer, and then used that integer as an index for the selecting a piece from the vector of pieces. 

Another problem that took me a while to figure out was how to identify what was a valid move and what wasn't. This was much more challenging than drawing a random piece, as my case was specific enough that I couldn't find applicable posts on StackOverflow or the like. What I ended up settling on was a function which assembled each run, both vertical and horizontal, into a vector. Those vectors could then be tested for length, and group, and other qualities. It also made counting points much easier.

### Compromises

In the real game of Qwirkle, multiple pieces can be placed at once. This dramatically increases the complexity of the game, but for simplicity's sake, I decided to allow my program to only accept one piece at a time. If I were to spend more time on this program, I would change the Game class to accept more than one piece at a time. I'd accomplish this by passing a string to cin and then parsing out pieces and coordinates (using Regex or something similar).

Another thing I would change is building a more robust user interface. Currently, the program only accepts moves and allows the user to skip turns and exit the program. Ideally, users would be able to name players, restart games, and save and load games.

### Gameplay
The object of the game is to place the following characters on the board and create runs. A run is one, two, or three adjacent characters, all from the same group. The groups are as follows:
  - Upper case letters: **A B C**
  - Lower case letters: **a b c**
  - Numbers: **1 2 3**
  - First ordinal characters: **A a 1**
  - Second ordinal characters: **B b 2**
  - Third ordinal characters: **C c 3**
  
In order for two or more pieces to be adjacent, they must be from the same group, and not already used in that run. Represented as a "perfect" three by three grid, in which each row and column are a group:

    A B C
    a b c
    1 2 3

A game in progress might look like this:

      0 1 2 3 4 5 6 7 8 9
    0 . . . . . . . . . .
    1 . . . . . . . . . .
    2 . . 2 3 . . . . . .
    3 . . . C A B . . . .
    4 . . . c . . . . . .
    5 . . . . . . . . . .
    6 . . . . . . . . . .
    7 . . . . . . . . . .
    8 . . . . . . . . . .
    9 . . . . . . . . . .

When prompted, input a move like so: ROW COLUMN PIECE  
To play the piece b at row 4, column 5, enter the following: 2 4 b 

If no piece can be played by a player, she may skip her turn like so: 0 0 s  
If no piece can be played by either player, the game may be exited like so: 0 0 x

### Scoring
Each piece played is worth one point. If it is joined with other pieces already on the board, an extra point is scored for each run that is added to. Any time a run is completed, an extra three points is scored. 

Placing a 1 at row 2, column 4 on the board above would net 8 points.

### Conclusion

The more time I spent working on this program, the more I realized that I could work on it forever. Each time I came up with one solution or improvement, it revealed another problem or inadequacy waiting to be solved. [Beyond mountains there are mountains](https://en.wikipedia.org/wiki/Mountains_Beyond_Mountains).

Eventually I decided that the point of the project was not to create a perfectly functioning, perfectly written program with every feature of the game it's based on. The point was to sharpen my C++ skills, and I'm confident that I've done that.
