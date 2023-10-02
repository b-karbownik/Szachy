//
// Created by bartek on 06.05.23.
//

#include "Rook.h"
#include <iostream>

Rook::Rook(pieceType type, pieceColor color, int positionX, int positionY) {
    this->color = color;
    this->positionY = positionY;
    this->positionX = positionX;
    this->type = type;
    hasMoved = false;
}

bool Rook::isMovePossible(int finalPositionX, int finalPositionY) {
    if ((finalPositionX >= 0 && finalPositionX < 8) && (finalPositionY >= 0 && finalPositionY < 8)) {
        int deltaX = this->positionX - finalPositionX;
        int deltaY = this->positionY - finalPositionY;
        if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
            return true;

        }
    }

    return false;
}

