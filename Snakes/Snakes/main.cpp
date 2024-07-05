#include "snake_header.h"

void game()
{
    Board board;
    board.draw();
    while (true)
    {
        board.snakeMove();
        Sleep(frameDelay);
        board.setSnakeDir(getDir());
    }
}

int main()
{
    game();
}