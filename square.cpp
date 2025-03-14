#include "square.h"
#include "piece.h"

// Constructor body
Square::Square() {
    chessPiece = NULL;
}

// Destructor body
Square::~Square() {
}

// Kare üzerindeki taşı almak için kullanılan fonksiyon
BasePiece* Square::GetPiece() {
    return chessPiece;
}

// Kare üzerine bir taşı yerleştirmek için kullanılan fonksiyon
void Square::SetPiece(BasePiece *piece) {
    this->chessPiece = piece;
}

// Kareyi temizlemek için kullanılan fonksiyon (taşı kaldırır)
void Square::Clear() {
    this->chessPiece = NULL;
}