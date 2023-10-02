cmake_minimum_required(VERSION 3.10)

project(ChessGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(inc)
add_executable(ChessGame WIN32 Main.cpp inc/Game.h inc/Board.h inc/Piece.h src/Piece.cpp src/Game.cpp src/Board.cpp src/Rook.cpp inc/Rook.h src/Pawn.cpp inc/Pawn.h src/Bishop.cpp inc/Bishop.h src/King.cpp inc/King.h src/Queen.cpp inc/Queen.h src/Knight.cpp inc/Knight.h src/SDLHandler.cpp inc/SDLHandler.h)
target_link_libraries(ChessGame ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
