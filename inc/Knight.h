//
// Created by bartek on 06.05.23.
//

#ifndef CHESSGAME_KNIGHT_H
#define CHESSGAME_KNIGHT_H

#include "Piece.h"

class Knight : public Piece{
public:
    Knight(pieceType type, pieceColor color, int positionX, int positionY);
    bool isMovePossible(int finalPositionX, int finalPositionY)override;

};


#endif //CHESSGAME_KNIGHT_H
