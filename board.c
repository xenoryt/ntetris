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

void init_tetros()
{
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
			{{0, -1}, {0, 0}, {0, 1}, {1, 1}},
			{{1, 0}, {0, 0}, {-1, 0},{-1, 1}},
			{{-1, -1}, {0, -1}, {0, 0}, {0, 1}},
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

	for(int i = 0; i < 7; i++)
	{
		tetrotypes[i].rotation = 0;
		tetrotypes[i].y = 0;
		tetrotypes[i].x = 5;
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				tetrotypes[i].blocks[j][k].y = orientations[i][j][k][0];
				tetrotypes[i].blocks[j][k].x = orientations[i][j][k][1];
				tetrotypes[i].blocks[j][k].color = i + 1;
			}
		}
	}
}

WINDOW * new_board()
{
	WINDOW * board = newwin(ROWS + 2, COLUMNS + 2, 0, 0); //+2 for borders

	return board;
}

static void print_block(WINDOW * board, const struct block const * block, int y, int x)
{
	wattron(board, COLOR_PAIR(block->color));
	mvwprintw(board, 1 + y + block->y, 1 + (x + block->x) * 2, "  ");
	wattroff(board, COLOR_PAIR(block->color));
}

static void print_tetro(WINDOW * board, const struct tetro const * tetro)
{
	for(int i = 0; i < 4; ++i)
	{
		print_block(board, &tetro->blocks[tetro->rotation][i], tetro->y, tetro->x);
	}
}

void update_board(WINDOW * board)
{
	wclear(board);

	struct tetro temp = tetrotypes[4];
	static int i = 0;
	temp.y = i;
	temp.rotation = i % 4;
	print_tetro(board, &temp);
	i++;

	box(board, 0, 0);
}
