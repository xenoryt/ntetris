#include <ncurses.h>
#include "board.h"

//to sleep use napms

int main()
{
    initscr();
    init_colors();
	noecho();
	curs_set(0);
	timeout(0);
    
    WINDOW * board = new_board();
    //mvwprintw(board, 1, 1, "00112233445566778899");

	int ch;
	int done = 0;
	while (!done) {
		switch(ch = getch())
		{
			case 'q':
				done = 1;
				break;
			case KEY_LEFT:
				break;
			case KEY_RIGHT:
				break;
			case KEY_UP:
				break;
			case KEY_DOWN:
				break;
			default:
				break;
		}
		update_board(board);

		refresh();
		wrefresh(board);

		napms(500);
	}

	endwin();

    return 0;
}
