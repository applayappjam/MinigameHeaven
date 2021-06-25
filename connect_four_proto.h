//Content '0' means empty, '1' means player's stone, '2' means computer's stone.
int board[6][7]={0}; 

int row, column, res=-1, ply=1, cpt=2, cnt=0;

//funtion prototype
void printBoard();
void showInfo();
void choosePosit();
void checkRightInput(int);
void inputPlayer(int);
void inputComputer();
void check_count();
void check_first_cross();
void check_second_cross();
void check_width();
void check_height();
void showResult(int);