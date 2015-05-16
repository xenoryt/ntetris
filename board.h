struct block
{
	int y;
	int x;
	int color;
};

//tetronimo
struct tetro
{
	int y, x;
	struct block blocks[4][4];
	int rotation;
};

void init_colors();
void init_tetros();
WINDOW * new_board();

static void print_block(WINDOW *, const struct block const *, int, int);
static void print_tetro(WINDOW *, const struct tetro const *);

void update_board(WINDOW *);
