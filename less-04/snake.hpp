#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <string>

constexpr unsigned short FRAME = 0;
constexpr unsigned short SNAKE = 1;
constexpr unsigned short FRUIT = 2;
constexpr unsigned short POINT = 3;

#ifndef SNAKE_HPP
#define SNAKE_HPP

struct food{
	unsigned short y,x;
	food();
	food(unsigned short, unsigned short);
};
struct snakeCell{
	unsigned short y,x;
	snakeCell();
	snakeCell(unsigned short, unsigned short);
};
class Board{
	private:
		unsigned short height, width, points;
		std::string walls_char, food_char, snake_char;
		std::vector<snakeCell> snake;
		food fruit;

		void PutChar(const std::string&, const unsigned short&, const unsigned short&);
	public:
		Board();
		~Board();
		void FrameCreator();
		void SnakeCreator();
		void FoodCreator();
		void Points();

};
#endif // SNAKE_HPP
