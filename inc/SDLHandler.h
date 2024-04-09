//
// Created by bartek on 02.10.23.
//

#ifndef CHESSGAME_SDLHANDLER_H
#define CHESSGAME_SDLHANDLER_H

#include "Piece.h"
#include "SDL.h"
#include "SDL_image.h"


class SDLHandler {
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    const int SCREEN_HEIGHT = 800;
    const int SCREEN_WIDTH = 800;
    const int PIECE_WIDTH = SCREEN_WIDTH / 8;
    const int PIECE_HEIGHT = SCREEN_HEIGHT / 8;

    SDLHandler(SDL_Renderer *renderer);

    void renderPossibleMoves(int startX, int startY);

    void drawThickRectangle(int thickness, int xPosition, int yPosition);

    void drawPiece(pieceColor color, pieceType type, int xPosition, int yPosition);

    void drawBoard();

    void update();

    void handleMouseEvent();

    void handleFirstClick();

    void handleSecondClick();

};


#endif //CHESSGAME_SDLHANDLER_H
