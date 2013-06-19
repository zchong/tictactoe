#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "chesspiece.h"
typedef enum {player = 1, computer = -1, allelse = 0} GameDecision;
class Game {
    public:
        Game();
        int minimax(bool playerTurn, int n);
        bool isGameADraw();
        bool checkForConnectingLines(chesspiece chess);
        GameDecision checkForWinners();
    private:
        Board board;
};
#endif