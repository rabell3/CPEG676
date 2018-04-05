#include <iostream>
#include <stdio.h>

int main(){
    int i=0;
      for (;;) {
        if (i < 5) {
            printf("i = %d\n", i);
            i++;
        } else break;
    }
    printf("made it\n");
    return 0;
}