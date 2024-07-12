#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <list>

using namespace std;

enum class Direction { north, south, west, east };

const int snakeSpeed = 5;
const int frameDelay = 1000 / snakeSpeed;

const int ARROW = 224;
const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;

Direction getDir();

struct Point
{
	int x;
	int y;
};

void drawSymb(Point point, char symb = ' ');

class Snake
{
private:
	Direction direction = Direction::east;
	list<Point> body;
	Point cutTail;
public:
	Snake() : cutTail{ 0, 0 }
	{
		body.push_back({ 22, 15 });
		body.push_back({ 23, 15 });
		body.push_back({ 24, 15 });
		body.push_back({ 25, 15 });
		body.push_back({ 26, 15 });
	}
	void setDirection(Direction dir) { direction = dir; };
	void draw();
	bool checkBodyHit();
	void move();
};

class Board
{
	Snake snake;
	const Point ul{ 0, 0 };
	const Point lr{ 50, 30 };
public:
	bool checkBorderHit();
	void draw()
	{
		snake.draw();
		drawSymb(lr, ' ');
	}
	void snakeMove()
	{
		snake.move();
	}
	void setSnakeDir(Direction dir)
	{
		snake.setDirection(dir);
	};
};


