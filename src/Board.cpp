//
// Created by Bartek on 20.04.2023.
//


#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include <iostream>

Board::Board() {
    for (auto &boardOfPiece: boardOfPieces) {
        for (auto &j: boardOfPiece) {
            j = nullptr;
        }
    }
    boardOfPieces[0][0] = new Rook(ROOK, BLACK, 0, 0);
    boardOfPieces[1][0] = new Knight(KNIGHT, BLACK, 1, 0);
    boardOfPieces[2][0] = new Bishop(BISHOP, BLACK, 2, 0);
    boardOfPieces[3][0] = new Queen(QUEEN, BLACK, 3, 0);
    boardOfPieces[4][0] = new King(KING, BLACK, 4, 0);
    boardOfPieces[5][0] = new Bishop(BISHOP, BLACK, 5, 0);
    boardOfPieces[6][0] = new Knight(KNIGHT, BLACK, 6, 0);
    boardOfPieces[7][0] = new Rook(ROOK, BLACK, 7, 0);
    for (int i = 0; i <= 7; i++) {
        boardOfPieces[i][1] = new Pawn(PAWN, BLACK, i, 1);
    }
    boardOfPieces[0][7] = new Rook(ROOK, WHITE, 0, 7);
    boardOfPieces[1][7] = new Knight(KNIGHT, WHITE, 1, 7);
    boardOfPieces[2][7] = new Bishop(BISHOP, WHITE, 2, 7);
    boardOfPieces[3][7] = new Queen(QUEEN, WHITE, 3, 7);
    boardOfPieces[4][7] = new King(KING, WHITE, 4, 7);
    boardOfPieces[5][7] = new Bishop(BISHOP, WHITE, 5, 7);
    boardOfPieces[6][7] = new Knight(KNIGHT, WHITE, 6, 7);
    boardOfPieces[7][7] = new Rook(ROOK, WHITE, 7, 7);

    for (int i = 0; i <= 7; i++) {
        boardOfPieces[i][6] = new Pawn(PAWN, WHITE, i, 6);
    }
}

bool Board::isFieldEmpty(int xPosition, int yPosition) {
    if (this->boardOfPieces[xPosition][yPosition] == nullptr) {
        return true;
    }
    return false;
}


bool Board::isPieceOtherColor(Piece *firstPiece, Piece *secondPiece) {
    if (firstPiece == nullptr || secondPiece == nullptr) {
        std::cout << "Pole puste" << std::endl;
        return false;
    }
    if (firstPiece->getColor() == secondPiece->getColor()) {
        std::cout << "Ten sam kolor" << std::endl;
        return false;

    }
    std::cout << "Rozne kolory" << std::endl;
    return true;
}

Board::~Board() = default;

void Board::setPiece(int xPosition, int yPosition) {


}

Piece *&Board::operator[](int index) {
    return reinterpret_cast<Piece *&>(boardOfPieces[index]);
}


void Board::movePiece(int xFirstPos, int yFirstPos, int xSecondPos, int ySecondPos) {
    std::swap(boardOfPieces[xFirstPos][yFirstPos], boardOfPieces[xSecondPos][ySecondPos]);
    boardOfPieces[xFirstPos][yFirstPos] = nullptr;
    boardOfPieces[xSecondPos][ySecondPos]->setPositionX(xSecondPos);
    boardOfPieces[xSecondPos][ySecondPos]->setPositionY(ySecondPos);
//    std::cout << "Przesunieto figure z pozycji: [" << xFirstPos << ", "
//              << yFirstPos << "] na pole: ["
//              << boardOfPieces[xSecondPos][ySecondPos]->getPositionX() << ", "
//              << boardOfPieces[xSecondPos][ySecondPos]->getPositionY()
//              << "]" << std::endl;
}
