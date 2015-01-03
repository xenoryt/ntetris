#include <ncurses.h>
#include "board.h"

const int ROWS = 20;
const int COLUMNS = 10 * 2; //each block is 2 wide

struct tetro tetrotypes[7];

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

void init_tetros() {
	//y, x
	int orientations[][4][4][2] = {
		/* [][]
		   [][]
		*/
		{
			{{0, 0}, {0, -1}, {-1, 0}, {-1, -1}},
			{{0, 0}, {0, -1}, {-1, 0}, {-1, -1}},
			{{0, 0}, {0, -1}, {-1, 0}, {-1, -1}},
			{{0, 0}, {0, -1}, {-1, 0}, {-1, -1}}
		},
		/* [][][][]    []
					   []
					   []
					   []
		*/
		{
			{{0, -2}, {0,-1}, {0, 0}, {0, 1}},
			{{-1, 0}, {0, 0}, {1, 0}, {2, 0}},
			{{0, -2}, {0,-1}, {0, 0}, {0, 1}},
			{{-1, 0}, {0, 0}, {1, 0}, {2, 0}}

		},

		/*    [][]    []
			[][]      [][]
						[]
		*/
		{
			{{0, 0}, {-1, -1}, {-1, 0}, {0, 1}},
			{{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
			{{0, 0}, {-1, -1}, {-1, 0}, {0, 1}},
			{{0, 0}, {1, 0}, {0, 1}, {-1, 1}}
		},
		
		/* [][]         []
			 [][]     [][]
					  []
		*/
		{
			{{0, -1}, {0, 0}, {1,0}, {1,1}}, 
			{{-1, 1}, {0, 1}, {0,0}, {1,0}},
			{{0, -1}, {0, 0}, {1,0}, {1,1}}, 
			{{-1, 1}, {0, 1}, {0,0}, {1,0}}
		},
		
		/*  [][][]    []            []     [][]
			[]        []        [][][]       []
					  [][]                   []
		*/      
		{
			{{0, 0}, {0, 1}, {0, -1}, {-1, -1}},
			{{0, 0}, {1, 0}, {-1, 0}, {-1, 1}},
			{{0, 0}, {0, -1}, {0, 1}, {1, 1}},
			{{0, 0}, {-1, 0}, {1, 0}, {1, -1}}
		},
		
		
		/* [][][]    [][]    []         []
			   []    []      [][][]     []
					 []               [][]
		*/
		{
			{{0, -1}, {0,0}, {0, 1}, {1, 1}},
			{{1, 0}, {0,0}, {-1,0},{-1, 1}},
			{{-1, -1}, {0, -1}, {0, 0}, {0,1}},
			{{-1, 1}, {0, 0}, {1, 0}, {-1, -1}}
		},
		
		/*  [][][]    []       []      []
			  []      [][]   [][][]  [][]
					  []               []
		*/
		{
			{{0, 0}, {0, -1}, {0, 1}, {-1, 0}},
			{{0, 0}, {1, 0}, {-1, 0}, {0, 1}},
			{{0, 0}, {0, -1}, {0, 1}, {1, 0}},
			{{0, 0}, {1, 0}, {-1, 0}, {0, -1}}
		}
	};

	int i,j,k;
	for(i=0;i<7;i++) {
		tetrotypes[i].rot = 0;
		for(j=0;j<4;j++){
			for(k=0;k<4;k++) {
				tetrotypes[i].blocks[j][k].y = orientations[i][j][k][0];
				tetrotypes[i].blocks[j][k].x = orientations[i][j][k][1];
			}
		}
	}
}

WINDOW * new_board()
{
	WINDOW * board = newwin(ROWS + 2, COLUMNS + 2, 2, 2); //+2 for borders
	box(board, 0, 0);

	return board;
}

void update_board(WINDOW * board)
{
    static int i = 0;
    struct block temp;
    temp.y = i;
    temp.x = i;
    temp.color = 2;

    i++;

    print_block(board, &temp);
}

static void print_block(WINDOW * board, const struct block const * block)
{
    wattron(board, COLOR_PAIR(block->color));
    mvwprintw(board, 1 + block->y, 1 + block->x * 2, "  ");
    wattroff(board, COLOR_PAIR(block->color));
}
