#include <ncurses.h>
#include "board.h"

int main()
{
    initscr();
    init_colors();
    
    WINDOW * board = new_board();

    for(int i = 1; i <= 10; ++i)
    {
	mvwprintw(board, i, 1, "00112233445566778899");

	napms(1000);
	
	refresh();
	wrefresh(board);
    }
    
    getch();

    delwin(board);
    endwin();

    return 0;
}
