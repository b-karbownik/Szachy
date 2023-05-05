//
// Created by Bartek on 21.04.2023.
//

#include "Pawn.h"

//Pawn::Pawn(pieceName name, pieceColor color, int positionX, int positionY) {
//    this->name = name;
//    this->color = color;
//    this->positionX = positionX;
//    this->positionY = positionY;
//    hasMoved = false;
//}


bool Pawn::isMovePossible(int nextPositionX, int nextPositionY) {
    if (nextPositionX - this->getPositionX() != 0) {
        return false;
    } else {
        if(!this->hasMoved && nextPositionY - this->getPositionY() == 2){
            return true;
        } else if (this->hasMoved && nextPositionY - this->getPositionY() == 1){
            return true;
        } else {
            return false;
        }
    }
}
