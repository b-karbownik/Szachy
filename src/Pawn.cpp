//
// Created by bartek on 06.05.23.
//

#include "Pawn.h"
#include <iostream>

Pawn::Pawn(pieceType type, pieceColor color, int positionX, int positionY) {
    this->color = color;
    this->positionY = positionY;
    this->positionX = positionX;
    this->type = type;
    hasMoved = false;
}

bool Pawn::isMovePossible(int finalPositionX, int finalPositionY) {
    if ((finalPositionX >= 0 && finalPositionX < 8) && (finalPositionY >= 0 && finalPositionY < 8)) {
        int deltaX = finalPositionX - this->positionX;
        int deltaY = finalPositionY - this->positionY;
        if (this->color == BLACK) {
            if (deltaX == 0) {
                if (deltaY == 2 && !hasMoved) {
                    return true;
                } else if (deltaY == 1) {
                    return true;
                }

            }
        } else if (this->color == WHITE) {
            if (deltaX == 0) {
                if (deltaY == -2 && !hasMoved) {
                    return true;
                } else if (deltaY == -1) {
                    return true;
                }

            }
        }

    }
    return false;

}
