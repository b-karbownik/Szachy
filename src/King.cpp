//
// Created by bartek on 06.05.23.
//

#include "King.h"
#include <iostream>

King::King(pieceType type, pieceColor color, int positionX, int positionY) {
    this->color = color;
    this->positionY = positionY;
    this->positionX = positionX;
    this->type = type;
    this->hasMoved = false;
}

bool King::isMovePossible(int finalPositionX, int finalPositionY) {
    if ((finalPositionX >= 0 && finalPositionX < 8) && (finalPositionY >= 0 && finalPositionY < 8)) {
        int deltaX = this->positionX - finalPositionX;
        int deltaY = this->positionY - finalPositionY;
        if ((abs(deltaY) == 1 && abs(deltaX) == 1) ||
            (abs(deltaY) == 1 && abs(deltaX) == 0) ||
            (abs(deltaY) == 0 && abs(deltaX) == 1)) {
            return true;

        }
    }
    return false;
}