#include "queen.h"
#include "board.h"

extern Board board;

// Vezir taşı için constructor body
Queen::Queen(Color color, Position pos) {
    this->type = "Q";
    this->color = color;
    this->pos = pos;
}

// Vezir taşı için destructor body
Queen::~Queen() {

}

// Vezir taşının hareketinin geçerli olup olmadığını kontrol eder
bool Queen::ValidateMove(Position moveToPos) {
    bool validMove = false;

    // Hedef konum ile mevcut konum arasındaki farkları hesaplar
    int rowDifference = std::abs(moveToPos.ypos - pos.ypos);
    int colDifference = std::abs(moveToPos.xpos - pos.xpos);

    // Yatay, dikey veya çapraz hareket kontrolü
    if ((rowDifference == 0 && colDifference != 0) ||   // Yatay hareket
        (rowDifference != 0 && colDifference == 0) ||   // Dikey hareket
        (rowDifference == colDifference)) {               // Çapraz hareket

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

