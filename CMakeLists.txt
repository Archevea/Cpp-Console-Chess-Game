cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chess main.cpp
        board.h
        board.cpp
        piece.h
        piece.cpp
        king.h
        king.cpp
        knight.h
        knight.cpp
        queen.h
        queen.cpp
        pawn.h
        pawn.cpp
        bishop.h
        bishop.cpp
        rook.h
        rook.cpp
        square.h
        square.cpp)
