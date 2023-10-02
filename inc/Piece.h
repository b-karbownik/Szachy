//
// Created by Bartek on 21.04.2023.
//

#ifndef CHESSGAME_PIECE_H
#define CHESSGAME_PIECE_H

enum pieceType {
    PAWN, KNIGHT, ROOK, BISHOP, KING, QUEEN
};

enum pieceColor {
    WHITE, BLACK
};

class Piece {
protected:
    pieceType type;
    pieceColor color;
    int positionX;
    int positionY;
    bool hasMoved;

public:
    Piece();
    virtual ~Piece();
    int getPositionX();
    void setPositionX(int positionX);
    void setPositionY(int positionY);
    int getPositionY();
    pieceType getType();
    pieceColor getColor();
    bool getHasMoved();
    void setHasMoved();
    virtual bool isMovePossible(int finalPositionX, int finalPositionY);
};

#endif // CHESSGAME_PIECE_H
