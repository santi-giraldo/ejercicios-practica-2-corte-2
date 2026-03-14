#include <stdexcept>
#include <cmath>
#include <iostream>
using namespace std;

class Queen {
private:
    int row, col;

public:
    Queen(int row, int col) : row(row), col(col) {
        if (row < 0 || row > 7 || col < 0 || col > 7)
            throw invalid_argument("Position must be within the board (0-7)");
    }

    int getRow() const { return row; }
    int getCol() const { return col; }

    bool attacks(const Queen& other) const {
        if (row == other.row && col == other.col)
            throw invalid_argument("Queens cannot occupy the same position");

        if (row == other.row || col == other.col)
            return true;

        if (abs(row - other.row) == abs(col - other.col))
            return true;

        return false;
    }
};
int main() {
    // Ejemplo del enunciado: blanca en c5=(3,2), negra en f2=(6,5)
    Queen white(3, 2);
    Queen black(6, 5);
    cout << "Blanca(3,2) ataca a Negra(6,5)? "
         << (white.attacks(black) ? "SI" : "NO") << endl; // SI (diagonal)

    Queen q1(0, 0), q2(7, 7);
    cout << "Q(0,0) ataca a Q(7,7)? "
         << (q1.attacks(q2) ? "SI" : "NO") << endl; // SI (diagonal)

    Queen q3(0, 0), q4(3, 5);
    cout << "Q(0,0) ataca a Q(3,5)? "
         << (q3.attacks(q4) ? "SI" : "NO") << endl; // NO

    Queen q5(2, 4), q6(6, 4);
    cout << "Q(2,4) ataca a Q(6,4)? "
         << (q5.attacks(q6) ? "SI" : "NO") << endl; // SI (misma columna)

    return 0;
}
