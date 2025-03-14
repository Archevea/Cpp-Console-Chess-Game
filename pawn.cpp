#include "pawn.h"
#include "board.h"

using namespace std;
extern Board board;

// Piyon taşı için constructor body
Pawn::Pawn(Color color, Position pos) {
    this->type = "P";
    this->color = color;
    this->pos = pos;
    this->doubleJumpAvailable = true;
}

// Piyon taşı için destructor body
Pawn::~Pawn() {

}

// Piyon taşının hareketinin geçerli olup olmadığını kontrol eder
bool Pawn::ValidateMove(Position moveToPos) {
    bool validMove = false;

    // Hedef konum ile mevcut konum arasındaki farkları hesaplar
    int rowDifference = moveToPos.ypos - pos.ypos;
    int colDifference = std::abs(moveToPos.xpos - pos.xpos);

    // Piyonun ileri hareket etme kontrolü
    if (color == Color::White) {
        if (rowDifference == 1 && colDifference == 0 && board.GetPiece(moveToPos) == nullptr) {
            // Beyaz piyon sadece yukarı doğru bir kare ileri hareket edebilir
            validMove = true;
        } else if (pos.ypos == 1 && rowDifference == 2 && colDifference == 0 &&
                   board.GetPiece(moveToPos) == nullptr && board.GetPiece({pos.xpos, pos.ypos + 1}) == nullptr) {
            // Piyon başlangıç konumundaysa ve iki kare ileri hareket edebilirse
            validMove = true;
        }
    } else if (color == Color::Black) {
        if (rowDifference == -1 && colDifference == 0 && board.GetPiece(moveToPos) == nullptr) {
            // Siyah piyon sadece aşağı doğru bir kare ileri hareket edebilir
            validMove = true;
        } else if (pos.ypos == 6 && rowDifference == -2 && colDifference == 0 &&
                   board.GetPiece(moveToPos) == nullptr && board.GetPiece({pos.xpos, pos.ypos - 1}) == nullptr) {
            // Piyon başlangıç konumundaysa ve iki kare ileri hareket edebilirse
            validMove = true;
        }
    }

    // Piyonun düşman taşı yeme yeteneği kontrolü
    if (colDifference == 1) {
        if (rowDifference == 1 && board.GetPiece(moveToPos) != nullptr &&
            board.GetPiece(moveToPos)->GetColor() != this->color) {
            // Beyaz piyonun sağ çaprazında düşman taşı varsa
            validMove = true;
        } else if (rowDifference == -1 && board.GetPiece(moveToPos) != nullptr &&
                   board.GetPiece(moveToPos)->GetColor() != this->color) {
            // Siyah piyonun sol çaprazında düşman taşı varsa
            validMove = true;
        } else {
            validMove = false;
        }
    }

    return validMove;
}
