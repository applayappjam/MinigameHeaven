//headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gomoku.c"

//function prototypes
void connect_four(); //asas6978
void num_baseball(); //jinnyfruit
void gomoku(); // Tuna
void tic_tac_toe(); //jj0526
//ljlee

//function definitions
void connect_four(); //asas6978

void num_baseball(); //jinnyfruit


int table[19][19];

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);

void display_stone(int table[][20][20]);

int game_end(int table[][20][20]);

void draw_table(int c, int r);

void display_stone(int table[][20][20])
{
    int i, x, y;
    char *stone[2] = { "○", "●" };

        for (i = 0; i < 2; i++)
            for (x = 1; x < 20; x++)
                for (y = 1; y < 20; y++)
                {
                    if (table[i][x][y] == 1)
                    {
                            //gotoxy(x * 2 - 1, y);
                            printf("%s", stone[i]);
                    }

                }
}


void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
        switch (key)
        {
        case 72: //위쪽 방향키
            if (*y1 > 0)
               *y1 -=*y1; 

               break;

        case 75: //왼쪽 방향키
               if (*x1 > 0)
               *x1 -=*x1; 

               break;

        case 77://오른쪽 방향키
               if (*x1 < 20)
               *x1 +=*x1; 

               break;

        case 80: //아래쪽 방향키
               if (*y1 < 20)
               *y1 +=*y1; 

               break;

        default:

               return;
        }
}

void draw_table(int c, int r)
{

        int i, j;

        unsigned char a = 0xa6;
        unsigned char b[12];

        for (i = 1; i < 12; i++)
               b[i] = 0xa0 + i;

        printf("%c%c", a, b[3]);

        for (i = 0; i < c - 1; i++)
               printf("%c%c", a, b[8]);

        printf("%c%c\n", a, b[4]);

        for (i = 0; i < r - 1; i++)
        {
               printf("%c%c", a, b[7]);
               for (j = 0; j < c - 1; j++)
                       printf("%c%c", a, b[11]);

               printf("%c%c\n", a, b[9]);
        }

        printf("%c%c", a, b[6]);

        for (i = 0; i < c - 1; i++)
               printf("%c%c", a, b[10]);

        printf("%c%c\n", a, b[5]);

}

void gomoku()
{
    // int x = 1, y = 1;
    // int table[19][19] = { 0 };
    // char *stone[2]={"○","●"};   //포인터 처리하면 오류가 없어지네?

    // printf("start gomoku! \nPress any button to start game!");
    // getchar();
    // printf(table);
    
    int x = 1, y = 1, other = 0;
    int table[2][20][20] = { 0 };
    char key;
    char *stone[2] = { "○", "●" };

        
        while (1)
        {

           // gotoxy(x, y);
            draw_table(18, 18);
            
            printf("%s", stone[other]);

            display_stone(table);
           // gotoxy(1, 20);

            printf("방향키로 움직일 수 있으며 스페이스(와 엔터)를 입력하면 돌을 놓을 수 있습니다. \n");
            printf("q를 누르면 게임을 종료합니다. \n");
            //gotoxy(1, 21);

            printf("돌을 놓았으면 상대방 차례입니다. ");

            key = getchar();

        if (key == 'q')    
            break;

        else if (key == ' ')
        {
            table[other][(x + 1) / 2][y] = 1;
            other--;
        }
        else if (key >= 72)
            move_arrow_key(key, &x, &y, 37, 19);

        // if (game_end(table) == 1)
        // {
        //     printf("흑돌이 이겼습니다\n");
        //     break;

        // }
        // else if (game_end(table) == 2)
        // {
        //     printf("백돌이 이겼습니다\n");
        //     break;
        // }
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
            connect_four();
            break;
        case'2':
            num_baseball();
            break;
        case '3':
            gomoku();
            break;
        case '4':
            tic_tac_toe();
            break;
        default:
            printf("You typed a wrong number! Please try again!\n");
            break;
        }
    }
}
