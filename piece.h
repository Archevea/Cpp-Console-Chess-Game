#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <string>

class Board;

// Renkleri temsil eden enum yapısı
enum Color {
    Black,
    White
};

// Pozisyon bilgisini içeren struct yapısı
typedef struct Coordinates {
    int xpos;
    int ypos;

} Position;

// Temel taş sınıfı
class BasePiece {
public:
    BasePiece(); // BasePiece için constructor
    virtual ~BasePiece(); // BasePiece için destructor
    void Draw(); // Taşı çizmek için kullanılan fonksiyon
    void SetPosition(Position pos); // Taşın pozisyonunu ayarlamak için kullanılan fonksiyon
    Position GetPosition(); // Taşın mevcut pozisyonunu almak için kullanılan fonksiyon
    Color GetColor(); // Taşın rengini almak için kullanılan fonksiyon
    virtual bool ValidateMove(Position moveToPosition) = 0; // Taşın geçerli bir hamle yapabilip yapamayacağını kontrol eden fonksiyon

protected:
    std::string type; // Taşın cinsi
    Color color;  // Taşın rengi
    Position pos; // Taşın pozisyonu

};

#endif