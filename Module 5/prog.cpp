#include <stdio.h>
#include <iostream>


int main(int argc, char* argv[]){
    char input[256];
    printf("Type something for us to print out: ");
    gets(input);
    printf("You entered: %s\n", input);
    return 0;
}
