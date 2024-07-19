#include "snake_header.h"

void Board::drawBorders()
{
    for (int x = ul.x; x <= lr.x; ++x)
    {
        drawSymb({ x, ul.y }, '-');
        drawSymb({ x, lr.y }, '-');
    }
    for (int y = ul.y + 1; y < lr.y; ++y)
    {
        drawSymb({ ul.x, y }, '|');
        drawSymb({ lr.x, y }, '|');
    }

    snake.draw();
}

bool Board::checkBorderHit()
{
    Point head = snake.getHead();
    return (head.x <= ul.x || head.x >= lr.x || head.y <= ul.y || head.y >= lr.y);
}
