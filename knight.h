#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "piece.h"

class Knight : public BasePiece {
public:
    Knight(Color color, Position pos); // At taşı için constructor
    virtual ~Knight(); // At taşı için destructor
    bool ValidateMove(Position moveToPosition); // At taşının hareketinin geçerli olup olmadığını kontrol eder
};

#endif