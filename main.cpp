/*
 * CENG-241 Term Project
 * Hazırlayanlar:
 * 202138006 - Batuhan Karaköy
 * 202238037 - Çağatay Yüksel
 * 202138014 - Yunus Emre Işıktan
 * 202138018 - Yusuf Yeşilmen
 * 202138003 - Enes Türkoğlu
 *
 * */

#include "board.h"
#include "piece.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void DisplayIntro();
void DisplayInstructions();
void ToLowerCase(string *str);
bool ValidateInput(string input1, string input2);
Position ConvertChessNotation(string move);
Board board;

int main(int argc, char** argv) {

    string input1, input2;
    Color turnColor = White;
    bool moveSucceed = false;
    Position moveFrom;
    Position moveTo;

    DisplayIntro();

    while (input1 != "quit") {

        cout << string(4, '\n');

        // Satranç tahtasını ekrana yazdırır
        board.Draw();

        // Move Validation Loop
        do {

            // Oynama sırasını ekrana yazdırır
            if (turnColor == White) {
                cout << endl << "Beyazin Sirasi" << endl;
            } else {
                cout << endl << "Siyahin Sirasi" << endl;
            }

            do {
                cout << "Nereden hareket edeceginizi giriniz: ";
                cin >> input1;

                ToLowerCase(&input1);

                if (input1 == "quit") {

                    // çıkış için
                    return 0;

                }
                else if (input1 == "help") {

                    DisplayInstructions();

                }
                else {
                    cout << "Nereye hareket edeceginizi giriniz: ";
                    cin >> input2;

                    ToLowerCase(&input2);
                }

            } while (input1 == "help" || !ValidateInput(input1, input2));

            // Input must be valid, Convert Algebriac Notation into Cartesian based Coordinates
            moveFrom = ConvertChessNotation(input1);
            moveTo = ConvertChessNotation(input2);

            // Doğru renkteki taşın oynanmasını kontrol eder
            if (board.GetPiece(moveFrom)->GetColor() != turnColor) {

                cout << "Gecersiz hamle. Lutfen oynamak istediginiz tasin rengine dikkat edin! " << endl;
                moveSucceed = false;

            }
            else {
                moveSucceed = board.MovePiece(moveFrom, moveTo);

                // Hamlenin geçerli veya geçersiz olduğunu kullanıcıya bildirir
                if (moveSucceed == false) {
                    cout << "Gecersiz Hamle!" << endl;
                } else {
                    cout << "Hamle Basarili!" << endl;
                }
            }
        } while (moveSucceed == false);

        // Hamle doğru ise sırayı değiştirir
        if (turnColor == White) {
            turnColor = Black;
        } else if (turnColor == Black) {
            turnColor = White;
        }

    }

    return (EXIT_SUCCESS);
}

// Oyun Giriş Ekranı
void DisplayIntro() {
    DisplayInstructions();
    cout << "\n\n\t\t\tOyuna Baslamak Icin Enter Tusuna Basiniz" << endl;
    cin.ignore();
}

// Oyun kurallarını ekrana yazdırır
void DisplayInstructions() {

    cout << "\nKurallar:" << endl;
    cout << "Oynamak istediginiz tasin denk geldigi satir ve sutun ismini girerek hareket edebilirsiniz" << endl;
    cout << "'quit' yazarak oyudan cikabilir veya 'help' yazarak bu bilgilendirme ekranini tekrar gorebilirsiniz" << endl;
}

// Büyük veya küçük karakterden dolayı hata almamak için karakterleri küçüğe çevirir
void ToLowerCase(string *str) {
    for (size_t i = 0; i < str->length(); ++i) {
        (*str)[i] = tolower((*str)[i]);
    }
}

// Kullanıcıdan gelen input doğru mu değil mi kontrol eder hatalı ise uyarı verir
bool ValidateInput(string input1, string input2) {

    if (input1.size() != 2 || input2.size() != 2) {

        cout << "Hatali giris bicmi. Lutfen 'a2' gibi bir sekilde giris yapiniz." << endl;
    } else {

        Position moveFrom = ConvertChessNotation(input1);
        Position moveTo = ConvertChessNotation(input2);

        if (moveFrom.xpos < 0 || moveFrom.xpos > 7 || moveFrom.ypos < 0 || moveFrom.ypos > 7) {
            cout << "Baslangic noktasi sinirlar dahilinde degil!" << endl;
        }
        else if (moveTo.xpos < 0 || moveTo.xpos > 7 || moveTo.ypos < 0 || moveTo.ypos > 7) {
            cout << "Varis noktasi sinirlar dahilinde degil!" << endl;
        }
        else {
            return true;
        }
    }

    return false;
}

// Kullanıcıdan gelen inputu satranç tahtasının x ve y konumuna göre ayarlar
Position ConvertChessNotation(string moveInputStr) {

    Position movePosition;

    movePosition.xpos = (int) moveInputStr[0] - 97;
    movePosition.ypos = atoi(&moveInputStr[1]) - 1;

    return movePosition;
}