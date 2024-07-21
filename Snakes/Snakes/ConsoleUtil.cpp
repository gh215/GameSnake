#include "snake_header.h"

void drawSymb(Point point, char symb)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)point.x, (SHORT)point.y };
    SetConsoleCursorPosition(hOut, coord);
    cout << symb;
}

Direction getDir(int key)
{
    static Direction dir = Direction::east;
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
    return dir;
}

list<Point> createSnakeBody(Point head, Direction dir, int size)
{
    list<Point> body;
    for (int i = 0; i < size; i++)
    {
        body.push_back(head);
        switch (dir)
        {
        case Direction::east:
            head.x--;
            break;
        case Direction::west:
            head.x++;
            break;
        case Direction::north:
            head.y++;
            break;
        case Direction::south:
            head.y--;
            break;
        }
    }
    return body;
}

