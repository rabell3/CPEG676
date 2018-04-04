#include "stdio.h"

int main(void) {
	char y[16] = "0123456789abcdef";
    char x[16] = "CATSCATSCATSCATS";
    char z[16] = "bananabananabana";
    printf("%s should be CAT", x);
    
    printf("\n%p\n%p\n%p", (void*)&y, (void*)&x, (void*)&z);
    int i = 0;
    
    while (x[i] != 0){
    	printf("\n%o was the ascii value, %c,  of character %d\n", (unsigned int) x[i], x[i], i);
    	i++;
    }

	fflush(stdout);   
	usleep(1);
    return 0;
}