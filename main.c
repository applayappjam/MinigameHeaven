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

#include "connect_four_proto.h"
void connect_four(){
    while(res==-1){
        showInfo();
        choosePosit();

        check_count();
        check_first_cross();
        check_second_cross();
        check_width();
        check_height();
        
        cnt++;
    }
    return;
}

//show Board's condition
void printBoard(){
    for(int i=0;i<7;i++) printf("%d ", i);
    printf("\n\n");

    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++) printf("%d ", board[i][j]);
        printf("\n");
    }

    printf("\n");
}

//show info to player and input value
void showInfo(){
    printf("\n\nContent '0' means empty, '1' means player's stone, '2' means computer's stone.\n\n");
    printBoard();
    printf("Enter column's num: ");
    scanf("%d", &column);
    printf("\n");
    checkRightInput(column);
}


//check player's right input
void checkRightInput(int column){
    if(board[0][column]!=0 || column<0 || column>6){
        printf("It's a wrong input!\n\n");
        showInfo();
    }

    else{
        inputPlayer(column);
    }
}


//input player's position on board
void inputPlayer(int column){
    int i=5;
    while(board[i][column]!=0) i--;
    board[i][column] = 1;
}


//choose computer's position on board
void choosePosit(){
    int rand_row = rand() % 6, rand_col = rand() % 7;
    srand(time(NULL));
    while((rand_row!=5 && board[rand_row+1][rand_col]==0) || board[rand_row][rand_col]!=0){
        rand_row = rand() % 6, rand_col = rand() % 7;
    }
    inputComputer(rand_row, rand_col);
}


//input computer's position on board
void inputComputer(int _row, int _column){
    board[_row][_column] = 2;
}

//check number of stones on board
void check_count(){
    if(cnt==21){
        res = 0;
        showResult(res);
    }
}

//check whether completed 4 stones
void check_first_cross(){
    for(int l=0;l<4;l++){
        for(int k=0;k<3;k++){
            if(board[5-k][0+l] == board[4-k][1+l] && board[4-k][1+l] == board[3-k][2+l] && board[3-k][2+l] == board[2-k][3+l] && board[2-k][3+l] == ply){
                res=1;
                showResult(res);
            }

            else if(board[5-k][0+l] == board[4-k][1+l] && board[4-k][1+l] == board[3-k][2+l] && board[3-k][2+l] == board[2-k][3+l] && board[2-k][3+l] == cpt){
                res=2;
                showResult(res);
            }
        }
    } 
}

//check whether completed 4 stones
void check_second_cross(){
    for(int l=0;l<4;l++){
        for(int k=0;k<3;k++){
            if(board[5-k][6-l] == board[4-k][5-l] && board[4-k][5-l] == board[3-k][4-l] && board[3-k][4-l] == board[2-k][3-l] && board[2-k][3-l] == ply){
                res=1;
                showResult(res);
            }
            
            else if(board[5-k][6-l] == board[4-k][5-l] && board[4-k][5-l] == board[3-k][4-l] && board[3-k][4-l] == board[2-k][3-l] && board[2-k][3-l] == cpt){
                res=2;
                showResult(res);
            }
        }
    }
}

//check whether completed 4 stones
void check_width(){
    for(int j=5;j>=0;--j){
        for(int i=0;i<4;i++){
            if(board[j][0+i] == board[j][1+i] && board[j][1+i] == board[j][2+i] && board[j][2+i] == board[j][3+i] && board[j][3+i] == ply){
                res=1;
                showResult(res);
            } 

            else if(board[j][0+i] == board[j][1+i] && board[j][1+i] == board[j][2+i] && board[j][2+i] == board[j][3+i] && board[j][3+i] == cpt){
                res=2;
                showResult(res);
            }
        }
    }
}

//check whether completed 4 stones
void check_height(){
    for(int i=0;i<7;i++){
        for(int j=5;j>=3;--j){
            if(board[j][i] == board[j-1][i] && board[j-1][i] == board[j-2][i] && board[j-2][i] == board[j-3][i] && board[j-3][i] == ply){
                res=1;
                showResult(res);
            }

           else if(board[j][i] == board[j-1][i] && board[j-1][i] == board[j-2][i] && board[j-2][i] == board[j-3][i] && board[j-3][i] == cpt){
                res=2;
                showResult(res);
            }
        }
    }
}


//show winnner
void showResult(int result){
    switch(result){
        case 0:
            printf("Cannot determine winner.\n");
            printf("\n--------Result--------\n\n");
            printBoard();
            connect_four();
            break;

        case 1:
            printf("Winner is player, You win!\n");
            printf("\n--------Result--------\n\n");
            printBoard();
            connect_four();
            break;

        case 2:
            printf("Winner is computer, You lose!.\n");
            printf("\n--------Result--------\n\n");
            printBoard();
            connect_four();
            break;
    }
}

void num_baseball(); //jinnyfruit

void gomoku(); // Tuna

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
