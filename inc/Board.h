//
// Created by Bartek on 20.04.2023.
//

#ifndef CHESSGAME_BOARD_H
#define CHESSGAME_BOARD_H

#include <SDL.h>
#include "Piece.h"

class Board {
    friend class Game;

private:
    Piece* boardOfPieces[8][8]{};
public:
    Board();
    ~Board();
    bool isFieldEmpty(int xPosiiton, int yPosition);
    bool isPieceOtherColor(Piece* firstPiece, Piece* secondPiece);
    Piece*& operator[](int index);
    void setPiece(int xPosition, int yPosition);
    void movePiece(int xFirstPos, int yFirstPos,int xSecondPos, int ySecondPos );
};


#endif //CHESSGAME_BOARD_H
