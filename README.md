#TIC TAC TOE

A simple TicTacToe program with nice console output written using C++.

##Introduction
A Tic Tac Toe program lets the user choose his/her piece on a 3X3 board. Your goal is to align 3 of the same piece in a row/column/diagonal to win the game.

The computer (BAD GUY) will try to either win its own by doing the same, or it will block your winning ways. 

Try to beat it!

##Cool Points
If you tried to play this game, you will notice some very interesting colors on the console, as well as the game's almost god-like AI.

How did I do it, you ask?

* Console colors for the beautiful gameplay 
* Minimax algorithm, [Read Wikipedia entry here](http://en.wikipedia.org/wiki/Minimax#Minimax_algorithm_with_alternate_moves) for the God-like AI

##Classes
There are three distinct classes in this TicTacToe game:
* `Game` - This is the main game logic with minimax algorithm implemented
* `Board` - This is the board for the game, has 3X3 dimensions
* `chesspiece` - This is the piece that will be used for the game. Could have read "TicTac" and "Toe" but I decided that chesspiece is a little more generic.

Finally, there is one important class that runs the game: `tictactoegame`.

[Last updated: Jun 20, 2013] 
