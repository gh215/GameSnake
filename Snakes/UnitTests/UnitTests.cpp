#include "pch.h"
#include "CppUnitTest.h"
#include "..\Snakes\snake_header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
        TEST_METHOD(TestCreateSnakeBody_ValidArguments)
        {
            Point head = { 5, 5 };
            int size = 3;

            list<Point> bodyEast = createSnakeBody(head, Direction::east, size);
            Assert::AreEqual(bodyEast.back().x, 3);
            Assert::AreEqual(bodyEast.back().y, 5);

            list<Point> bodyWest = createSnakeBody(head, Direction::west, size);
            Assert::AreEqual(bodyWest.back().x, 7);
            Assert::AreEqual(bodyWest.back().y, 5);

            list<Point> bodyNorth = createSnakeBody(head, Direction::north, size);
            Assert::AreEqual(bodyNorth.back().x, 5);
            Assert::AreEqual(bodyNorth.back().y, 7);

            list<Point> bodySouth = createSnakeBody(head, Direction::south, size);
            Assert::AreEqual(bodySouth.back().x, 5);
            Assert::AreEqual(bodySouth.back().y, 3);

        }

        TEST_METHOD(TestCreateSnakeBody_InvalidArguments)
        {
            Point head = { 5, 5 };
            Direction dir = Direction::east;
            int size = -1;  
            try
            {
                createSnakeBody(head, dir, size);
            }
            catch (invalid_argument)
            {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(TestGetHead)
        {
            Snake snake;
            Point head = snake.getHead();
            Assert::AreEqual(head.x, 22);
            Assert::AreEqual(head.y, 15);
        }

        TEST_METHOD(TestSetDirection)
        {
            Snake snake;
            snake.setDirection(Direction::north);
            snake.move();
            Point head = snake.getHead();
            Assert::AreEqual(head.y, 14);
        }

        TEST_METHOD(TestCheckBodyHit)
        {
            Snake snake;
            snake.move();
            snake.setDirection(Direction::north);
            snake.move();
            snake.setDirection(Direction::west);
            snake.move();
            snake.setDirection(Direction::south);
            snake.move();
            Assert::IsTrue(snake.checkBodyHit());
        }

        TEST_METHOD(TestMove)
        {
            Snake snake;
            snake.move();
            Point head = snake.getHead();
            Assert::AreEqual(head.x, 23);
        }

        TEST_METHOD(TestIsOnSnake)
        {
            Snake snake;
            Point head = snake.getHead();
            Assert::IsTrue(snake.isOnSnake(head));
        }

        TEST_METHOD(TestFoodTick)
        {
            Food food({ 0, 0 }, 50);

            Assert::AreEqual(49, food.tick());
            for (int i = 0; i < 48; i++) food.tick();
            Assert::AreEqual(1, food.tick());
            Assert::AreEqual(0, food.tick());
        }

        TEST_METHOD(TestCheckBorderHit)
        {
            Board board;

            board.setSnakeDir(Direction::east);
            for (int i = 0; i < 25; i++) board.snakeMove();
            Assert::IsFalse(board.checkBorderHit());

            // Двигаем змею к правой границе
            for (int i = 0; i < 25; i++) board.snakeMove();
            Assert::IsTrue(board.checkBorderHit());
        }


	};
}
