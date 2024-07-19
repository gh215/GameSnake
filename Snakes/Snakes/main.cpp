#include "snake_header.h"

void game()
{
    Board board;
    board.drawBorders();
    while (true)
    {
        board.draw();
        board.snakeMove();
        if (board.checkBorderHit())
        {
            showGameOverMessage();
            break;
        }
        Sleep(frameDelay);
        board.setSnakeDir(getDir());
    }
}

int main()
{
    game();
}
