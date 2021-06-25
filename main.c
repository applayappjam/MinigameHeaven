//headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function prototypes
void connect_four(); //asas6978
void num_baseball(); //jinnyfruit
void gomoku(); // Tuna
int tic_tac_toe(); //jj0526
//ljlee

int secretNum;
int checkNum;
int Success_Key = 0;
void check(int, int);

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

void num_baseball(){
      printf("★Welcome to number baseball game★\n\n");
    printf("-> You can predict a three-digit number a total of 9 times.\n");
    printf("-> if the number and digits match, S.\n");
    printf("-> if only the number matches and the number of digits is different, B.\n");
    printf("-> if none of the numbers match, OUT.\n");

    int count = 1;
    int first;
    int second;
    int third;
    int value;

    srand(time(NULL));
    secretNum = (rand() % 899)+ 100;    //Generate three-digit natural number to match
    value = secretNum;

    first = value / 100;
    value = value % 100;
    second = value / 10;
    third = value % 10;

    while (first == second || second == third || first == third) {
        secretNum = (rand() % 999) + 100;    

        value = secretNum;

        first = value / 100;
        value = value % 100;
        second = value / 10;
        third = value % 10;
    }

    while (count < 10) {

        printf("\nType a three-digit number (%d time):", count);
        scanf("%d", &checkNum);

        if (checkNum == secretNum) {
            printf("\nSuccess!\n");
            Success_Key++;
            break;
        }

        else {
            check(secretNum, checkNum);
        }

        count++;
    }

    if (Success_Key == 0) {
        printf("\nFAIL!\n");
        printf("answer:%d\n", secretNum);
    }
}

