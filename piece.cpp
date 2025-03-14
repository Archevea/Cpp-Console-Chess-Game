#include "piece.h"
#include <iostream>
#include <string>

using namespace std;

// BasePiece için constructor body
BasePiece::BasePiece() {
    type = " ";
}

// BasePiece için destructor body
BasePiece::~BasePiece() {
}

// Taşı çizmek için kullanılan fonksiyon
void BasePiece::Draw() {
    if (color == Black) {
        cout << "b";
    }
    else {
        cout << "w";
    }
    cout << type;
}

// Taşın pozisyonunu ayarlamak için kullanılan fonksiyon
void BasePiece::SetPosition(Position pos) {
    this->pos = pos;
}

// Taşın rengini almak için kullanılan fonksiyon
Color BasePiece::GetColor() {
    return color;
}
