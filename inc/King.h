//
// Created by bartek on 27.04.23.
//

#ifndef SDL2TEST_KING_H
#define SDL2TEST_KING_H
#include "Piece.h"

class King : Piece {
private:
    bool hasMoved;
public:
    King();
    ~King();

};


#endif //SDL2TEST_KING_H