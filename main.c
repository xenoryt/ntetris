#include <ncurses.h>
#include "board.h"

int main()
{
    initscr();
    init_colors();
    noecho();
    
    WINDOW * board = new_board();

    for(int i = 1; i <= 10; ++i)
    {
	mvwprintw(board, i, 1, "00112233445566778899");

	napms(1000);
	
	refresh();
	wrefresh(board);
    }
    
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
