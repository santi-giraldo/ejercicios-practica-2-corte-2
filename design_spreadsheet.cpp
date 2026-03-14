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


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
