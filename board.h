struct block
{
    int y;
    int x;
    int colour;
};

//tetronimo
struct tetro {
	int x,y;
	struct block blocks[4];
};

void init_colors();
void newBlock();
WINDOW * new_board();

static void printBlock(WINDOW*, struct block);
static void rotr(struct tetro*);
static void rotl(struct tetro*);
