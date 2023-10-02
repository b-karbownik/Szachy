//
// Created by bartek on 06.05.23.
//

#ifndef CHESSGAME_PAWN_H
#define CHESSGAME_PAWN_H

#include "Piece.h"

class Pawn : public Piece{
private:
public:
    bool isMovePossible(int finalPositionX, int finalPositionY)override;
    Pawn(pieceType type, pieceColor color, int positionX, int positionY);
};


#endif //CHESSGAME_PAWN_H
