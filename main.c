#include <ncurses.h>
#include "board.h"

int main()
{
    initscr();
    init_colors();
	noecho();
    
    WINDOW * board = new_board();
    mvwprintw(board, 1, 1, "00112233445566778899");
    
    refresh();
    wrefresh(board);
	int ch;
    while ((ch = getch()) != 'q') {
		switch(ch) {
			case KEY_LEFT:
				break;
			case KEY_RIGHT:
				break;
			case KEY_UP:
				break;
			case KEY_DOWN:
				break;
		}
	}
    endwin();

    return 0;
}
