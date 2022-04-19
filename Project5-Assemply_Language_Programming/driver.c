#include <stdio.h>
#include <string.h>


void To_Upper(char *str);
  
int main() {
    char str[20];
    strcpy(str, "cs 354 is Awesome!");
    printf("Original string:   %s\n",str);
    To_Upper(str);
    printf("\n");
    printf("Upper case string: %s\n",str);
    return 0;
}



