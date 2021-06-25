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

//function definitions
void connect_four(); //asas6978

void num_baseball(); //jinnyfruit

void gomoku(); // Tuna

int check(char index[], int size);
void score(char nothing, int count);
int tic_tac_toe() //jj052
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
                break;
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
                break;
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





int hangman(){
    srand(time(NULL));
    char nothing = ' ';
    char head = '○';
    char body = '│';
    char arm[2];
    arm[0] = '/';
    arm[1] = '\\';
    char leg[2];
    leg[0] = '/';
    leg[1] = '\\';
    int select;
    char animal[300][20] = {"elephant", "chicken", "Aardvark", "Alligator", "Alpaca", "Anaconda", "Ant", "Antelope","Ape","Aphid",
    "Armadillo","Asp","Baboon","Badger","Eagle","Barracuda","Bass","Basset Hound","Bat","Bear","Beaver","Bedbug","Bee","Beetle",
    "Bird","Bison","Whale","Bobcat","Buffalo","Butterfly","Buzzard","Camel","Caribou","Carp","Cat","Caterpillar","Catfish","Cheetah","Chicken",
    "Chimpanzee","Chipmunk","Cobra","Cod","Condor","Cougar","Cow","Coyote","Crab","Crane","Cricket","Crocodile","Crow","Cuckoo","Deer","Dinosaur",
    "Dog","Dolphin","Donkey","Dove","Dragonfly","Duck","Eagle","Eel","Elephant","Emu","Falcon","Ferret","Finch","Fish","Flamingo",
    "Flea","Fly","Fox","Frog","Goat","Goose","Gopher","Gorilla","Grasshopper","Hamster","Hare","Hawk","Hippopotamus","Horse",
    "Hummingbird","Humpback Whale","Husky","Iguana","Impala","Kangaroo","Ladybug","Leopard","Lion","Lizard","Llama","Lobster","Mongoose",
    "Monkey","Moose","Mosquito","Moth","Mountain goat","Mouse","Mule","Octopus","Orca","Ostrich","Otter","Owl","Ox","Oyster","Panda",
    "Parrot","Peacock","Pelican","Penguin","Perch","Pheasant","Pig","Pigeon","Polar bear","Porcupine","Quail","Rabbit","Raccoon",
    "Rat","Rattlesnake","Raven","Rooster","Sheep","Shrew","Skunk","Snail","Snake","Spider","Tiger","Walrus","Whale","Wolf","Zebra", "Giraffe",
    "Mole"};
    int len_animal = strlen(animal);
    char fruit[300][20] = {"Apple","Apricot","Avocado","Banana","Blackberry","Blueberry","Cherry","Coconut","Cucumber","Durian","Dragonfruit",
    "Fig","Gooseberry","Grape","Guava","Jackfruit","Plum","Kiwifruit","Kumquat","Lemon","Lime","Mango","Watermelon","Mulberry","Orange",
    "Papaya","Passionfruit","Peach","Pear","Persimmon","Pineapple","Pineberry","Quince","Raspberry","Soursop","Strawberry","Tamarind",
    "Yuzu", "kiwi", "pineapple"};
    int len_fruit = strlen(fruit);
    char nation[200][20] = {"Afghanistan","Albania","Algeria","Andorra","Angola","Argentina","Armenia","Australia","Austria","Azerbaijan",
    "Bahrain","Bangladesh","Barbados","Belarus","Belgium","Belize","Benin","Bhutan","Bolivia","Bosnia and Herzegovina","Botswana","Brazil",
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
    "Venezuela","Vietnam", "Yemen", "Zambia", "Zimbabwe"};
    int len_nation = strlen(nation);
    printf("Game start!\n");
    printf("  ┌───┐\n");
    printf("  %c   │\n", nothing );
    printf(" %c%c%c  │\n",nothing,nothing,nothing );
    printf(" %c %c  │\n",nothing,nothing);
    printf("      ┴\n");
    int count = 0;
    int num;
    char problem[20];
    char *answer;
    int len_answer;
    char char_answer;
    int right = 0;
    int cap;
    printf("1 for Animals, 2 for nations, 3 for fruits Select 1-3\n");
    scanf("%d", &select);
    if (select == 1){
        num = rand()%len_animal;
        len_answer = strlen(animal[num]);
        for (int i = 0; i<len_answer; i++){
            problem[i] = animal[num][i];
        }
        problem[len_answer] = NULL;
        answer = (int*)malloc(sizeof(int)*len_answer)+1;
        answer[len_answer] = NULL;
        for (int i = 0; i<len_answer; i++){
            answer[i] = '_';
        }
        while(1){
            printf("Input an alphabet\n");
            while (1){
                scanf(" %c", &char_answer);
                if (('a'<=char_answer)&&(char_answer<='z')){
                    cap = 0; 
                    break;
                }
                if (('A'<=char_answer)&&(char_answer<='Z')){
                    cap = 1; // caps : 1
                    break;
                }
                printf("Input the alphabet again\n");
            }
            for (int i = 0; i<len_animal; i++){
                if ((cap == 0)&&problem[i] == char_answer){
                    answer[i] = problem[i];
                    right = 1;
                }
                else if ((cap == 1)&&problem[i] == char_answer){
                    answer[i] = problem[i];
                right = 1;
                }
                else if ((cap == 0)&&(char_answer-32 == problem[i])){
                    answer[i] = problem[i];
                    right = 1;
                }
                else if ((cap == 1)&&(char_answer+32==problem[i])){
                    answer[i] = problem[i];
                    right = 1;
                }
            }
            if (right == 0){
                count++;
            }
            right = 0;
            score(nothing, count);
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
                break;
             }
        }
    }
    else if (select == 2){
        num = rand()%len_nation;
        len_answer = strlen(nation[num]);
        for (int i = 0; i<len_answer; i++){
            problem[i] = nation[num][i];
        }
        problem[len_answer] = NULL;
        answer = (int*)malloc(sizeof(int)*len_answer)+1;
        answer[len_answer] = NULL;
        for (int i = 0; i<len_answer; i++){
            answer[i] = '_';
        }//animal
        while(1){
            printf("Input an alphabet\n");
            while (1){
                scanf(" %c", &char_answer);
                if (('a'<=char_answer)&&(char_answer<='z')){
                    cap = 0; 
                    break;
                }
                if (('A'<=char_answer)&&(char_answer<='Z')){
                    cap = 1; // caps : 1
                    break;
                }
                printf("Input the alphabet again\n");
            }
            for (int i = 0; i<len_nation; i++){
                if ((cap == 0)&&problem[i] == char_answer){
                    answer[i] = problem[i];
                    right = 1;
                }
                else if ((cap == 1)&&problem[i] == char_answer){
                    answer[i] = problem[i];
                    right = 1;
                }
                else if ((cap == 0)&&(char_answer-32 == problem[i])){
                    answer[i] = problem[i];
                    right = 1;
                }
                else if ((cap == 1)&&(char_answer+32==problem[i])){
                    answer[i] = problem[i];
                    right = 1;
                }
            }
            if (right == 0){
                count++;
            }
            right = 0;
            score(nothing, count);
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
                break;
            }
        }
    }
    else if (select == 3){
        num = rand()%len_fruit;
        len_answer = strlen(fruit[num]);
        for (int i = 0; i<len_answer; i++){
            problem[i] = fruit[num][i];
        }
        problem[len_answer] = NULL;
        answer = (int*)malloc(sizeof(int)*len_answer)+1;
        answer[len_answer] = NULL;
        for (int i = 0; i<len_answer; i++){
            answer[i] = '_';
        }
        while(1){
            printf("Input an alphabet\n");
            while (1){
                scanf(" %c", &char_answer);
                if (('a'<=char_answer)&&(char_answer<='z')){
                    cap = 0; 
                    break;
                }
                if (('A'<=char_answer)&&(char_answer<='Z')){
                    cap = 1; // caps : 1
                    break;
                }
                printf("Input the alphabet again\n");
            }
            for (int i = 0; i<len_fruit; i++){
                if ((cap == 0)&&problem[i] == char_answer){
                    answer[i] = problem[i];
                    right = 1;
                }
                else if ((cap == 1)&&problem[i] == char_answer){
                    answer[i] = problem[i];
                    right = 1;
                }
                else if ((cap == 0)&&(char_answer-32 == problem[i])){
                    answer[i] = problem[i];
                    right = 1;
                }
                else if ((cap == 1)&&(char_answer+32==problem[i])){
                    answer[i] = problem[i];
                    right = 1;
                }
            }
            if (right == 0){
                count++;
            }
            right = 0;
            score(nothing, count);
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
                break;
            }
        }
    }
    else{
        printf("input the number again\n");
        return 0;
    }
    
}
void score(char nothing, int count){
    if (count == 0){
        printf("  ┌───┐\n");
        printf("  %c   │\n", nothing);
        printf(" %c%c%c  │\n",nothing,nothing,nothing );
        printf(" %c %c  │\n",nothing,nothing);
        printf("      ┴\n");
    }
    else if (count == 1){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" %c%c%c  │\n",nothing,nothing,nothing );
        printf(" %c %c  │\n",nothing,nothing);
        printf("      ┴\n");
    }
    else if (count == 2){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" %c|%c  │\n",nothing,nothing,nothing );
        printf(" %c %c  │\n",nothing,nothing);
        printf("      ┴\n");
    }
    else if (count == 3){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" /|%c  │\n",nothing,nothing,nothing );
        printf(" %c %c  │\n",nothing,nothing);
        printf("      ┴\n");
    }
    else if (count == 4){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" /|\\  │\n",nothing,nothing,nothing );
        printf(" %c %c  │\n",nothing,nothing);
        printf("      ┴\n");
    }
    else if (count == 5){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" /|\\  │\n",nothing,nothing,nothing );
        printf(" / %c  │\n",nothing,nothing);
        printf("      ┴\n");
    }
    else if (count == 6){
        printf("  ┌───┐\n");
        printf("  ○   │\n");
        printf(" /|\\  │\n",nothing,nothing,nothing );
        printf(" / \\  │\n",nothing,nothing);
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
