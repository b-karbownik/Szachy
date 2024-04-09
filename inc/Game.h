//
// Created by Bartek on 21.04.2023.
//

#ifndef CHESSGAME_GAME_H
#define CHESSGAME_GAME_H

#include "SDL.h"
#include "Board.h"
#include <SDLHandler.h>
#include <vector>

class Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDLHandler *sdlHandler;
    Board board;
    bool isWhiteTurn;
    bool firstClick{};
    int firstClickX;
    int firstClickY;
    bool isPromotionNow;
    pieceType promotionChoose;

    std::vector<Piece> *pieces;
public:
    const int SCREEN_HEIGHT = 800;
    const int SCREEN_WIDTH = 800;
    const int PIECE_WIDTH = SCREEN_WIDTH / 8;
    const int PIECE_HEIGHT = SCREEN_HEIGHT / 8;

    Game();

    ~Game();

    void init();

    void drawBoard();

    bool isValidMove(int startX, int startY, int endX, int endY);

    void drawPieces();

    bool isOnPath(int startX, int startY, int endX, int endY);

    void renderPossibleMoves(int startX, int startY);


    void update();

    bool isInCheck(pieceColor kingColor);

    bool isMoveBlockingCheck(int startX, int startY, int endX, int endY);

    bool isCheckMate();

    void handleMouseEvent();

    void handleFirstClick(int boardPosX, int boardPosY);

    bool isCastlingPossible(int startX, int startY, int endX, int endY);

    void handleSecondClick(int boardPosX, int boardPosY);

    void handleCastling(int kingStartX, int kingStartY, int kingEndX, int kingEndY, int rookStartX, int rookStartY,
                        int rookEndX, int rookEndY);


    void pawnPromotion(pieceColor color, pieceType type, int positionX, int positionY);


    void pawnPromotionGUI(pieceColor color);

    void handlePromotion();

    bool isFieldEmpty(int x, int y);
};

#endif //CHESSGAME_GAME_H
