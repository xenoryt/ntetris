#include <ncurses.h>
#include "board.h"

//to sleep use napms

int main()
{
	initscr();
	init_colors();
	init_tetros();
	noecho();
	curs_set(0);
	timeout(0);

	WINDOW * board = new_board();

	int level = 1; //1 to 10
	int done = 0;
	int ticks = 0; //number of iterations since last board update

	while (!done)
	{
		int ch;
		switch(ch = getch())
		{
		case 'q':
			done = 1;
			continue;
		case KEY_LEFT:
			continue;
		case KEY_RIGHT:
			continue;
		case KEY_UP:
			continue;
		case KEY_DOWN:
			continue;
		case ERR:
			break;
		default:
			continue;
		}
		if(ticks >= (10 - level))
		{
			update_board(board);

			wrefresh(board);
			refresh();

			ticks = 0;
		}
		ticks++;

		napms(50); //update every 0.05 seconds
	}

	endwin();

	return 0;
}
