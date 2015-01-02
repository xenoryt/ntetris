#include <ncurses.h>
#include "board.h"

const int ROWS = 20;
const int COLUMNS = 10 * 2; //each block is 2 wide

static void print_block(WINDOW *, const struct block const *);

void init_colors()
{
    start_color();

    //tetronimo colours
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
}

WINDOW * new_board()
{
    WINDOW * board = newwin(ROWS + 2, COLUMNS + 2, 2, 2); //+2 for borders
    box(board, 0, 0);

    return board;
}

void update_board(WINDOW * board)
{
    static int i = 1;
    struct block temp;
    temp.y = i;
    temp.x = i;
    temp.color = 2;

    i++;

    print_block(board, &temp);
}

static void print_block(WINDOW * board, const struct block const * block)
{
    attron(COLOR_PAIR(block->color));
    mvwprintw(board, block->y, 1 + block->x * 2, "te");
    attroff(COLOR_PAIR(block->color));
}
