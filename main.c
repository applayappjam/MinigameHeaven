//headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function prototypes
void connect_four(); //asas6978
void num_baseball(); //jinnyfruit
void gomoku(); // Tuna
void tic_tac_toe(); //jj0526
//ljlee

//function definitions
void connect_four(); //asas6978

void num_baseball(); //jinnyfruit




void move_cursor(char c, int r);
int game_end();
void draw_table();
void set_stone(int order, int c, int r);

char stone[2] = { 'O', 'X' };
int table[19][19] = { 0 };
int col_num = 10, row_num = 10;
char col = 'a';
int row = 0;

void set_stone(int order, int c, int r){
    table[r][c] = order+1;
}

void draw_table()
{

    int r = 18, c = 18;
    int i, j;

    printf("   A B C D E F G H I J K L M N O P Q R S\n");

        unsigned char a = 0xa6;
        unsigned char b[12];

        for (i = 1; i < 12; i++)
            b[i] = 0xa0 + i;

        if(table[0][0] == 0)
            printf("0  %c%c ", a, b[3]);
        else
            printf("0  %c", stone[table[0][0]-1]);

        for (i = 1; i < c; i++)
            if(table[0][i] == 0)
                printf("%c%c ",a, b[8]);
            else
                printf("%c ", stone[table[0][i]-1]);

        if(table[0][18] == 0)
            printf("%c%c \n", a, b[4]);
        else
            printf("%c ", stone[table[0][18]-1]);

        
        for (i = 1; i < r; i++)
        {
            if(i>9)
                if(table[i][0] == 0)
                    printf("%d %c%c ", i, a, b[7]);
                else
                    printf("%d %c ", i, stone[table[i][0]-1]);
            else
                if(table[i][0] == 0)
                    printf("%d  %c%c ", i, a, b[7]);
                else
                    printf("%d  %c ", i, stone[table[i][0]-1]);

            for (j = 1; j < c; j++)
                if(table[i][j] == 0)
                    printf("%c%c ",a, b[11]);
                else
                    printf("%c ", stone[table[i][j]-1]);

            if(table[i][18] == 0)
                printf("%c%c \n", a, b[9]);
            else
                printf("%c \n",stone[table[i][18]-1]);
        }

        if(table[18][0] == 0)
            printf("18 %c%c ", a, b[6]);
        else
            printf("18 %c ",stone[table[18][0]-1]);

        for (i = 1; i < c; i++)
            if(table[18][i] == 0)
                printf("%c%c ", a, b[10]);
            else
                printf("%c ",stone[table[18][i]-1]);

        if(table[18][18] == 0)
            printf("%c%c\n", a, b[5]);
        else
            printf("%c ",stone[table[18][18]-1]);
}


int game_end()  
{
    int count = 0;

    for(int o = 1; o < 3; o++){
        for(int i = 0; i < 19; i++) // vertical 5 counter
        {
            count = 0;
            for(int j = 0; j < 19; j++){
                if(table[j][i] == o)
                    count++;
                else
                    count = 0;

                if(count == 5)
                    return o;
            }
        }
    }

    for(int o = 1; o < 3; o++){
        for(int i = 0; i< 19; i++) // horizontal 5 counter
        {
            count = 0;
            for(int j = 0; j< 19; j++){
                if(table[i][j] == o)
                    count++;
                else
                    count = 0;

                if(count == 5)
                    return o;
            }
        }
    }

    for(int o = 1; o < 3; o++){
        for(int j = 0; j < 14; j++){
            for(int i = 0; i + j < 19; i++) // right cross 5 counter
            {
                count = 0;
                
                if(table[i + j][i] == o)
                    count++;
                else
                    count = 0;

                if(count == 5)
                    return o;
                
            }

            for(int i = 1; i + j < 19; i++) // right cross 5 counter
            {
                count = 0;
                
                if(table[i][i + j] == o)
                    count++;
                else
                    count = 0;

                if(count == 5)
                    return o;
                
            }
        }
        
    }

    for(int o = 1; o > 3; o++){
        for(int j = 0; j < 14; j++){
            for(int i = 0; i + j < 19; i++) // left cross 5 counter
            {
                count = 0;
                
                if(table[i + j][18 - i] == o)
                    count++;
                else
                    count = 0;

                if(count == 5)
                    return o;
                
            }

            for(int i = 1; i + j < 19; i++) 
            {
                count = 0;
                
                if(table[i][i + j] == o)
                    count++;
                else
                    count = 0;

                if(count == 5)
                    return o;
                
            }
        }

    }
}



void gomoku()
{
    int order=0;

    printf("start gomoku! \nType any text to start game!\n");
    printf("Type Q then quit\n");
    scanf(" %c", &col); 

    while (1)
    {
        draw_table();

        printf("Type location to place stones ex)A3\n");
        printf("O stone is first\n");

        scanf(" %c", &col);

        if(col == 'q') 
            break;

        scanf("%d", &row);

        if(col == ' ' || row == ' ' || col < 'A' || col > 'S' || row < 0 || row > 19)
        {    
        printf("Your input is incorrect.\n");
        }
        else if(table[row][col - 'A'] != 0){
            printf("Your input is duplicated.\n");
        }
        else
        {
            set_stone(order, col - 'A', row);

            if (order == 1)
                order--;
            else    
                order++;
        }

        if (game_end() == 1)
        {
            printf("O stone, Win!\n");
            break;
        }
        else if (game_end() == 2)
        {
            printf("X stone, Win!\n");
            break;
        }
        
    } 



} // Tuna

void tic_tac_toe(); //jj0526

//main
int main()
{
    const char game_names[4][20] = {"connect four", "number baseball", "gomoku", "tic-tac-toe"}; //in case, let it as a const array, not hard-coded string.
    const int game_count = 4;
    char sys = '2'; //for use of system("clear")
    do //check if user uses windwos or Unix.
    {
        printf("Choose if you are using Windows or Unix! Unix includes macOS and Linux.\n");
        printf("1. Windows, 2. Unix. your system : ");
        scanf(" %c", &sys);
    } while(sys != '1' && sys != '2');
    while(1)
    {
        //welcome page.
        printf("Welcome to Minigame Heaven!\n");
        printf("We have currently %d games.\n", game_count);
        for(int i = 0; i < game_count; ++i)
            printf("%d. %s\n", i + 1, game_names[i]); //print games.
        printf("Type the number of each game or 0 if you want to exit.\n");
        printf("your choice : ");
        char choice = '0';
        scanf(" %c", &choice); //get a game. ignore white spaces.
        if (sys == '1') //windows
            system("cls"); //clear screen
        else //Unix
            system("clear"); //clear screen
        switch(choice)
        {
        case '0':
            printf("Thanks for playing! Hope to see you soon!\n");
            return 0;
        case '1':
           // connect_four();
            break;
        case'2':
            //num_baseball();
            break;
        case '3':
            gomoku();
            break;
        case '4':
            //tic_tac_toe();
            break;
        default:
            printf("You typed a wrong number! Please try again!\n");
            break;
        }
    }
}
