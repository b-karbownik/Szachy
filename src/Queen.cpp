//
// Created by bartek on 06.05.23.
//
#include <iostream>
#include "Queen.h"
Queen::Queen(pieceType type, pieceColor color, int positionX, int positionY) {
    this->color = color;
    this->positionY = positionY;
    this->positionX = positionX;
    this->type = type;
}

bool Queen::isMovePossible(int finalPositionX, int finalPositionY){
    if ((finalPositionX >= 0 && finalPositionX < 8) && (finalPositionY >= 0 && finalPositionY < 8)) {
        int deltaX = this->positionX - finalPositionX;
        int deltaY = this->positionY - finalPositionY;
        if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
            return true;
        }
    }

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