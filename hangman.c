#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
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
    while (1){
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