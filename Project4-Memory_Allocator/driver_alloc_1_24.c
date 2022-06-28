#include "mem.h"
#include <stdio.h>

int main() {
    Initialize_Memory_Allocator(1600);
    Mem_Dump();

    char *p[25];
    for (int i = 1; i < 24; i++)
        if((p[i] = Mem_Alloc(i)) == NULL) {
            printf("Allocation failed\n");
            exit(0);
        }
    Mem_Dump();

    Free_Memory_Allocator();
    return 0;
}