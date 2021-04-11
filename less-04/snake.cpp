#include "snake.hpp"
Board::Board(){
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	start_color();
	use_default_colors();

	init_pair(FRAME, COLOR_CYAN, -1);
	init_pair(SNAKE, COLOR_GREEN, -1);
	init_pair(FRUIT, COLOR_RED, -1);
	init_pair(POINT, COLOR_MAGENTA, -1);

	getmaxyx(stdscr, height, width);
	walls_char = "#";
	snake_char = "x";
	food_char = "*";
	points = 0;

	fruit.x = width / 4;
	fruit.y = height / 4;

	for(unsigned short I=0; I<3; I++)
		snake.push_back(snakeCell(height/2, width/2 + I));

	attron(A_BOLD);
	FrameCreator();
	SnakeCreator();
	FoodCreator();
	Points();
	attroff(A_BOLD);
}
Board::~Board(){

	nodelay(stdscr, false);
	keypad(stdscr, false);
	getch();
	endwin();
}
food::food(){
	this->y = 0;
	this->x = 0;
}
food::food(unsigned short y, unsigned short x){
	this->y = y;
	this->x = x;
}
snakeCell::snakeCell(){
	this->y = 0;
	this->x = 0;
}
snakeCell::snakeCell(unsigned short y, unsigned short x){
	this->y = y;
	this->x = x;
}
void Board::PutChar(const std::string &S, const unsigned short &Y, const unsigned short &X){
	mvprintw(Y, X, "%s", S.c_str());
}
void Board::FrameCreator(){
	attron(COLOR_PAIR(FRAME));
	for(unsigned short I=0; I<width; I++){
		PutChar(walls_char, 0, I);
		PutChar(walls_char, height - 2, I);
	}
	for(unsigned short I=0; I<height - 2; I++){
		PutChar(walls_char, I, 0);
		PutChar(walls_char, I, width - 1);
	}
	attroff(COLOR_PAIR(FRAME));
}
void Board::SnakeCreator(){
	attron(COLOR_PAIR(SNAKE));
	for(unsigned short I=0; I<snake.size(); I++)
		PutChar(snake_char, snake[I].y, snake[I].x);
	attroff(COLOR_PAIR(SNAKE));
}
void Board::FoodCreator(){
	attron(COLOR_PAIR(FRUIT));
	PutChar(food_char, fruit.y, fruit.x);
	attroff(COLOR_PAIR(FRUIT));
}
void Board::Points(){
	attron(COLOR_PAIR(POINT));
	mvprintw(height-1, 0, ">>> Scores: %u", points);
	attroff(COLOR_PAIR(POINT));
}

