#include "snake_header.h"

void Snake::move()
{
    //Создаем новую точку newHead, копируя координаты текущей головы змеи.
    Point newHead = body.front();
    switch (direction)
    {
    case Direction::up: newHead.y--; break;
    case Direction::down: newHead.y++; break;
    case Direction::left: newHead.x--; break;
    case Direction::right: newHead.x++; break;
    }
    //Добавляем новую голову в начало тела змеи
    body.push_front(newHead);
    //Сохраняем координаты хвоста (последнего элемента) в cutTail.
    cutTail = body.back();
    //Удаляем последний элемент тела (хвост)
    body.pop_back();
}

void Snake::draw()
{
    // Стираем хвост
    ::draw(cutTail, ' ');

    // Рисуем голову
    ::draw(body.front(), '#');

    // Рисуем тело. Содаём итератор указывающий на второй элемент тела
    auto it = next(body.begin());
    for (; it != body.end(); ++it)
    {
        ::draw(*it, '*');
    }
}