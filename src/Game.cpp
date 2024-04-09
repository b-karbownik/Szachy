#include <iostream>
#include "Game.h"
#include "Board.h"
#include <SDL.h>
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "SDLHandler.h"
#include "King.h"


Game::Game() : window(nullptr), renderer(nullptr), sdlHandler(nullptr) {
    window = SDL_CreateWindow("Szachy", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    sdlHandler = new SDLHandler(renderer);
    board = Board();
    isWhiteTurn = true;
    firstClickX = 0;
    firstClickY = 0;
    isPromotionNow = false;
    promotionChoose = PAWN;


}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    delete sdlHandler;
}


void Game::drawPieces() {

    for (int x = 0; x <= 7; x++) {
        for (int y = 0; y <= 7; y++) {
            int xPosition = x * PIECE_WIDTH;
            int yPosition = y * PIECE_HEIGHT;
            if (board.boardOfPieces[x][y] != nullptr) {
                sdlHandler->drawPiece(board.boardOfPieces[x][y]->getColor(),
                                      board.boardOfPieces[x][y]->getType(),
                                      xPosition,
                                      yPosition);
            }
        }
    }
}

void Game::update() {
    sdlHandler->drawBoard();
//    for (auto piece: *pieces) {
//        sdlHandler->drawPiece(piece.getColor(),
//                              piece.getType(),
//                              piece.getPositionX(),
//                              piece.getPositionY());
//    }
    drawPieces();
}

void Game::handleMouseEvent() {
    int mouseX, mouseY;
    Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

    if (!(mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))) {
        return;
    }

    int boardPosX = mouseX / (800 / 8);
    int boardPosY = mouseY / (800 / 8);

    if (!(boardPosX >= 0 && boardPosX < 8 && boardPosY >= 0 && boardPosY < 8)) {
        return;
    }

    if (firstClick) {
        handleFirstClick(boardPosX, boardPosY);
    } else {
        handleSecondClick(boardPosX, boardPosY);
    }
}


void Game::handleFirstClick(int boardPosX, int boardPosY) {
    firstClickX = boardPosX;
    firstClickY = boardPosY;
    if (!board.isFieldEmpty(firstClickX, firstClickY) &&
        board.boardOfPieces[firstClickX][firstClickY]->getColor() == (isWhiteTurn ? WHITE : BLACK)) {
        renderPossibleMoves(firstClickX, firstClickY);
    }
    firstClick = false;
}

void Game::handleSecondClick(int boardPosX, int boardPosY) {
    if (board.isFieldEmpty(firstClickX, firstClickY)) {
//        firstClick = true;
//        return;
    } else {
        Piece *piece = board.boardOfPieces[firstClickX][firstClickY];
        if (piece->getColor() == (isWhiteTurn ? WHITE : BLACK)) {
            if (isInCheck(piece->getColor())) {
                if ((isValidMove(firstClickX, firstClickY, boardPosX, boardPosY)) &&
                    !isMoveBlockingCheck(firstClickX, firstClickY, boardPosX, boardPosY)) {
                    board.movePiece(firstClickX, firstClickY, boardPosX, boardPosY);
                    piece->setHasMoved();
                    isWhiteTurn = !isWhiteTurn;
                }
            } else if ((isValidMove(firstClickX, firstClickY, boardPosX, boardPosY)
                        ||
                        (isCastlingPossible(firstClickX, firstClickY, boardPosX, boardPosY))) &&
                       !isMoveBlockingCheck(firstClickX, firstClickY, boardPosX, boardPosY)) {
                if (board.boardOfPieces[firstClickX][firstClickY]->getType() == KING &&
                    !board.isFieldEmpty(boardPosX, boardPosY) &&
                    board.boardOfPieces[boardPosX][boardPosY]->getType() == ROOK) {
                    if (boardPosX > firstClickX) { //roszada w prawo
                        handleCastling(firstClickX, firstClickY, firstClickX + 2, boardPosY, boardPosX, boardPosY, 5,
                                       boardPosY);
                        isWhiteTurn = !isWhiteTurn;
                    } else { //roszada w lewo

                        handleCastling(firstClickX, firstClickY, firstClickX - 2, boardPosY, boardPosX, boardPosY, 3,
                                       boardPosY);
                        isWhiteTurn = !isWhiteTurn;
                    }


                } else {
                    board.movePiece(firstClickX, firstClickY, boardPosX, boardPosY);
                    piece->setHasMoved();


                    if (piece->getType() == PAWN) {
                        if (piece->getColor() == WHITE) {
                            if (piece->getPositionY() == 0) {
                                this->isPromotionNow = true;
                                update();
                                pawnPromotion(piece->getColor(), QUEEN, piece->getPositionX(),
                                              piece->getPositionY());
                            }
                        }
                        if (piece->getColor() == BLACK) {
                            if (piece->getPositionY() == 7) {

                                update();
                                pawnPromotion(piece->getColor(), QUEEN, piece->getPositionX(),
                                              piece->getPositionY());
                            }
                        }
                    }
                    isWhiteTurn = !isWhiteTurn;
                }
            }
        }
    }
    if (isCheckMate()) {
        update();
        std::cout << "Szach i Mat. Wygrywa:" << std::endl;
        if (isWhiteTurn) {
            std::cout << "Czarny" << std::endl;
        } else {
            std::cout << "Biały" << std::endl;
        }
        SDL_Delay(5000);
        SDL_Quit();

    }
    update();
    firstClick = true;
}


