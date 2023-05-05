//
// Created by Bartek on 20.04.2023.
//


#include "Board.h"
#include "Rook.h"
#include "Pawn.h"
Board::Board() {
    //board[0][0] = new Pawn(Pawn,white,0,0);
}

Board::~Board() {}

void Board::setPiece(int xPosition, int yPosition) {


}

void Board::movePiece(int xFirstPos, int yFirstPos, int xSecondPos, int ySecondPos) {
    std::swap(board[xFirstPos][yFirstPos], board[xSecondPos][ySecondPos]);
    board[xFirstPos][yFirstPos] = 0;

}
