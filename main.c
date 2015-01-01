#include <ncurses.h>

const int ROWS = 20;
const int COLUMNS = 10 * 2; //each block is 2 wide

struct block
{
    int y;
    int x;
    int colour;
};

void init_colors()
{
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
}

int main()
{
    initscr();
    start_color();
    init_colors();
    
    WINDOW * board = newwin(ROWS + 2, COLUMNS + 2, 5, 5); //+2 for borders
    box(board, 0, 0);
    mvwprintw(board, 1, 1, "00112233445566778899");
    
    refresh();
    wrefresh(board);
    getch();
    endwin();

    return 0;
}
