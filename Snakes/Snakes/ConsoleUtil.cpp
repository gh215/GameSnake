#include "snake_header.h"

void draw(Point point, char symb)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)point.x, (SHORT)point.y };
    SetConsoleCursorPosition(hOut, coord);
    cout << symb;
}

Direction getDir()
{
    static Direction dir = Direction::right;
    if (_kbhit())
    {
        int key = _getch();
        if (key == ARROW)
        {
            key = _getch();
            switch (key)
            {
            case UP: dir = Direction::up; break;
            case DOWN: dir = Direction::down; break;
            case LEFT: dir = Direction::left; break;
            case RIGHT: dir = Direction::right; break;
            }
        }
    }
    return dir;
}