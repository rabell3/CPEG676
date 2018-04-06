#include "stdlib.h"
#include "stdio.h"
#include "string.h"


static char *inputfile = "input1.txt";

char* fileread(char * infile) {
    static char data[256];
    FILE* fp = fopen(infile, "r");
    if(!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    
    while (fgets(data, sizeof data, fp) != NULL)

    // printf("data: %s\n", data);
    if (ferror(fp))
        puts("I/O error when reading\n");
    else if (feof(fp))
        puts("File read\n");
 
    fclose(fp);

    return data;
}

char** translate(char * datain){
    static char data[256];
    *data = datain;
    return data;
}

int main(void) {
    printf("Rotty the rotator\n");

    char *FILEBUFF, *translated; // This isn't going to work. Need to malloc()

    FILEBUFF = fileread(inputfile);

    printf("ourbuff: %s\n", FILEBUFF);
    translated = translate(FILEBUFF);
    printf("translated: %s\n", translated);
/*
    rotate();

    writefile();
*/
    return 0;
}