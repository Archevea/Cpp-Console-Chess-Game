#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "piece.h"

class Pawn : public BasePiece {
private:
    bool doubleJumpAvailable; // Piyon taşının ilk açılışta 2 kare hareket edip edemeyeceğini kontrol eder
public:
    Pawn(Color color, Position pos); // Piyon taşı için constructor
    virtual ~Pawn(); // Piyon taşı için destructor
    bool ValidateMove(Position moveToPosition); // Piyon taşının hareketinin geçerli olup olmadığını kontrol eder
};

#endif
