#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <list>

using namespace std;

enum class Direction { up, down, left, right };

const int snakeSpeed = 5;
const int frameDelay = 1000 / snakeSpeed;

const int ARROW = 224;
const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;

struct Point
{
	int x;
	int y;
};

class Snake
{
private:
	Direction direction = Direction::right;
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
		system("cls");
	}
	void snakeMove()
	{
		snake.move();
		snake.draw();
	}
	void setSnakeDir(Direction dir)
	{
		snake.setDirection(dir);
	};
};

Direction getDir();
void draw(Point point, char symb = ' ');
