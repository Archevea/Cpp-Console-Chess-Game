#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H
#include "piece.h"

class Square {
public:
    Square(); // Constructor
    virtual ~Square(); // Destructor
    BasePiece* GetPiece(); // Kare üzerindeki taşı almak için kullanılan fonksiyon
    void SetPiece(BasePiece *piece); // Kare üzerine bir taşı yerleştirmek için kullanılan fonksiyon
    void Clear(); // Kareyi temizlemek için kullanılan fonksiyon (taşı kaldırır)

private:
    BasePiece *chessPiece; // Kare üzerindeki taşı temsil eden pointer
};

#endif