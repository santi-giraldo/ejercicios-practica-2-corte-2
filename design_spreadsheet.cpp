#include <unordered_map>
#include <string>
using namespace std;

class Spreadsheet {
private:
    unordered_map<string, int> cells;

    int parseOperand(const string& s) {
        if (isdigit(s[0])) {
            return stoi(s);  
        }
        auto it = cells.find(s);
        return (it != cells.end()) ? it->second : 0;
    }

public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        cells[cell] = value;
    }

    void resetCell(string cell) {
        cells.erase(cell);
    }

    int getValue(string formula) {
        string expr = formula.substr(1);

        size_t plusPos = expr.find('+');
        string left  = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        return parseOperand(left) + parseOperand(right);
    }
};
int main() {
    Spreadsheet sp(3);

    cout << "=5+7  -> " << sp.getValue("=5+7") << endl;   // 12

    sp.setCell("A1", 10);
    cout << "=A1+6 -> " << sp.getValue("=A1+6") << endl;  // 16

    sp.setCell("B2", 15);
    cout << "=A1+B2 -> " << sp.getValue("=A1+B2") << endl; // 25

    sp.resetCell("A1");
    cout << "=A1+B2 (A1 reset) -> " << sp.getValue("=A1+B2") << endl; // 15

    return 0;
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
