#ifndef BOARD_H
#define BOARD_H
#include "chesspiece.h"
class Board {
  public:
    Board();
    ~Board();
    bool insertIntoPosition(int position, chesspiece input);
    bool isPositionEmpty(int position);
    bool removePosition(int position);
    chesspiece getPieceAtPosition(int position);
    int boardSize();
    bool isValidPosition(int position);
    void print_board();
  private:  
    char *board;
    bool isValidInput(chesspiece input);
};
#endif