#include "Rook.h"
#include "board.h"

extern Board board;

// Kale taşı için constructor body
Rook::Rook(Color color, Position pos) {
    this->type = "R";
    this->color = color;
    this->pos = pos;
}

// Kale taşı için destructor body
Rook::~Rook() {

}

// Kale taşının hareketinin geçerli olup olmadığını kontrol eder
bool Rook::ValidateMove(Position moveToPos) {
    bool validMove = false;

    // Hedef konum ile mevcut konum arasındaki farkları hesapla
    int rowDifference = std::abs(moveToPos.ypos - pos.ypos);
    int colDifference = std::abs(moveToPos.xpos - pos.xpos);

    // Yatay veya dikey hareket kontrolü
    if ((rowDifference > 0 && colDifference == 0) ||   // Dikey hareket
        (rowDifference == 0 && colDifference > 0)) {   // Yatay hareket

        // Hareket edilen yol boyunca başka taş olup olmadığını kontrol eder
        if (board.CheckPathClear(pos, moveToPos)) {
            // Hedef konumda taş varsa ve bu taş kendi renginde değilse, hamle geçerli kabul edilir
            if (board.GetPiece(moveToPos) == nullptr || board.GetPiece(moveToPos)->GetColor() != this->color) {
                validMove = true;
            }
        }
    }

    return validMove;
}

