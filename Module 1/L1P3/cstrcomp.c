#include "stdio.h"
#include "string.h"

int main(void) {
  char text1[128] = "Andy is the greatest";
//  char text2[128] = "Andy is the greatest";
  char text2[128] = "Robert is the greatest";


  printf("%s\n", text1);
  printf("%s\n", text2);

  int value = strcmp(text1, text2);

  printf("Comparision: %d\n", value);

  return 0;
}