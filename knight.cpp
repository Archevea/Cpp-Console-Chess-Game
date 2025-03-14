#include "knight.h"
#include "board.h"

extern Board board;

// At taşı için constructor body
Knight::Knight(Color color, Position pos) {
    this->type = "N";
    this->color = color;
    this->pos = pos;
}

// At taşı için destructor body
Knight::~Knight() {

}

// At taşının hareketinin geçerli olup olmadığını kontrol eder
bool Knight::ValidateMove(Position moveToPos) {
    bool validMove = false;

    // Hedef konum ile mevcut konum arasındaki farkları hesaplar
    int rowDifference = std::abs(moveToPos.ypos - pos.ypos);
    int colDifference = std::abs(moveToPos.xpos - pos.xpos);

    // Atın L şeklinde hareket etme kontrolü
    if ((rowDifference == 2 && colDifference == 1) ||   // Yatay iki, dikey bir
        (rowDifference == 1 && colDifference == 2)) {   // Yatay bir, dikey iki

        // Hedef konumda taş varsa ve bu taş kendi renginde değilse, hamle geçerli kabul edilir
        if (board.GetPiece(moveToPos) == nullptr || board.GetPiece(moveToPos)->GetColor() != this->color) {
            validMove = true;
        }
    }

    return validMove;
}