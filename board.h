struct block
{
    int y;
    int x;
    int color;
};

void init_colors();
WINDOW * new_board();
void update_board(WINDOW *);
