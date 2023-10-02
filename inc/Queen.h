//
// Created by bartek on 06.05.23.
//

#ifndef CHESSGAME_QUEEN_H
#define CHESSGAME_QUEEN_H

#include "Piece.h"
class Queen : public Piece{
public:
    Queen(pieceType type,pieceColor,int positionX, int positionY);
    bool isMovePossible(int finalPositionX, int finalPositionY)override;
};


#endif //CHESSGAME_QUEEN_H
