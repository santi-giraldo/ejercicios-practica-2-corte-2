#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

class Robot {
private:
    int x, y;
    Direction dir;

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

public:
    Robot(int x, int y, Direction dir) : x(x), y(y), dir(dir) {}

    int getX()         const { return x; }
    int getY()         const { return y; }
    Direction facing() const { return dir; }
    string directionName() const {
        switch (dir) {
            case NORTH: return "NORTH";
            case EAST:  return "EAST";
            case SOUTH: return "SOUTH";
            case WEST:  return "WEST";
        }
        return "";
}

    void turnRight() {
        dir = static_cast<Direction>((dir + 1) % 4);
    }

    void turnLeft() {
        dir = static_cast<Direction>((dir + 3) % 4);
    }

    void advance() {
        x += dx[dir];
        y += dy[dir];
    }

    void execute(const string& instructions) {
        for (char cmd : instructions) {
            if      (cmd == 'R') turnRight();
            else if (cmd == 'L') turnLeft();
            else if (cmd == 'A') advance();
            else throw invalid_argument("Instruccion invalida: " + string(1, cmd));
        }
    }
};
int main() {
    Robot robot(7, 3, NORTH);
    robot.execute("RAALAL");

    cout << "Posicion final: (" << robot.getX() << ", " << robot.getY() << ")" << endl; // (9, 4)
    cout << "Direccion: " << robot.directionName() << endl; // WEST

    return 0;
}
