//
// Created by bartek on 06.05.23.
//

#ifndef CHESSGAME_ROOK_H
#define CHESSGAME_ROOK_H
#include "Piece.h"

class Rook : public Piece{
private:
public:
    bool isMovePossible(int finalPositionX, int finalPositionY) override;
    Rook(pieceType type, pieceColor color, int positionX, int positionY);
};


#endif //CHESSGAME_ROOK_H
