#include "snake_header.h"

void game()
{
    Board board;
    board.drawBorders();
    bool paused = false;
    while (!board.isGameOver())
    {
        board.processInput();
        board.draw();
        board.snakeMove();
        Sleep(frameDelay);
    }
    board.showGameOverMessage();
}

int main()
{
    game();
}

