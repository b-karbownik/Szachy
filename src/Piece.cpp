//
// Created by Bartek on 21.04.2023.
//

#include "Piece.h"

int Piece::getPositionX() {
    return this->positionX;
}

int Piece::getPositionY() {
    return this->positionY;
}

pieceName Piece::getName(){
    return this->name;
}

bool Piece::isMovePossible(int positionX, int positionY) {
    return false;
}

bool Piece::getColor(){
    return this->color;
}
