#include <stdexcept>
#include <cmath>
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
