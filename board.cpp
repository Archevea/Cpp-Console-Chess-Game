#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "queen.h"
#include "knight.h"
#include "king.h"
#include "bishop.h"
#include <iostream>

using namespace std;

// Satranç tahtası için constructor body
Board::Board() {
    InitializePieces();
}

// Satranç tahtası için destructor
Board::~Board() {
}

// Tahtayı çizmek için kullanılan fonksiyon
void Board::Draw() {
    for (int row = 7; row >= 0; row--) {

        // Yatay satır bölücüleri çizer
        cout << "   ";
        for (int col = 0; col < 8; col++) {
            cout << "-----";
        }
        cout << "-" << endl;


        // Dikey satır bölücü ve satranç taşı çizer
        cout << row + 1 << "  ";
        for (int col = 0; col < 8; col++) {
            cout << "| ";
            BasePiece *currPiece = board[row][col].GetPiece();
            if (currPiece != NULL) {
                currPiece->Draw();
            } else {
                cout << "  ";
            }
            cout << " ";
        }

        // Satır sonu için bölücü çizer
        cout << "|" << endl;

    }

    // Son satır için yatay bölücü çizer
    cout << "   ";
    for (int col = 0; col < 8; col++) {
        cout << "-----";
    }
    cout << "-" << endl;

    cout << "   ";
    for (int col = 0; col < 8; col++) {
        cout << "  " << (char) (col + 97) << "  ";
    }
    cout << endl << endl;

}

// Taşları başlangıç pozisyonlarına yerleştiren fonksiyon
void Board::InitializePieces() {

    // Piyon
    for (int col = 0; col < 8; col++) {
        Position blackPawnPos = {col,6};
        board[blackPawnPos.ypos][blackPawnPos.xpos].SetPiece(new Pawn(Black, blackPawnPos));

        Position whitePawnPos = {col,1};
        board[whitePawnPos.ypos][blackPawnPos.xpos].SetPiece(new Pawn(White, whitePawnPos));
    }

    // Kale
    Position whiteRookPos = {0,0};
    board[whiteRookPos.ypos][whiteRookPos.xpos].SetPiece(new Rook(White, whiteRookPos));

    Position whiteRookPos2 = {7,0};
    board[whiteRookPos2.ypos][whiteRookPos2.xpos].SetPiece(new Rook(White, whiteRookPos2));

    Position blackRookPos = {0,7};
    board[blackRookPos.ypos][blackRookPos.xpos].SetPiece(new Rook(Black, blackRookPos));

    Position blackRookPos2 = {7,7};
    board[blackRookPos2.ypos][blackRookPos2.xpos].SetPiece(new Rook(Black, blackRookPos2));

    // At
    Position whiteKnightPos = {1,0};
    board[whiteKnightPos.ypos][whiteKnightPos.xpos].SetPiece(new Knight(White, whiteKnightPos));

    Position whiteKnightPos2 = {6,0};
    board[whiteKnightPos2.ypos][whiteKnightPos2.xpos].SetPiece(new Knight(White, whiteKnightPos2));

    Position blackKnightPos = {1,7};
    board[blackKnightPos.ypos][blackKnightPos.xpos].SetPiece(new Knight(Black, blackKnightPos));

    Position blackKnightPos2 = {6,7};
    board[blackKnightPos2.ypos][blackKnightPos2.xpos].SetPiece(new Knight(Black, blackKnightPos2));

    // Fil
    Position whiteBishopPos = {2,0};
    board[whiteBishopPos.ypos][whiteBishopPos.xpos].SetPiece(new Bishop(White, whiteBishopPos));

    Position whiteBishopPos2 = {5,0};
    board[whiteBishopPos2.ypos][whiteBishopPos2.xpos].SetPiece(new Bishop(White, whiteBishopPos2));

    Position blackBishopPos = {2,7};
    board[blackBishopPos.ypos][blackBishopPos.xpos].SetPiece(new Bishop(Black, blackBishopPos));

    Position blackBishopPos2 = {5,7};
    board[blackBishopPos2.ypos][blackBishopPos2.xpos].SetPiece(new Bishop(Black, blackBishopPos2));

    // Şah
    Position whiteKingPos = {4,0};
    board[whiteKingPos.ypos][whiteKingPos.xpos].SetPiece(new King(White, whiteKingPos));

    Position blackKingPos = {4,7};
    board[blackKingPos.ypos][blackKingPos.xpos].SetPiece(new King(Black, blackKingPos));

    // Vezir
    Position blackQueenPos = {3,7};
    board[blackQueenPos.ypos][blackQueenPos.xpos].SetPiece(new Queen(Black, blackQueenPos));

    Position blackQueenPos2 = {3,0};
    board[blackQueenPos2.ypos][blackQueenPos2.xpos].SetPiece(new Queen(White, blackQueenPos2));

}

// Bir taşın belirtilen pozisyondan başka bir pozisyona hareket etmesini sağlayan fonksiyon
bool Board::MovePiece(Position fromPos, Position toPos) {
    bool moveCompleted = false;

    // Square object arrayinden taş alır
    BasePiece *origPiece = board[fromPos.ypos][fromPos.xpos].GetPiece();

    // Hamlenin yapılıp yapılamayacağını kontorl eder
    if (origPiece != NULL && origPiece->ValidateMove(toPos) && IsWithinBoard(toPos)) {

        // Hamleyi yapar
        origPiece->SetPosition(toPos);
        board[toPos.ypos][toPos.xpos].SetPiece(origPiece);
        board[fromPos.ypos][fromPos.xpos].Clear();

        moveCompleted = true;
    }

    return moveCompleted;
}

// Belirtilen pozisyondaki kareden taşı almak için kullanılan fonksiyon
BasePiece* Board::GetPiece(Position piecePos) {
    return board[piecePos.ypos][piecePos.xpos].GetPiece();
}

// Verilen pozisyonun tahta sınırları içinde olup olmadığını kontrol eden fonksiyon
bool Board::IsWithinBoard(Position pos) {

    if ((0 <= pos.xpos && pos.xpos <= 7) && (0 <= pos.ypos && pos.ypos <= 7)) {
        return true;
    }

    return false;
}

// Belirtilen iki pozisyon arasındaki yolu kontrol eden fonksiyon
bool Board::CheckPathClear(Position start, Position end) {
    int rowStep = (end.ypos - start.ypos) / std::max(1, std::abs(end.ypos - start.ypos));
    int colStep = (end.xpos - start.xpos) / std::max(1, std::abs(end.xpos - start.xpos));

    for (int i = start.ypos + rowStep, j = start.xpos + colStep;
         i != end.ypos || j != end.xpos;
         i += rowStep, j += colStep) {
        if (board[i][j].GetPiece() != nullptr) {
            // Yolda taş var
            return false;
        }
    }
    // Yolda taş yok
    return true;
}