void check(int secretNum, int checkNum){
 int temp;
    int i, j;

    int Strike = 0;
    int Ball = 0;
    int Out = 0;
    int compare_list[2][3];

    compare_list[0][0] = secretNum / 100;
    secretNum = secretNum % 100;
    compare_list[0][1] = secretNum / 10;
    compare_list[0][2] = secretNum % 10;

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

int checking_the_winner(char index[], int size);
void score(int count);
int checking_duplicated(char index[], int size, int num);
void show_tic_tac_toe_board(char index[9]);
int tic_tac_toe() //jj052
{
    //initialisation
    srand(time(NULL));
    char index[9]; // 'O', 'X' or ' '
    for (int i = 0; i<9; i++){
        index[i] = ' ';
    }
    //variables
    int start;
    int my_turn[5];
    int the_opponent[5];
    char a = 'O';
    char O = 'O';//my turn
    char X = 'X';// the opponet's
    int m = 0;// my turn
    int n = 0; // my turn
    int size = 9; // size of the board
    int win = 0; // who's winning
    int num;

    show_tic_tac_toe_board(index);
    printf("1 is for starting first, 2 is for starting second\n");
    scanf("%d", &start);
    if (start == 1 ){
        printf("you're starting first! input a number 1-9 \n\n");
        scanf("%d", &my_turn[m]);
        index[my_turn[m]-1] = 'O';
        show_tic_tac_toe_board(index);
        m++;
    }
    else {
        printf("you're starting second!\n");
    }
     while(1){
        while(1){
            the_opponent[n] = rand()%9;
            if (index[the_opponent[n]]==' '){
                break;
            }
        }
        index[the_opponent[n]] = 'X';
        printf("The opponent : %d\n", the_opponent[n]+1);
        show_tic_tac_toe_board(index);
        win = checking_the_winner(index, size);
        if (win != 0){
            show_tic_tac_toe_board(index);
            switch(win)
            {
            case 1:
                printf("★★★★ You win! ★★★★\n");
                break;
            case 2:
                printf("You lose Try again!\n");
                break;
            case 3:
                printf("It's a tie! Try again\n");
                break;
            }
            break;
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
        win = checking_the_winner(index, size);
        if (win != 0){
            show_tic_tac_toe_board(index);
            switch(win)
            {
            case 1:
                printf("★★★★ You win! ★★★★\n");
                break;
            case 2:
                printf("You lose Try again!\n");
                break;
            case 3:
                printf("It's a tie! Try again\n");
                break;
            }
            break;
        }
    }
    return 0;
}
void show_tic_tac_toe_board(char index[9]){
    printf("┌────┬────┬────┐\n");
    printf("│ ¹%c │ ²%c │ ³%c │\n",index[0],index[1],index[2]);
    printf("├────┼────┼────┤\n");
    printf("│ ⁴%c │ ⁵%c │ ⁶%c │\n",index[3],index[4],index[5]);
    printf("├────┼────┼────┤\n");
    printf("│ ⁷%c │ ⁸%c │ ⁹%c │\n",index[6],index[7],index[8]);
    printf("└────┴────┴────┘\n");
}

int checking_the_winner(char index[], int size){
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

int hangman(){
    srand(time(NULL));
    int select;
    int len_animal = 142;
    int len_fruit = 40;
    int len_nation = 162;
    char problems[3][300][20] = {{"elephant", "chicken", "Aardvark", "Alligator", "Alpaca", "Anaconda", "Ant", "Antelope","Ape","Aphid",
    "Armadillo","Asp","Baboon","Badger","Eagle","Barracuda","Bass","Basset Hound","Bat","Bear","Beaver","Bedbug","Bee","Beetle",
    "Bird","Bison","Whale","Bobcat","Buffalo","Butterfly","Buzzard","Camel","Caribou","Carp","Cat","Caterpillar","Catfish","Cheetah","Chicken",
    "Chimpanzee","Chipmunk","Cobra","Cod","Condor","Cougar","Cow","Coyote","Crab","Crane","Cricket","Crocodile","Crow","Cuckoo","Deer","Dinosaur",
    "Dog","Dolphin","Donkey","Dove","Dragonfly","Duck","Eagle","Eel","Elephant","Emu","Falcon","Ferret","Finch","Fish","Flamingo",
    "Flea","Fly","Fox","Frog","Goat","Goose","Gopher","Gorilla","Grasshopper","Hamster","Hare","Hawk","Hippopotamus","Horse",
    "Hummingbird","Humpback Whale","Husky","Iguana","Impala","Kangaroo","Ladybug","Leopard","Lion","Lizard","Llama","Lobster","Mongoose",
    "Monkey","Moose","Mosquito","Moth","Mountain goat","Mouse","Mule","Octopus","Orca","Ostrich","Otter","Owl","Ox","Oyster","Panda",
    "Parrot","Peacock","Pelican","Penguin","Perch","Pheasant","Pig","Pigeon","Polar bear","Porcupine","Quail","Rabbit","Raccoon",
    "Rat","Rattlesnake","Raven","Rooster","Sheep","Shrew","Skunk","Snail","Snake","Spider","Tiger","Walrus","Whale","Wolf","Zebra", "Giraffe",
    "Mole"},
    {"Apple","Apricot","Avocado","Banana","Blackberry","Blueberry","Cherry","Coconut","Cucumber","Durian","Dragonfruit",
    "Fig","Gooseberry","Grape","Guava","Jackfruit","Plum","Kiwifruit","Kumquat","Lemon","Lime","Mango","Watermelon","Mulberry","Orange",
    "Papaya","Passionfruit","Peach","Pear","Persimmon","Pineapple","Pineberry","Quince","Raspberry","Soursop","Strawberry","Tamarind",
    "Yuzu", "kiwi", "pineapple"},
    {"Afghanistan","Albania","Algeria","Andorra","Angola","Argentina","Armenia","Australia","Austria","Azerbaijan",
    "Bahrain","Bangladesh","Barbados","Belarus","Belgium","Belize","Benin","Bhutan","Bolivia", "Botswana","Brazil",
    "Brunei","Bulgaria","Burkina Faso","Burundi","Cambodia","Cameroon","Canada","Chad","Chile","China","Colombia","Comoros","Congo","Croatia",
    "Cuba",    "Cyprus","Denmark","Djibouti","Dominica","Ecuador","Egypt","Eritrea","Estonia","Eswatini","Ethiopia","Fiji","Finland","France","Gabon",
    "Georgia","Germany","Ghana","Greece","Grenada","Guatemala","Guinea","Guyana","Haiti","Honduras","Hungary","Iceland","India","Indonesia",
    "Iran","Iraq","Ireland","Israel","Italy","Jamaica","Japan","Jordan","Kazakhstan","Kenya","Kiribati","Korea","Kosovo","Kuwait","Kyrgyzstan",
    "Laos","Latvia","Lebanon","Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Madagascar","Malawi","Malaysia","Maldives",
    "Mali","Malta","Mauritania","Mauritius","Mexico","Micronesia","Moldova","Monaco","Mongolia","Montenegro","Morocco","Mozambique","Myanmar",
    "Namibia","Nauru","Nepal","Netherlands","Nicaragua","Niger","Nigeria","Norway", "Oman", "Pakistan","Palau","Panama","Paraguay",
    "Peru","Philippines","Poland","Portugal","Qatar", "Romania","Russia","Rwanda","Samoa","Senegal","Serbia","Seychelles","Singapore",
    "Slovakia","Slovenia","Somalia","Spain","Sudan","Sudan","Suriname","Sweden","Switzerland","Syria","Taiwan","Tajikistan","Tanzania",
    "Thailand","Togo","Tonga","Tunisia","Turkey","Turkmenistan","Tuvalu","Uganda","Ukraine","USA","Uruguay","Uzbekistan", "Vanuatu",
    "Venezuela","Vietnam", "Yemen", "Zambia", "Zimbabwe"}};
    int count = 0;
    printf("Game start!\n");
    score(0);
    int num;
    char problem[20];
    char *answer;
    int len_answer;
    char char_answer;
    int right = 0;
    printf("1 for Animals, 2 for nations, 3 for fruits Select 1-3\n");
    scanf("%d", &select);
    if (select == 1){
        num = rand()%len_animal;
    }
    else if (select == 2){
        num = rand()%len_nation;
    }
    else if (select == 3){
        num = rand()%len_fruit;
    }
    else{
        printf("input the number again\n");
        return 0;
    }
    len_answer = strlen(problems[select - 1][num]);
    strcpy(problem, problems[select - 1][num]);
    problem[len_answer] = 0;
    answer = (char*)malloc(sizeof(char)*len_answer+1);
    answer[len_answer] = 0;
    for (int i = 0; i<len_answer; i++){
        answer[i] = '_';
    }
    while(1){
        printf("Input an alphabet\n");
        while (1){
            scanf(" %c", &char_answer);
            if (('a'<=char_answer&&char_answer<='z')||('A'<=char_answer&&char_answer<='Z')){
                break;
            }
            printf("Input the alphabet again\n");
        }
        right = 0;
        printf(" %c", char_answer);
        for (int i = 0; i<len_answer; i++){
            if ((problem[i] == char_answer)||(problem[i] == char_answer+32)||(problem[i] == char_answer-32)){
                answer[i] = problem[i];
                right = 1;
            }
        }
        if (right == 0){
            count++;
        }
        printf("%d  %d\n\n", right , count);
        right = 0;
        score(count);
        for (int i = 0; i<len_answer; i++){
            printf("%c", answer[i]);
        }
        printf("\n");
        if (strcmp(answer, problem) == 0){
            printf("★★★ YOU WIN ★★★\n");
            break;
        }
        if (count == 6){
            printf("You lost. Try again\n");
            printf("The answer is \"%s\"\n", problem);
            break;
         }
    }
    return 0;
}
void score(int count){
    if (count == 0){
        printf("  ┌───┐\n");
        printf("      │\n");
        printf("      │\n");
        printf("      │\n");
        printf("      ┴\n");
    }
    else if (count == 1){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf("      │\n");
        printf("      │\n");
        printf("      ┴\n");
    }
    else if (count == 2){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf("  |   │\n");
        printf("      │\n");
        printf("      ┴\n");
    }
    else if (count == 3){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" /|   │\n");
        printf("      │\n");
        printf("      ┴\n");
    }
    else if (count == 4){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" /|\\  │\n");
        printf("      │\n");
        printf("      ┴\n");
    }
    else if (count == 5){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" /|\\  │\n");
        printf(" /    │\n");
        printf("      ┴\n");
    }
    else if (count == 6){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" /|\\  │\n");
        printf(" / \\  │\n");
        printf("      ┴\n");
    }
}
//main
int main()
{
    const char game_names[5][20] = {"connect four", "number baseball", "gomoku", "tic-tac-toe", "hang man"}; //in case, let it as a const array, not hard-coded string.
    const int game_count = 5;
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
        case '5':
            hangman();
            break;
        default:
            printf("You typed a wrong number! Please try again!\n");
            break;
        }
    }
}
