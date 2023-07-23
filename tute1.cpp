#include <curses.h>
using namespace std;
int main (int argc, char** argv){

	initscr();

	//prints  a string
	printw("Hello Faraz!");

    refresh();

	int c  = getch();

	printw("%d" , c);

	//addch(c);
	getch();

	endwin();
	return 0;
}
