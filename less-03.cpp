#include <ncurses.h>
using namespace std;
// **********************************************
constexpr unsigned short footer_h = 4;
constexpr unsigned short footer_start_x = 0;

unsigned int LEFT = '|', RIGHT='|', TOP = '+', BOTTOM = '-', TLC = '+', TRC= '+', BLC= '+', BRC= '+';
// **********************************************
unsigned short max_h, max_w;


WINDOW *FOOTER, *LEFT_HAND, *RIGHT_HAND;
// **********************************************
int main(int argc, char ** argv){
    initscr(); // to initialize the window
    noecho(); // to disbale the echo
	raw(); // to disbale the control buttons such Ctrl-C


	getmaxyx(stdscr, max_h, max_w);
	FOOTER = newwin(footer_h, max_w, max_h - footer_h, footer_start_x);
	LEFT_HAND  = newwin(max_h - footer_h, max_w / 2, 0, footer_start_x);
	RIGHT_HAND = newwin(max_h - footer_h, max_w / 2, 0, max_w / 2);

	do{
		erase();
		werase(FOOTER);
		werase(LEFT_HAND);
		werase(RIGHT_HAND);

		getmaxyx(stdscr, max_h, max_w);

		mvwin(FOOTER, max_h - footer_h, footer_start_x);
		wresize(FOOTER, footer_h, max_w);
		wborder(FOOTER, LEFT, RIGHT, TOP, BOTTOM, TLC, TRC, BLC, BRC);

		mvwin(LEFT_HAND, 0, 0);
		wresize(LEFT_HAND, max_h - footer_h, max_w / 2);
		box(LEFT_HAND, 0, 0);


		mvwin(RIGHT_HAND, 0, max_w / 2);
		wresize(RIGHT_HAND, max_h - footer_h, max_w / 2);
		box(RIGHT_HAND, 0, 0);

		mvwprintw(FOOTER, 1, 1, "Here is our footer!");
		refresh();
		wrefresh(FOOTER);
		wrefresh(LEFT_HAND);
		wrefresh(RIGHT_HAND);


	}while(getch() != (unsigned int)'q');

    // to end the window
    endwin();
	return 0;
}
