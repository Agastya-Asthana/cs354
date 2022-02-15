#include <stdio.h>

int main(){
    //pointers are variableds that hold memeory address
    int x = 69;
    int* pointer;   //pointer declreation
    pointer = &x;   //assign pointer to mem addr x

    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d\n", x, &x, pointer, &pointer, *pointer);

    *pointer = 9;
    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d\n", x, &x, pointer, &pointer, *pointer);

    int y = 2;
    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d, y = %d, &y = %p\n", x, &x, pointer, &pointer, *pointer, y, &y);

    pointer = &y;
    *pointer = 420;
    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d, y = %d, &y = %p\n", x, &x, pointer, &pointer, *pointer, y, &y);

    int arr[4] = {10, 20, 30, 40};
    arr[0] = 15;

    for (int i = 0; i < 4; i++)
    {
        printf("arr[%d] = %d at address %p\n", i, arr[i], &arr[i]);
    }

    pointer = arr;
    printf("*p - %d\n", *pointer);

    //Pointer arithmetic    

    return 0;
}