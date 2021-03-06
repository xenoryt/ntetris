#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "board.h"

int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s [level]\n", argv[0]);
		return 0;
	}	

	int level = atoi(argv[1]);
	if(level < 1 || level > 10)
	{
		printf("level must be 1-10\n");
		return 0;
	}
	
	initscr();
	init_colors();
	init_tetros();
	noecho();
	curs_set(0);
	timeout(0);

	WINDOW * board = new_board();

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
