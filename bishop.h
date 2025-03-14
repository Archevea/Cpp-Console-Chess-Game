#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "piece.h"

class Bishop : public BasePiece {
public:
    Bishop(Color color, Position pos); // Fil taşı için constructor
    virtual ~Bishop(); // Fil taşı için destructor

    bool ValidateMove(Position moveToPosition); // Fil taşının hareketinin geçerli olup olmadığını kontrol eder
};

#endif
