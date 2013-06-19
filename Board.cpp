#include "Board.h"
#include <iostream>
using namespace std;

#define MAX_BOARD_SIZE 10
Board::Board()
{
    board = new char(MAX_BOARD_SIZE);
    for (int i = 1; i < MAX_BOARD_SIZE; i++)
    {
        board[i] = '_';
    }    
}
Board::~Board()
{
    delete [] board;
}

int Board::boardSize()
{
    return MAX_BOARD_SIZE;
}

bool Board::insertIntoPosition(int position, chesspiece input)
{
    bool success = false;
    if (isValidPosition(position) && isValidInput(input))
    {
        board[position] = input.getPieceLabel();
        success = true;
    }
    return success;
}

bool Board::isPositionEmpty(int position)
{
    return (board[position] == '_');
}

bool Board::removePosition(int position)
{
    bool isPieceRemoved = false;
    if (isValidPosition(position))
    {
        board[position] = '_';
        isPieceRemoved = true;
    }
    return isPieceRemoved;
}

chesspiece Board::getPieceAtPosition(int position)
{
    chesspiece piece;
    if (isValidPosition(position))
    {
        piece.setPieceLabel(board[position]);
    }
    return piece;
}

bool Board::isValidPosition(int position)
{
    return (position >= 1 && position <= 9);
}

//private helper
bool Board::isValidInput(chesspiece input)
{
    char c = input.getPieceLabel();
    return (c == 'X' || c == 'O' || c == '_');
}