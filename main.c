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
        update_board(board);

        refresh();
        wrefresh(board);

        napms(500);
    }

    endwin();

    return 0;
}
