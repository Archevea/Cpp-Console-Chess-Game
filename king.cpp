#include "king.h"
#include "board.h"
#include <iostream>

extern Board board;

// Şah taşı için constructor body
King::King(Color color, Position pos) {
    this->type = "K";
    this->color = color;
    this->pos = pos;
}

// Şah taşı için destructor body
King::~King() {
    std::cout << "oyun bitti";
}

// Şah taşının hareketinin geçerli olup olmadığını kontrol eder
bool King::ValidateMove(Position moveToPos) {
    bool validMove = false;

    // Hedef konum ile mevcut konum arasındaki farkları hesaplar
    int rowDifference = std::abs(moveToPos.ypos - pos.ypos);
    int colDifference = std::abs(moveToPos.xpos - pos.xpos);

    // Yatay, dikey veya çapraz bir adım kontrolü
    if ((rowDifference == 1 && colDifference == 0) ||   // Yatay hareket
        (rowDifference == 0 && colDifference == 1) ||   // Dikey hareket
        (rowDifference == 1 && colDifference == 1)) {   // Çapraz hareket

        // Hedef konumda taş varsa ve bu taş kendi renginde değilse, hamle geçerli kabul edilir
        if (board.GetPiece(moveToPos) == nullptr || board.GetPiece(moveToPos)->GetColor() != this->color) {
            validMove = true;
        }
    }

    return validMove;
}

