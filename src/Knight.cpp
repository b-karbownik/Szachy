//
// Created by bartek on 06.05.23.
//

#include "Knight.h"
#include <iostream>

Knight::Knight(pieceType type, pieceColor color, int positionX, int positionY) {
    this->type = type;
    this->color = color;
    this->positionX = positionX;
    this->positionY = positionY;
}

bool Knight::isMovePossible(int finalPositionX, int finalPositionY) {
    if ((finalPositionX >= 0 && finalPositionX < 8) && (finalPositionY >= 0 && finalPositionY < 8)) {
        int deltaX = this->positionX - finalPositionX;
        int deltaY = this->positionY - finalPositionY;
        if ((abs(deltaX) == 1 && abs(deltaY) == 2) || (abs(deltaX) == 2 && abs(deltaY) == 1)){
            return true;
        }
    }
    return false;
}
