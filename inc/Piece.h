//
// Created by Bartek on 21.04.2023.
//

#ifndef CHESSGAME_PIECE_H
#define CHESSGAME_PIECE_H

enum pieceName{Pawn,Knight,Rook,Bishop,King,Queen};
enum pieceColor{White,Black};
class Piece {
protected:
    pieceName name;
    pieceColor color;
    int positionX;
    int positionY;
public:
    Piece();
    virtual ~Piece();
    int getPositionX();
    int getPositionY();
    pieceName getName();
    bool getColor();
    virtual bool isMovePossible(int positionX, int positionY);

};


#endif //CHESSGAME_PIECE_H
