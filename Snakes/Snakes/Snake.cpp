#include "snake_header.h"

void Snake::move()
{
    //������� ����� ����� newHead, ������� ���������� ������� ������ ����.
    Point newHead = body.front();
    switch (direction)
    {
    case Direction::up: newHead.y--; break;
    case Direction::down: newHead.y++; break;
    case Direction::left: newHead.x--; break;
    case Direction::right: newHead.x++; break;
    }
    //��������� ����� ������ � ������ ���� ����
    body.push_front(newHead);
    //��������� ���������� ������ (���������� ��������) � cutTail.
    cutTail = body.back();
    //������� ��������� ������� ���� (�����)
    body.pop_back();
}

void Snake::draw()
{
    // ������� �����
    ::draw(cutTail, ' ');

    // ������ ������
    ::draw(body.front(), '#');

    // ������ ����. ����� �������� ����������� �� ������ ������� ����
    auto it = next(body.begin());
    for (; it != body.end(); ++it)
    {
        ::draw(*it, '*');
    }
}