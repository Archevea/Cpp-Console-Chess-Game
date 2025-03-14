#include "bishop.h"
#include "board.h"

extern Board board;

// Fil taşı için constructor body
Bishop::Bishop(Color color, Position pos) {
    this->type = "B";
    this->color = color;
    this->pos = pos;
}

// Fil taşı için destructor body
Bishop::~Bishop() {

}

// Fil taşının hareketinin geçerli olup olmadığını kontrol eder
bool Bishop::ValidateMove(Position moveToPos) {
    bool validMove = false;

    // Hedef konum ile mevcut konum arasındaki farkları hesaplar
    int rowDifference = std::abs(moveToPos.ypos - pos.ypos);
    int colDifference = std::abs(moveToPos.xpos - pos.xpos);

    if (rowDifference == colDifference) {
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