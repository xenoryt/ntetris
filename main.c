#include <ncurses.h>
#include "board.h"

int main()
{
    initscr();
    init_colors();
    
    WINDOW * board = new_board();
    mvwprintw(board, 1, 1, "00112233445566778899");
    
    refresh();
    wrefresh(board);
    getch();
    endwin();

    return 0;
}
