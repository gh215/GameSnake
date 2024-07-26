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
        board.checkFoodCollision();
        board.snakeMove();
        Sleep(frameDelay);
    }
    board.showGameOverMessage();
}

int main()
{
    game();
}

