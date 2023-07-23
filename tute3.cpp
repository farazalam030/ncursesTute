#include <curses.h>
using namespace std;
int main (int argc, char** argv){

	initscr(); //initialises screen sets up memory and clear screen
	cbreak();
	// raw();
	noecho();

	int height; int width; int start_y; int start_x;

	height=10;
	width=20;
	start_y = start_x=10;

	WINDOW *win = newwin(  height,   width,   start_y,   start_x);
	refresh();
	// box(win,124,45);
	char c = '|';
	int left,right,top,bottom,tlc,trc,blc,brc;
	left=right = (int)c;
	c='-';
	top = bottom =(int)c;
	c='+';
	tlc=trc=blc=brc=(int)c;
	wborder(win,left,right,top,bottom,tlc,trc,blc,brc);
	mvwprintw(win,1,1,"This is my box");
	wrefresh(win);
	int d  = getch(); // whats for user input , returns int value
	getch();
	endwin();
	return 0;
}
