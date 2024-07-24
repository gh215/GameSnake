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
}

bool Board::checkBorderHit()
{
    Point head = snake.getHead();
    return (head.x <= ul.x || head.x >= lr.x || head.y <= ul.y || head.y >= lr.y);
}

void Board::boardMessage(string message)
{
    // Размеры рамки
    const int messageWidth = 14;
    const int messageHeight = 5;

    // Центр игрового поля
    int centerX = (ul.x + lr.x) / 2;
    int centerY = (ul.y + lr.y) / 2;

    // Начальные координаты для рамки сообщения
    int startX = centerX - messageWidth / 2;
    int startY = centerY - messageHeight / 2;

    for (int y = startY; y < startY + messageHeight; y++)
    {
        for (int x = startX; x < startX + messageWidth; x++)
        {
            drawSymb({ x, y }, ' ');
        }
    }

    // Рисуем рамку и сообщение
    for (int y = startY; y < startY + messageHeight; y++)
    {
        for (int x = startX; x < startX + messageWidth; x++)
        {
            if (y == startY || y == startY + messageHeight - 1)
            {
                drawSymb({ x, y }, '-');
            }
            else if (x == startX || x == startX + messageWidth - 1)
            {
                drawSymb({ x, y }, '|');
            }
        }
    }

    int messageX = startX + (messageWidth - message.length()) / 2;
    int messageY = startY + messageHeight / 2;
    for (size_t i = 0; i < message.size(); i++)
    {
        drawSymb({ messageX + static_cast<int>(i), messageY }, message[i]);
    }

    COORD endPosition = { 0, (SHORT)(lr.y + 1) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), endPosition);
}

void Board::showPauseMessage()
{
    string message = "PAUSE";
    boardMessage(message);
}

void Board::showGameOverMessage()
{
    string message = "GAME OVER";
    boardMessage(message);
}

void Board::clearPauseMessage()
{
    const int messageWidth = 14;
    const int messageHeight = 5;
    int centerX = (ul.x + lr.x) / 2;
    int centerY = (ul.y + lr.y) / 2;
    int startX = centerX - messageWidth / 2;
    int startY = centerY - messageHeight / 2;

    for (int y = startY; y < startY + messageHeight; y++)
    {
        for (int x = startX; x < startX + messageWidth; x++)
        {
            drawSymb({ x, y }, ' ');
        }
    }
}

void Board::checkPause()
{
    showPauseMessage();
    _getch();
    clearPauseMessage();
    drawBorders();
    draw();
}

void Board::processInput()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == PAUSE_LOWER || key == PAUSE_UPPER)
        {
            checkPause();
        }
        else if (key == ARROW)
        {
            key = _getch();
            setSnakeDir(getDir(key));
        }
    }
    flush();
}

