﻿#include "snake_header.h"

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

bool Snake::checkBodyHit()
{
    Point head = body.front();

    // Итератор, указывающий на второй элемент тела змеи
    auto it = next(body.begin());

    for (; it != body.end(); ++it)
    {
        // Если координаты головы совпадают с координатами любой части тела
        if (head.x == it->x && head.y == it->y)
        {
            return true;
        }
    }
    return false;
}

void Snake::grow()
{
    body.push_back(cutTail);
}

//Проверяет, находится ли данная точка на теле змеи
bool Snake::isOnSnake(Point p)  
{
    for (const auto& segment : body) 
    {
        //Если координаты точки совпадают с любым сегментом
        if (segment.x == p.x && segment.y == p.y) 
        {
            return true;
        }
    }
    return false;
}

void Snake::updateDirection(int key)
{
    if (key == LEFT || key == RIGHT)
    {
        switch (direction)
        {
        case Direction::north:
            direction = (key == LEFT) ? Direction::west : Direction::east;
            break;
        case Direction::south:
            direction = (key == LEFT) ? Direction::east : Direction::west;
            break;
        case Direction::west:
            direction = (key == LEFT) ? Direction::south : Direction::north;
            break;
        case Direction::east:
            direction = (key == LEFT) ? Direction::north : Direction::south;
            break;
        }
    }
}