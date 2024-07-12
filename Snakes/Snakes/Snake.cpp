#include "snake_header.h"

void Snake::move()
{
    //Создаем новую точку newHead, копируя координаты текущей головы змеи.
    Point newHead = body.front();
    switch (direction)
    {
    case Direction::north: newHead.y--; break;
    case Direction::south: newHead.y++; break;
    case Direction::west: newHead.x--; break;
    case Direction::east: newHead.x++; break;
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
    ::drawSymb(cutTail, ' ');

    // Рисуем голову
    ::drawSymb(body.front(), '#');

    // Рисуем тело. Содаём итератор указывающий на второй элемент тела
    auto it = next(body.begin());
    for (; it != body.end(); ++it)
    {
        ::drawSymb(*it, '*');
    }
}