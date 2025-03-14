#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "piece.h"

class King : public BasePiece {
public:
    King(Color color, Position pos); // Şah taşı için constructor
    virtual ~King(); // Şah taşı için destructor
    bool ValidateMove(Position moveToPos); // Şah taşının hareketinin geçerli olup olmadığını kontrol eder
};

#endif