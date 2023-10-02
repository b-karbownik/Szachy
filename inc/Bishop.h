//
// Created by bartek on 06.05.23.
//

#ifndef CHESSGAME_BISHOP_H
#define CHESSGAME_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(pieceType type, pieceColor color, int positionX, int positionY);

    bool isMovePossible(int finalPositionX, int finalPositionY) override;
};


#endif //CHESSGAME_BISHOP_H