void Game::handleCastling(int kingStartX, int kingStartY, int kingEndX, int kingEndY, int rookStartX, int rookStartY,
                          int rookEndX, int rookEndY) {
    Piece *king = board.boardOfPieces[kingStartX][kingStartY];
    board.movePiece(kingStartX, kingStartY, kingEndX, kingEndY);
    king->setHasMoved();

    Piece *rook = board.boardOfPieces[rookStartX][rookStartY];
    board.movePiece(rookStartX, rookStartY, rookEndX, rookEndY);
    rook->setHasMoved();

}


bool Game::isValidMove(int startX, int startY, int endX, int endY) {
    Piece *piece = board.boardOfPieces[startX][startY];
    if (piece) {
        if (piece->getType() == PAWN) {     //Bicie pionem
            if (abs(piece->getPositionX() - endX) == 1) {
                if (piece->getColor() == BLACK && endY == piece->getPositionY() + 1) {
                    if (!board.isFieldEmpty(endX, endY) &&
                        board.boardOfPieces[endX][endY]->getColor() != piece->getColor())
                        return true;
                }
                if (piece->getColor() == WHITE && endY == piece->getPositionY() - 1) {
                    if (!board.isFieldEmpty(endX, endY) &&
                        board.boardOfPieces[endX][endY]->getColor() != piece->getColor())
                        return true;
                }
                return false;
            }
        }
//        if (piece->getType() == KING) {
//            if (isCastlingPossible(startX, startY, endX, endY)) {
//                return true;
//            }
//        }

        if (piece->isMovePossible(endX, endY) &&
            !isOnPath(startX, startY, endX, endY) &&
            (board.isFieldEmpty(endX, endY) ||
             board.boardOfPieces[endX][endY]->getColor() != piece->getColor())) {
            if (piece->getType() == PAWN && !board.isFieldEmpty(endX, endY)) {

                return false;
            }
            return true;
        }
    }
    return false;
}

bool Game::isOnPath(int startX, int startY, int endX, int endY) {
    Piece *piece = board.boardOfPieces[startX][startY];
    if (piece != nullptr && piece->getType() == KNIGHT) {
        return false;
    }
    int deltaX = endX - startX;
    int deltaY = endY - startY;
    int steps = std::max(std::abs(deltaX), std::abs(deltaY));

    int xIncrement = (deltaX > 0) ? 1 : ((deltaX < 0) ? -1 : 0);
    int yIncrement = (deltaY > 0) ? 1 : ((deltaY < 0) ? -1 : 0);

    int x = startX + xIncrement;
    int y = startY + yIncrement;

    for (int i = 0; i < steps - 1; i++) {
        if (!board.isFieldEmpty(x, y)) {
            return true;
        }

        x += xIncrement;
        y += yIncrement;
    }

    return false;
}

void Game::renderPossibleMoves(int startX, int startY) {
    Piece *piece = board.boardOfPieces[startX][startY];
    sdlHandler->drawThickRectangle(1, startX, startY);
    if (piece != nullptr) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (((isValidMove(startX, startY, x, y) ||
                      (isCastlingPossible(firstClickX, firstClickY, x, y))) &&
                     !isMoveBlockingCheck(startX, startY, x, y))) {
                    pieceColor kingColor = (isWhiteTurn ? WHITE : BLACK);

                    if (isInCheck(kingColor)) {
                        if (!isMoveBlockingCheck(startX, startY, x, y)) {
                            sdlHandler->drawThickRectangle(3, x, y);
                        }
                    } else {
                        sdlHandler->drawThickRectangle(3, x, y);
                    }
                }
            }
        }
    }

    SDL_RenderPresent(renderer);
}

bool Game::isCastlingPossible(int startX, int startY, int endX, int endY) {
    Piece *king = board.boardOfPieces[startX][startY];
    Piece *rook = board.boardOfPieces[endX][endY];
    if (king == nullptr || rook == nullptr) {
        return false;
    }
    if ((king->getType() != KING || rook->getType() != ROOK) ||
        (rook->getColor() != king->getColor()) ||
        (king->getHasMoved()) ||
        (rook->getHasMoved())) {
        return false;
    }

    int direction = (endX > startX) ? 1 : -1; // Kierunek roszady (w prawo lub w lewo)
    for (int row = startX + direction; row != endX; row += direction) {
        if (!board.isFieldEmpty(row, startY)) {
            return false;
        }
    }


    return true;
}


