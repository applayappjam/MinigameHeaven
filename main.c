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

int secreteNum;
int checkNum;
int Success_Key = 0;
void check(int, int);

//function definitions
void connect_four(); //asas6978

void num_baseball(){
    printf("★Welcome to number baseball game★\n\n");
    printf("-> You can predict a three-digit number a total of 9 times.\n");
    printf("-> if the number and digits match, S.\n");
    printf("-> if only the number matches and the number of digits is different, B.\n");
    printf("-> if none of the numbers match, OUT.\n");
    
    int count = 1;

    srand(time(NULL));
    secreteNum = (rand() % 999) + 100;    //Generate three-digit natural number to match
    printf("secrete Num: %d\n", secreteNum);

    while (count < 10) {

        printf("\nType a three-digit number (%d time):", count);
        scanf("%d", &checkNum);

        if (checkNum == secreteNum) {
            printf("\nSuccess!\n");
            Success_Key++;
            break;
        }

        else {
            check(secreteNum, checkNum);
        }

        count++;
    }

    if (Success_Key == 0) {
        printf("\nFAIL!\n");
    }
}

void check(int secreteNum, int checkNum){
 int temp;
    int i, j;

    int Strike = 0;
    int Ball = 0;
    int Out = 0;
    int compare_list[2][3];

    compare_list[0][0] = secreteNum / 100;
    secreteNum = secreteNum % 100;
    compare_list[0][1] = secreteNum / 10;
    compare_list[0][2] = secreteNum % 10;

    compare_list[1][0] = checkNum / 100;
    checkNum = checkNum % 100;
    compare_list[1][1] = checkNum / 10;
    compare_list[1][2] = checkNum % 10;



    for (i = 0; i < 3; i++) {

        temp = 0;

        for (j = 0; j < 3; j++) {

            if (compare_list[0][i] == compare_list[1][j]) {

                if (i == j) {

                    Strike++;

                    if (temp > 0) {
                        Ball = Ball - temp;
                    }

                    break;
                }
                else {

                    Ball++;

                    if (temp > 0) {
                        Ball = Ball - temp;
                    }
                    temp++;
                }
            }
            else
                Out++;
        }
    }

    printf("\n[result]\n");

    if (Strike == 0 && Ball == 0 && Out > 0)
        printf("OUT!\n");
    else {
        if (Strike > 0)
            printf("S:%d \n", Strike);
        if (Ball > 0)
            printf("B:%d \n", Ball);
    }
}

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
