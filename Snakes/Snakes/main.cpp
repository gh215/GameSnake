#include "snake_header.h"

void game()
{
    Board board;
    while (true)
    {
        board.draw();
        board.snakeMove();
        Sleep(frameDelay);
        board.setSnakeDir(getDir());
    }
}

int main()
{
    game();
}
