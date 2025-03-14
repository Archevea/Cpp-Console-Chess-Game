#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "square.h"

class Board {
public:
    Board(); // Satranç tahtası için constructor
    virtual ~Board(); // Satranç tahtası için destructor
    void Draw(); // Tahtayı çizmek için kullanılan fonksiyon
    bool MovePiece(Position fromPos, Position toPos); // Bir taşın belirtilen pozisyondan başka bir pozisyona hareket etmesini sağlayan fonksiyon
    BasePiece* GetPiece(Position piecePos); // Belirtilen pozisyondaki kareden taşı almak için kullanılan fonksiyon
    bool CheckPathClear(Position start, Position end); // Belirtilen iki pozisyon arasındaki yolu kontrol eden fonksiyon

private:
    Square board[8][8]; // Satranç tahtasını temsil eden bir 2D array
    void InitializePieces(); // Taşları başlangıç pozisyonlarına yerleştiren fonksiyon
    bool IsWithinBoard(Position pos); // Verilen pozisyonun tahta sınırları içinde olup olmadığını kontrol eden fonksiyon
};

#endif