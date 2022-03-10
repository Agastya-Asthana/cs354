#include <stdio.h>
#include <stdlib.h>

void Reverse(char *str);

void Reverse(char *str){
    int i;
    for (i = 0; *(str+i) != '\0'; ++i);
    char *buff = malloc(sizeof(char)*(i+1));
    int buffIndex = 0;
    for (int j = (i-1); j >= 0; --j) {
        *(buff+(buffIndex++)) = *(str+j);
        //printf("%c", *(str+j));
    }
    *(buff+buffIndex) = '\0';
    for (int j = 0; j < (i + 1); ++j) {
        *(str+j) = *(buff+j);
    }
    free(buff);
}