bool Game::isCheckMate() {
    pieceColor kingColor = (isWhiteTurn ? WHITE : BLACK);
    int legalMoves = 0;
    if (isInCheck(kingColor)) {
        for (int piecePosX = 0; piecePosX < 8; piecePosX++) {
            for (int piecePosY = 0; piecePosY < 8; piecePosY++) {
                if (!board.isFieldEmpty(piecePosX, piecePosY)) {
                    Piece *piece = board.boardOfPieces[piecePosX][piecePosY];
                    for (int x = 0; x < 8; x++) {
                        for (int y = 0; y < 8; y++) {
                            if (piece->getColor() == kingColor &&
                                isValidMove(piece->getPositionX(), piece->getPositionY(), x, y) &&
                                !isMoveBlockingCheck(piecePosX, piecePosY, x, y)) {
//                                if (piece->getColor() == kingColor && piece->isMovePossible(x, y) &&
//                                    !isMoveBlockingCheck(piecePosX, piecePosY, x, y) &&
//                                    !isOnPath(piecePosX, piecePosY, x, y) && board.isFieldEmpty(x, y)) {
                                legalMoves++;
                                std::cout << "Pozycja figury blokujacej szach:" << piecePosX << ", " << piecePosY
                                          << std::endl;
                            }
                        }
                    }
                }
            }
        }
        std::cout << "Liczba legalnych ruchów: " << legalMoves << std::endl;
        if (legalMoves == 0) {
            return true;
        }
    }
    return false;

}

void Game::handlePromotion() {
    int mouseX, mouseY;
    Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

    if (!(mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))) {
        return;
    }

    if (mouseY >= 0 && mouseY <= 100) {
        if (mouseX >= 200 && mouseX <= 200 + 100) {
            std::cout << "Knight selected" << std::endl;
            this->promotionChoose = KNIGHT;
        } else if (mouseX >= 300 && mouseX <= 300 + 100) {
            std::cout << "Bishop selected" << std::endl;
            this->promotionChoose = BISHOP;
        } else if (mouseX >= 400 && mouseX <= 400 + 100) {
            std::cout << "Rook selected" << std::endl;
            this->promotionChoose = ROOK;
        } else if (mouseX >= 500 && mouseX <= 500 + 100) {
            std::cout << "Queen selected" << std::endl;
            this->promotionChoose = QUEEN;
        }
    }
}


void Game::pawnPromotion(pieceColor color, pieceType type, int positionX, int positionY) {
    switch (type) {
        case QUEEN: {
            board.boardOfPieces[positionX][positionY] = nullptr;
            board.boardOfPieces[positionX][positionY] = new Queen(QUEEN, color, positionX, positionY);
            break;
        }
        case ROOK: {
            board.boardOfPieces[positionX][positionY] = nullptr;
            board.boardOfPieces[positionX][positionY] = new Rook(ROOK, color, positionX, positionY);
            break;
        }
        case BISHOP: {
            board.boardOfPieces[positionX][positionY] = nullptr;
            board.boardOfPieces[positionX][positionY] = new Bishop(BISHOP, color, positionX, positionY);
            break;
        }
        case KNIGHT: {
            board.boardOfPieces[positionX][positionY] = nullptr;
            board.boardOfPieces[positionX][positionY] = new Knight(KNIGHT, color, positionX, positionY);
            break;

            default: {
                break;
            }
        }
    }
}


bool Game::isMoveBlockingCheck(int startX, int startY, int endX, int endY) {
    Piece *tempPiece = board.boardOfPieces[endX][endY];
    board.movePiece(startX, startY, endX, endY);

    pieceColor kingColor = (isWhiteTurn ? WHITE : BLACK);
    bool isInCheckAfterMove = isInCheck(kingColor);

    board.movePiece(endX, endY, startX, startY);
    board.boardOfPieces[endX][endY] = tempPiece;
    return isInCheckAfterMove;
}


bool Game::isInCheck(pieceColor kingColor) {
    int kingX = -1;
    int kingY = -1;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Piece *piece = board.boardOfPieces[x][y];
            if (piece != nullptr && piece->getType() == KING && piece->getColor() == kingColor) {
                kingX = x;
                kingY = y;
                break;
            }
        }
    }

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Piece *piece = board.boardOfPieces[x][y];
            if (piece != nullptr && piece->getColor() != kingColor) {
                if (piece->isMovePossible(kingX, kingY) && !isOnPath(x, y, kingX, kingY)) {
                    return true;
                }
            }
        }
    }

    return false;
}


void Game::init() {
    sdlHandler->drawBoard();
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

bool Game::isFieldEmpty(int x, int y) {
    for (auto piece: *pieces) {
        if (piece.getPositionX() == x && piece.getPositionX() == y) {
            return true;
        }
    }
    return false;
}