#include "snake_header.h"

void drawSymb(Point point, char symb)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)point.x, (SHORT)point.y };
    SetConsoleCursorPosition(hOut, coord);
    cout << symb;
}

void flush()
{
    while (_kbhit())
    {
        _getch();
    }
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

Point getRandomPoint(const Point& ul, const Point& lr)
{
    return
    {
        ul.x + 1 + rand() % (lr.x - ul.x - 1),
        ul.y + 1 + rand() % (lr.y - ul.y - 1)
    };
}