struct block
{
    int y;
    int x;
    int color;
};

//tetronimo
struct tetro {
	int x,y;
	struct block blocks[4];
};

void init_colors();
WINDOW * new_board();

static void print_block(WINDOW *, const struct block const *);
static void rotr(struct tetro*);
static void rotl(struct tetro*);

void update_board(WINDOW *);
