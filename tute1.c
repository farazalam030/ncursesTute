#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>

// using namespace std;
int main (int argc, char** argv){

	initscr();

	// refresh();

	char c  = getch();
	addch(c);
	getch();

	endwin();
	return 0;
}