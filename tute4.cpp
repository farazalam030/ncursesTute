#include <curses.h>
#include <fstream>
#include <string>
// using namespace std;
int main (int argc, char** argv){

  std::fstream iFile;
  iFile.open("inputEULA.txt", std::ios::in);
  //   start_ncurses(true, true);
  initscr(); // initialises screen sets up memory and clear screen

  if (!has_colors()) {
    printw("Terminal doennot support colors");
    getch();
    return -1;
  }

  start_color();
  /*
  A_NORMAL        Normal display (no highlight)
  A_STANDOUT      Best highlighting mode of the terminal.
  A_UNDERLINE     Underlining
  A_REVERSE       Reverse video
  A_BLINK         Blinking
  A_DIM           Half bright
  A_BOLD          Extra bright or bold
  A_PROTECT       Protected mode
  A_INVIS         Invisible or blank mode
  A_ALTCHARSET    Alternate character set
  A_CHARTEXT      Bit-mask to extract a character
  COLOR_PAIR(n)   Color-pair number n
  */

  init_pair(1, COLOR_CYAN, COLOR_WHITE);
  char choice;
  //   attron(COLOR_PAIR(1));
  if (iFile.is_open()) {
    std::string data;
    int count = 0;
    while (getline(iFile, data)) {

      mvprintw(count, 0, "%s", data.c_str());

      count++;

      if (count == 30) {
        mvprintw(31, 0, "Press any key to read ahead");
        getch();
        clear();
        count = 0;
      }
    }
    mvprintw(31, 0, "Do you Accept the License? Y/N");
    choice = getch();
    if (choice == 'Y' || choice == 'y') {
      clear();
      //   mvprintw(5, 5, "Installation Started ... ");
      //   getch();
      endwin();
      return 0;

    } else {
      clear();
      //   mvprintw(5, 5, "Installation Aborted ... ");
      //   getch();
      endwin();
      return -1;
    }
  }

  //
  //   attroff(COLOR_PAIR(1));

  /*
  COLOR_BLACK   0
  COLOR_RED     1
  COLOR_GREEN   2
  COLOR_YELLOW  3
  COLOR_BLUE    4
  COLOR_MAGENTA 5
  COLOR_CYAN    6
  COLOR_WHITE   7
  */
  iFile.close();
  // getch();
  endwin();

  return 0;
}
