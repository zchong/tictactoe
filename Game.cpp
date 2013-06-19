#include "Game.h"

#define INFINITY 1073741824
static int positionMax, positionMin;

Game::Game(){}

int Game::minimax(bool playerTurn, int n)
{
    int gain = 0;
    int max = -INFINITY;
    int min = INFINITY;

    GameDecision whoWins = checkForWinners();
    if (whoWins == player || whoWins == computer || isGameADraw())
        return whoWins;

    for (int i = 1; i < board.boardSize(); i++)
    {
        if(board.isPositionEmpty(i))
        {
            char pieceLabel = playerTurn ? 'X' : 'O'; //place 'X' if it is player turn, else 'O'
            chesspiece piece(pieceLabel);
            board.insertIntoPosition(i, piece);
            
            gain = minimax(!playerTurn, n + 1);
            
            piece.setPieceLabel('_');
            board.insertIntoPosition(i, piece);

            if (playerTurn)
            {
                if (gain > max)
                {
                    max = gain;
                    if (n == 0)
                    {
                        positionMax = i;
                    }
                }
            } else
            {
                if (gain < min)
                {
                    min = gain;
                    if (n == 0)
                    {
                        positionMin = i;
                    }
                }
            }
        }
    }
    return (playerTurn) ? max : min; 
}

bool Game::isGameADraw()
{
    GameDecision winResults = checkForWinners();
    bool boardIsFilled = true;
    
    for (int i = 1; i < board.boardSize(); i++)
    {
        if (board.isPositionEmpty(i))
        {
            boardIsFilled = false;
            break;
        }
    }
    return (winResults == allelse && boardIsFilled);
}

bool Game::checkForConnectingLines(chesspiece chess)
{
    char ch = chess.getPieceLabel();
    
     return (
        (board.getPieceAtPosition(1).getPieceLabel() == ch && board.getPieceAtPosition(2).getPieceLabel() == ch && board.getPieceAtPosition(3).getPieceLabel() == ch) ||
        (board.getPieceAtPosition(4).getPieceLabel() == ch && board.getPieceAtPosition(5).getPieceLabel() == ch && board.getPieceAtPosition(6).getPieceLabel() == ch) ||
        (board.getPieceAtPosition(7).getPieceLabel() == ch && board.getPieceAtPosition(8).getPieceLabel() == ch && board.getPieceAtPosition(9).getPieceLabel() == ch) ||
        (board.getPieceAtPosition(1).getPieceLabel() == ch && board.getPieceAtPosition(4).getPieceLabel() == ch && board.getPieceAtPosition(7).getPieceLabel() == ch) ||
        (board.getPieceAtPosition(2).getPieceLabel() == ch && board.getPieceAtPosition(5).getPieceLabel() == ch && board.getPieceAtPosition(8).getPieceLabel() == ch) ||
        (board.getPieceAtPosition(3).getPieceLabel() == ch && board.getPieceAtPosition(6).getPieceLabel() == ch && board.getPieceAtPosition(9).getPieceLabel() == ch) ||
        (board.getPieceAtPosition(1).getPieceLabel() == ch && board.getPieceAtPosition(5).getPieceLabel() == ch && board.getPieceAtPosition(9).getPieceLabel() == ch) ||
        (board.getPieceAtPosition(3).getPieceLabel() == ch && board.getPieceAtPosition(5).getPieceLabel() == ch && board.getPieceAtPosition(7).getPieceLabel() == ch));
}

GameDecision Game::checkForWinners()
{
    GameDecision winResults = allelse;
    chesspiece piece('X');
    chesspiece anotherpiece('O');

    if (checkForConnectingLines(piece.getPieceLabel())) 
    {
        winResults = player;
    }
    else if(checkForConnectingLines(anotherpiece.getPieceLabel())) 
    {
        winResults = computer;
    } 
    return winResults;
}