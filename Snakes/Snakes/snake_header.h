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
const int LEFT = 75;
const int RIGHT = 77;
const int PAUSE_LOWER = 112;
const int PAUSE_UPPER = 80;
const int FOOD_LIFETIME = 50;

Direction getDir(int key);

struct Point
{
	int x;
	int y;
};

list<Point> createSnakeBody(Point head, Direction dir, int size);
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
		Point startHead = { 22, 15 };
		direction = Direction::east;
		body = createSnakeBody(startHead, direction, 10);
	}
	Point getHead()
	{
		return body.front();
	}
	Direction dir = Direction::east;
	Direction getDir(int key);
	void setDirection(Direction dir) { direction = dir; }
	void updateDirection(int key);
	void resetDirection() { direction = Direction::east; }
	void draw();
	bool checkBodyHit();
	void move();
	void grow();
	bool isOnSnake(Point p);
};

class Food
{
private:
	Point coord;
	char look;
	int lifetime;
public:
	Food(Point p, int lf = FOOD_LIFETIME, char l = '@') : coord(p), look(l), lifetime(lf) {}

	void spawnFood(Snake& snake, const Point& ul, const Point& lr);
	void updateFood();
	bool checkFoodCollision(Snake& snake);

	int tick() { return --lifetime; }

	Point getCoords() const { return coord; }

	void draw() { drawSymb(coord, look); }

	~Food() { drawSymb(coord, ' '); }
};

class Board
{
	Snake snake;
	const Point ul{ 0, 0 };
	const Point lr{ 50, 20 };
	void checkPause();
	int lives;
	int score;
	list<Food> food;
	int foodCounter;
public:
	Board() : lives(3), score(0), foodCounter(0) {}
	bool checkBorderHit();
	void drawBorders();
	void processInput();
	void boardMessage(string message, string subMessage = "");
	void showGameOverMessage();
	void showPauseMessage();
	void clearPauseMessage();
	void showLostLifeMessage();
	bool pauseGame(Board& board);
	void drawStats();
	void updateFood();
	bool checkFoodCollision();
	void spawnFood();
	void moveCursorToBottom()
	{
		COORD endPosition = { 0, (SHORT)(lr.y + 2) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), endPosition);
	}
	void draw()
	{
		snake.draw();
		for (auto& f : food) 
		{
			f.draw();
		}
		drawSymb(lr, ' ');
	}
	void snakeMove();
	void setSnakeDir(Direction dir)
	{
		snake.setDirection(dir);
	}
	void updateScore(int points)
	{
		score += points;
	}
	void loseLife()
	{
		if (lives > 0) lives--;
	}
	bool isGameOver()
	{
		return lives == 0;
	}
};

Point getRandomPoint(const Point& ul, const Point& lr);
void flush();
void checkPause(Board& board);