#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "piece.h"

class Rook : public BasePiece {
public:
    Rook(Color color, Position pos); // Kale taşı için constructor body
    virtual ~Rook(); // Kale taşı için destructor body
    bool ValidateMove(Position moveToPos); // Kale taşının hareketinin geçerli olup olmadığını kontrol eder
};

#endif