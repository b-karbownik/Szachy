//
// Created by bartek on 06.05.23.
//

#ifndef CHESSGAME_KING_H
#define CHESSGAME_KING_H

#include "Piece.h"
class King : public Piece{
private:
public:
    King(pieceType type, pieceColor color, int positionX, int positionY);
    bool isMovePossible(int finalPositionX, int finalPositionY)override;


};


#endif //CHESSGAME_KING_H
