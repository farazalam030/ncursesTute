#include <curses.h>
using namespace std;
int main (int argc, char** argv){

	initscr(); // sets up memory and clear screen

	int x,y;
	x=y=10;

	move(y,x); // moves the curser to speciied location

	//prints  a string to a window
	printw("Hello Faraz!");

    // refresh();
	int c  = getch(); // whats for user input , returns int value

	// move(0,0);

	// printw("%d" , c);

	mvprintw(0,0,"%d" , c);

	refresh();

	//clear the screan

	clear();


	//addch(c);
	getch();

	endwin();
	return 0;
}
