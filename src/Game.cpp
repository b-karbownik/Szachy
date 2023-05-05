//
// Created by Bartek on 21.04.2023.
//
#include <iostream>
#include "Game.h"
#include "Board.h"
#include <SDL.h>
#include "SDL_image.h"

Game::Game() {
    window = SDL_CreateWindow("Szachy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Board board;
    isWhiteTurn = true;
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::drawBoard() {

    SDL_Color whiteSquare = {250, 235, 215, 0};
    SDL_Color blackSquare = {244, 164, 96, 0};
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            SDL_Rect field = {x * SCREEN_WIDTH / 8, y * SCREEN_HEIGHT / 8, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8};
            if ((x + y) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, whiteSquare.r, whiteSquare.g, whiteSquare.b, whiteSquare.a);
            } else {
                SDL_SetRenderDrawColor(renderer, blackSquare.r, blackSquare.g, blackSquare.b, blackSquare.a);
            }
            SDL_RenderFillRect(renderer, &field);
        }
    }
}


void Game::drawPieces() {

    const int KING_VALUE = 11;
    const int QUEEN_VALUE = 22;
    const int ROOK_VALUE = 55;
    const int BISHOP_VALUE = 33;
    const int KNIGHT_VALUE = 44;
    const int PAWN_VALUE = 66;
    for (int x = 0; x <= 7; x++) {
        for (int y = 0; y <= 7; y++) {
            int pieceValue = board.board[y][x];
            if (pieceValue != 0) {
                int pieceType = pieceValue / abs(pieceValue);
                int xPosiition = x * PIECE_WIDTH;
                int yPosition = y * PIECE_HEIGHT;
                SDL_Rect destRect = {xPosiition, yPosition, PIECE_WIDTH, PIECE_HEIGHT};
                SDL_Surface *image = nullptr;
                switch (abs(pieceValue)) {
                    case KING_VALUE:
                        if (pieceType > 0) {
                            image = IMG_Load("bk.png");
                        } else {
                            image = IMG_Load("wk.png");
                        }
                        break;
                    case QUEEN_VALUE:
                        if (pieceType > 0) {
                            image = IMG_Load("bq.png");
                        } else {
                            image = IMG_Load("wq.png");
                        }
                        break;

                    case ROOK_VALUE:
                        if (pieceType > 0) {
                            image = IMG_Load("br.png");
                        } else {
                            image = IMG_Load("wr.png");
                        }
                        break;
                    case BISHOP_VALUE:
                        if (pieceType > 0) {
                            image = IMG_Load("bb.png");
                        } else {
                            image = IMG_Load("wb.png");
                        }
                        break;
                    case KNIGHT_VALUE:
                        if (pieceType > 0) {
                            image = IMG_Load("bn.png");
                        } else {
                            image = IMG_Load("wn.png");
                        }
                        break;
                    case PAWN_VALUE:
                        if (pieceType > 0) {
                            image = IMG_Load("bp.png");
                        } else {
                            image = IMG_Load("wp.png");
                        }
                        break;
                    default:
                        break;
                }
                SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
                if (texture != nullptr) {
                    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }
}


void Game::handleMouseEvent() {
    static int firstClickX = -1, firstClickY = -1;
    int mouseX, mouseY;
    Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        int boardX = mouseX / 100;
        int boardY = mouseY / 100;
        std::cout << boardX << " " << boardY << "\n";
        // Set the color and transparency of the highlight
        SDL_Color highlightColor = {0, 0, 255, 128};

// Create a rectangle that covers the same area as the piece you want to highlight
        SDL_Rect highlightRect = {boardX*100, boardY*100, 100, 100};

// Set the render draw color to the highlight color
        SDL_SetRenderDrawColor(renderer, highlightColor.r, highlightColor.g, highlightColor.b, highlightColor.a);

// Draw a rectangle around the piece
        SDL_RenderDrawRect(renderer, &highlightRect);

// Present the contents of the renderer to the screen
        SDL_RenderPresent(renderer);

        if (firstClickX == -1 && firstClickY == -1) {
            if (board[boardY][boardX] != 0) {
                firstClickX = boardX;
                firstClickY = boardY;
            }
        } else {

            board.movePiece(firstClickY, firstClickX, boardY, boardX);
            drawBoard();
            drawPieces();

            firstClickX = -1;
            firstClickY = -1;
        }
    }
}

void Game::init() {
    drawBoard();
    drawPieces();
    bool isRunning = true;
    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            } else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
                handleMouseEvent();
            }
        }
    }
}


