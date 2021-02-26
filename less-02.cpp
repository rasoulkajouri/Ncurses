#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv){

    // to initialize the window
    initscr();

    // to disbale the echo
    noecho();

    int height, width, start_y, start_x;
    height = 10;
    width = 40;
    start_y = start_x = 10;

    WINDOW * win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    //wmove(win, 1, 1);
    mvwprintw(win, 1, 1, "This is a new window!");
    wrefresh(win);


    start_y += height - 1;
    WINDOW * winII = newwin(height, width, start_y, start_x);
    refresh();

    box(winII, 0, 0);
    wrefresh(winII);

    // to display a sentence
    //mvprintw(y, x, "Hello World!\n");



    // to pasue the code
    getch();

    // to end the window
    endwin();
	return 0;
}
