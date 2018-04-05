#include <time.h>
#include <stdlib.h>
#include "stdio.h"
#include "string.h"

void rolldice() {
    int diceroll = (rand() % 6) + 1;
    printf("Dice roll: %d\n", diceroll);
}

int checkuser() {
    char userin;
    printf("Keep going? (Y/N): ");
    userin = getchar();
    
    if ((userin == 'Y') || (userin == 'y')){
        return 1;
    } else return 0;
}

int main(void) {
    srand(time(0));   // only seeds once per program execution
    int keepgoing=1;
    while (keepgoing) {
        rolldice();
        keepgoing = checkuser();
    }
    return 0;
}