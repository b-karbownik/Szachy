//
// Created by bartek on 06.05.23.
//

#include "Bishop.h"
#include <iostream>

Bishop::Bishop(pieceType type, pieceColor color, int positionX, int positionY) {
    this->color = color;
    this->positionY = positionY;
    this->positionX = positionX;
    this->type = type;
}

bool Bishop::isMovePossible(int finalPositionX, int finalPositionY) {
    if ((finalPositionX >= 0 && finalPositionX < 8) && (finalPositionY >= 0 && finalPositionY < 8)) {
        int deltaX = finalPositionX - this->positionX;
        int deltaY = finalPositionY - this->positionY;
        if (finalPositionX != this->positionX) {
            if (abs(deltaX) == abs(deltaY)) {
                return true;
            }
        }
    }
    return false;
}
