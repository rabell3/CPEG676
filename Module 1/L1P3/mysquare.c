#include "stdio.h"
#include "string.h"

int square(int a) {
    return a*a;
}

int main(void) {
    int base=8;
    int product = square(base);

    printf("Base: %d\nProduct: %d\n",base, product);
    return 0;
}