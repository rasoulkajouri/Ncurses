#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv){

	// to initialize the window
	initscr();

	// to disbale the echo
	noecho();


	// to display a sentence
	printw("Hello World!\n");

	// to pause the code
	char C = getch();

	printw("You entered: %c | %d", C, int(C));

	// to pasue the code
	getch();

	// to end the window
	endwin();
	return 0;
}
