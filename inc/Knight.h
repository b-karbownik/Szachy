//
// Created by bartek on 27.04.23.
//

#ifndef SDL2TEST_KNIGHT_H
#define SDL2TEST_KNIGHT_H
#include "Piece.h"

class Knight : Piece{
private:
public:
    Knight();
    ~Knight();
    bool isMovePossible(int posiitonX, int PositionY) override;

};


#endif //SDL2TEST_KNIGHT_H
