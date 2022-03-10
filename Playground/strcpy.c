#include <stdio.h>

void String_Copy(char from[], char to[]);

int main(){
    char str[] = "This is the original string";
    char str2[1024] = "aas;hfjkashfkjnvkjdhfaksjfha;jj";

    printf("%s\n", str);
    printf("%s\n", str2);

    String_Copy(str, str2);

    printf("%s\n", str);
    printf("%s\n", str2);

    return 0;
}

void String_Copy(char from[], char to[]){
    int i = 0;
    while (from[i] != '\0')
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';   //copy the \0
    return;
    
}