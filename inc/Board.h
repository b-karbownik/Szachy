//
// Created by Bartek on 20.04.2023.
//

#ifndef CHESSGAME_BOARD_H
#define CHESSGAME_BOARD_H

#include <SDL.h>
#include <array>
#include <vector>
#include "Piece.h"

class Board {
    friend class Game;

private:
    int board[8][8] =
            {{55, 44, 33, 22, 11, 33, 44, 55},
             {66, 66, 66, 66, 66, 66, 66, 66},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {-66, -66, -66, -66, -66, -66, -66, -66},
             {-55, -44, -33, -22, -11, -33, -44, -55}};
    Piece* boardOfPieces[8][8]={};
public:
    Board();
    ~Board();
    int* operator[](int index) {
        return board[index];
    }
    void setPiece(int xPosition, int yPosition);
    void movePiece(int xFirstPos, int yFirstPos,int xSecondPos, int ySecondPos );
};


#endif //CHESSGAME_BOARD_H
