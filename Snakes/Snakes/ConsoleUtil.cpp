#include "snake_header.h"

void drawSymb(Point point, char symb)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)point.x, (SHORT)point.y };
    SetConsoleCursorPosition(hOut, coord);
    cout << symb;
}

Direction getDir()
{
    static Direction dir = Direction::east;
    if (_kbhit())
    {
        int key = _getch();
        if (key == LEFT || key == RIGHT)
        {
            switch (dir)
            {
            case Direction::north:
                dir = (key == LEFT) ? Direction::west : Direction::east;
                break;
            case Direction::south:
                dir = (key == LEFT) ? Direction::east : Direction::west;
                break;
            case Direction::west:
                dir = (key == LEFT) ? Direction::south : Direction::north;
                break;
            case Direction::east:
                dir = (key == LEFT) ? Direction::north : Direction::south;
                break;
            }
        }
    }
    return dir;
}


void showGameOverMessage()
{
    setlocale(LC_ALL, "Russian");
    system("cls");

    const char* message = "Game Over";

    cout << "\n\n\n";
    cout << "    +----------+\n";
    cout << "    |          |\n";
    cout << "    | Game Over|\n";
    cout << "    |          |\n";
    cout << "    +----------+\n";

    cout << "\n\nНажмите любую клавишу для выхода...";
}
