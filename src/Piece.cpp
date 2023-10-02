#include "Piece.h"

Piece::Piece() {
}

Piece::~Piece() {
}

int Piece::getPositionX() {
    return positionX;
}

int Piece::getPositionY() {
    return positionY;
}

pieceType Piece::getType() {
    return type;
}

bool Piece::getHasMoved() {
    return hasMoved;
}

void Piece::setHasMoved() {
    this->hasMoved=true;
}

void Piece::setPositionX(int positionX) {
    this->positionX=positionX;
}
void Piece::setPositionY(int positionY) {
    this->positionY=positionY;
}

pieceColor Piece::getColor() {
    return color;
}

bool Piece::isMovePossible(int finalPositionX, int finalPositionY) {

        return false;
}