//
// Created by bartek on 02.10.23.
//

#include "SDLHandler.h"
#include "Board.h"
#include <iostream>

SDLHandler::SDLHandler(SDL_Renderer *renderer) : renderer(renderer) {}

void SDLHandler::drawBoard() {

    SDL_Color whiteColor = {250, 235, 215, 0};
    SDL_Color blackColor = {244, 164, 96, 0};
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            SDL_Rect field = {x * SCREEN_WIDTH / 8, y * SCREEN_HEIGHT / 8, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8};
            if ((x + y) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, whiteColor.r, whiteColor.g, whiteColor.b, whiteColor.a);
            } else {
                SDL_SetRenderDrawColor(renderer, blackColor.r, blackColor.g, blackColor.b, blackColor.a);
            }
            SDL_RenderFillRect(renderer, &field);
        }
    }
}

void SDLHandler::drawPiece(pieceColor color, pieceType type, int xPosition, int yPosition) {
    SDL_Surface *image = nullptr;
    SDL_Rect pieceRect = {xPosition, yPosition, PIECE_WIDTH, PIECE_HEIGHT};
    switch (type) {
        case PAWN:
            image = IMG_Load((color == WHITE) ? "wp.png" : "bp.png");
            break;

        case KNIGHT:
            image = IMG_Load((color == WHITE) ? "wn.png" : "bn.png");
            break;

        case ROOK:
            image = IMG_Load((color == WHITE) ? "wr.png" : "br.png");
            break;

        case BISHOP:
            image = IMG_Load((color == WHITE) ? "wb.png" : "bb.png");
            break;

        case KING:
            image = IMG_Load((color == WHITE) ? "wk.png" : "bk.png");
            break;

        case QUEEN:
            image = IMG_Load((color == WHITE) ? "wq.png" : "bq.png");
            break;

        default:
            return;
    }

    if (image == nullptr) {
        std::cerr << "Image loading failed.\n";
        return;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    if (texture == nullptr) {
        std::cerr << "Texture creating failed.\n";
        return;
    }


    SDL_RenderCopy(renderer, texture, nullptr, &pieceRect);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture);
}


void SDLHandler::drawThickRectangle(int thickness, int xPosition, int yPosition) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = {xPosition * PIECE_WIDTH, yPosition * PIECE_HEIGHT, PIECE_WIDTH, PIECE_HEIGHT};
    if (thickness == 1) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &rect);
    } else {
        for (int i = 0; i < thickness; ++i) {
            SDL_RenderDrawRect(renderer, &rect);
            rect.x++;
            rect.y++;
            rect.w -= 2;
            rect.h -= 2;
        }
    }
}



//void Game::pawnPromotionGUI(pieceColor color) {
//    SDL_SetRenderDrawColor(renderer, 205, 81, 81, 255);
//    int buttonW = 100;
//    int buttonH = 100;
//    int buttonPositions[4] = {
//            200, 300, 400, 500
//    };
//    std::string paths[4]{
//            "n.png",
//            "b.png",
//            "r.png",
//            "q.png"
//
//    };
//    SDL_Surface *image = nullptr;
//    for (int i = 0; i < 4; i++) {
//        switch (color) {
//            case WHITE: {
//                std::string path = "w" + paths[i];
//                image = IMG_Load(path.c_str());
//
//                break;
//            }
//            case BLACK: {
//                std::string path = "b" + paths[i];
//                image = IMG_Load(path.c_str());
//
//                break;
//            }
//            default: {
//                break;
//            }
//        }
//        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
//
//        SDL_Rect rect = {buttonPositions[i], 0, buttonW, buttonH};
//        SDL_RenderFillRect(renderer, &rect);
//        SDL_RenderCopy(renderer, texture, nullptr, &rect);
//
//
//
//    }
//    this->isPromotionNow = true;
//    SDL_RenderPresent(renderer);
//
//}
