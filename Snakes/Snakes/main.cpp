#include "snake_header.h"

void game()
{
    Board board;
    board.drawBorders();
    board.spawnFood();

    while (!board.isGameOver())
    {
        board.processInput();
        board.updateFood();
        board.draw();
        board.drawStats();
        board.checkFoodCollision();
        board.snakeMove();
        Sleep(frameDelay);
    }
    board.moveCursorToBottom();
    board.showGameOverMessage();
}

int main()
{
    game();
    system("pause >nul");
}

