#include <ncurses.h>
#include "board.h"

const int ROWS = 20;
const int COLUMNS = 10 * 2; //each block is 2 wide

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

static void printBlock(WINDOW* board, struct block block) {
}


static void rotr(struct tetro *tetro) {
	int i;
	for(i = 0; i < 4; i++){ 
		struct block *b = &tetro->blocks[i];
		b->x = b->x - tetro->x;
		b->y = b->y - tetro->y;
		int tmp = b->x;
		b->x = -b->y;
		b->y = tmp;
		b->x += tetro->x;
		b->y += tetro->y;
	}
}
static void rotl(struct tetro *tetro) {
}

