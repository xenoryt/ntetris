struct block
{
    int y;
    int x;
    int colour;
};

void init_colors();
void newBlock();
WINDOW * new_board();

static void printBlock(WINDOW*, struct block);
