//
// Created by Bartek on 21.04.2023.
//

#ifndef CHESSGAME_PAWN_H
#define CHESSGAME_PAWN_H
#include "Piece.h"


class Pawn : Piece {
private:
    bool hasMoved;
public:
    Pawn(pieceName name, pieceColor color,int positionX, int positionY);
    ~Pawn();
    bool isMovePossible(int positionX, int positionY) override;
};


#endif //CHESSGAME_PAWN_H
