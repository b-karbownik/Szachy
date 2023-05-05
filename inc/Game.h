//
// Created by Bartek on 21.04.2023.
//

#ifndef CHESSGAME_GAME_H
#define CHESSGAME_GAME_H

#include "SDL.h"
#include "Board.h"

class Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    Board board;
    bool isWhiteTurn;
public:
    const int SCREEN_HEIGHT = 800;
    const int SCREEN_WIDTH = 800;
    const int PIECE_WIDTH = SCREEN_WIDTH / 8;
    const int PIECE_HEIGHT = SCREEN_HEIGHT / 8;
    Game();

    ~Game();

    void init();

    void drawBoard();

    void drawPieces();

    void update();
    bool isWindowOpen();
    void handleMouseEvent();
    void redrawPieces();
};


#endif //CHESSGAME_GAME_H
