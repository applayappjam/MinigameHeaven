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

void gomoku(); // Tuna

void tic_tac_toe() //jj052
{
    srand(time(NULL));
    char index[9]; // 'O', 'X' or ' '
    for (int i = 0; i<9; i++){
        index[i] = ' ';
    }
    int start;
    int my_turn[5];
    int the_opponent[5];
    char a = 'O';
    char O = 'O';//my turn
    char X = 'X';// the opponet's
    int m = 0;// my turn
    int n = 0; // my turn
    int size = 9; // size of the board
    int win; // who's winning
    int num;
    printf("1 is for starting first, 2 is for starting second\n");
    scanf("%d", &start);
    if (start == 1 ){
        printf("you're starting first! input a number 1-9 \n\n");
        scanf("%d", &my_turn[m]);
        index[my_turn[m]-1] = 'O';
        printf("┌────┬────┬────┐\n");
        printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
        printf("├────┼────┼────┤\n");
        printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
        printf("├────┼────┼────┤\n");
        printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
        printf("└────┴────┴────┘\n");
        m++;
        while(1){
            usleep(1000000);
            while(1){
                the_opponent[n] = rand()%9;
                if (index[the_opponent[n]]==' '){
                    break;
                }
            }
            index[the_opponent[n]] = 'X';
            printf("The opponent : %d\n", the_opponent[n]+1);
            printf("┌────┬────┬────┐\n");
            printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
            printf("├────┼────┼────┤\n");
            printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
            printf("├────┼────┼────┤\n");
            printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
            printf("└────┴────┴────┘\n");
            win = check(index, size);
            if (win == 1){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("★★★★ You win! ★★★★\n");
                return 0;
            }
            if (win == 2){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("You lose Try again!\n");
                return 0;
            }
            if (win == 3){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("It's a tie! Try again\n");
                return 0;
            }
            n++;
            printf("\nIt's your turn!\n");
            while(1){
                scanf("%d", &my_turn[m]);
                if (checking_duplicated(index, size, my_turn[m]-1) == 1){// the index doesn't exist
                    break;
                }
                printf("input the number again\n");
            }            
            index[my_turn[m]-1] = 'O';
            win = check(index, size);
            if (win == 1){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("★★★★ You win! ★★★★\n");
                return 0;
            }
            if (win == 2){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("You lost! Try again!\n");
                return 0;
            }
            if (win == 3){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("It's a tie! Try again\n");
                return 0;
            }
        }
    }
    else if (start == 2){
        printf("you're starting second!\n");
         while(1){
            usleep(1000000);
            while(1){
                the_opponent[n] = rand()%9;
                if (index[the_opponent[n]]==' '){
                    break;
                }
            }
            index[the_opponent[n]] = 'X';
            printf("The opponent : %d\n", the_opponent[n]+1);
            printf("┌────┬────┬────┐\n");
            printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
            printf("├────┼────┼────┤\n");
            printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
            printf("├────┼────┼────┤\n");
            printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
            printf("└────┴────┴────┘\n");
            win = check(index, size);
            if (win == 1){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("★★★★ You win! ★★★★\n");
                return 0;
            }
            if (win == 2){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("You lose Try again!\n");
                return 0;
            }
            if (win == 3){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("It's a tie! Try again\n");
                return 0;
            }
            n++;
            printf("\nIt's your turn!\n");
            while(1){
                scanf("%d", &my_turn[m]);
                if (checking_duplicated(index, size, my_turn[m]-1) == 1){// the index doesn't exist
                    break;
                }
                printf("input the number again\n");
            }            
            index[my_turn[m]-1] = 'O';
            win = check(index, size);
            if (win == 1){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("★★★★ You win! ★★★★\n");
                return 0;
            }
            if (win == 2){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("You lost! Try again!\n");
                return 0;
            }
            if (win == 3){
                printf("┌────┬────┬────┐\n");
                printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
                printf("├────┼────┼────┤\n");
                printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
                printf("└────┴────┴────┘\n");
                printf("It's a tie! Try again\n");
                return 0;
            }
        }
    }
}
int check(char index[], int size){
    if(((index[0] == 'O')&&(index[0]==index[1])&&(index[1]==index[2]))
    ||((index[3] == 'O')&&(index[3]==index[4])&&(index[4]==index[5]))
    ||((index[6] == 'O')&&(index[6]==index[7])&&(index[7]==index[8]))//garo
    ||((index[0] == 'O')&&(index[0]==index[3])&&(index[3]==index[6]))
    ||((index[1] == 'O')&&(index[1]==index[4])&&(index[4]==index[7]))
    ||((index[2] == 'O')&&(index[2]==index[5])&&(index[5]==index[8]))//sero
    ||((index[0] == 'O')&&(index[0]==index[4])&&(index[4]==index[8]))
    ||((index[2] == 'O')&&(index[2]==index[4])&&(index[4]==index[6]))){//daegakseon
        return 1;
    }
    if(((index[0] == 'X')&&(index[0]==index[1])&&(index[1]==index[2]))
    ||((index[3] == 'X')&&(index[3]==index[4])&&(index[4]==index[5]))
    ||((index[6] == 'X')&&(index[6]==index[7])&&(index[7]==index[8]))
    ||((index[0] == 'X')&&(index[0]==index[3])&&(index[3]==index[6]))
    ||((index[1] == 'X')&&(index[1]==index[4])&&(index[4]==index[7]))
    ||((index[2] == 'X')&&(index[2]==index[5])&&(index[5]==index[8]))
    ||((index[0] == 'X')&&(index[0]==index[4])&&(index[4]==index[8]))
    ||((index[2] == 'X')&&(index[2]==index[4])&&(index[4]==index[6]))){
        return 2;
    }
    int count;
    for (int i = 0; i<9; i++){
        if (index[i]!=' '){
            count++;
        }
    }
    if (count == 9){
        return 3; // no one won yet
    }
    return 0;
}
int checking_duplicated(char index[], int size, int num){
    //num == my_turn[m]
    if (index[num]==' '){
        return 1;
    }
    return 0;
}
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
