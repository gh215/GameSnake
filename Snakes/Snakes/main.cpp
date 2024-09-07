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
        board.snakeMove();       
        board.draw();        
        board.drawStats();
        board.checkFoodCollision();

        Sleep(frameDelay);
    }
    board.moveCursorToBottom();
    board.showGameOverMessage();
}

int main()
{
    game();
}

