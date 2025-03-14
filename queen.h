#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "piece.h"

class Queen : public BasePiece {
public:
    Queen(Color color, Position pos); // Vezir taşı için constructor
    virtual ~Queen(); // Vezir taşı için destructor
    bool ValidateMove(Position moveToPos); // Vezir taşının hareketinin geçerli olup olmadığını kontrol eder
};

#endif
