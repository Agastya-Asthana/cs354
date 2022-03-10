#include <stdio.h>
#include <stdlib.h>

// argc is the argument count -> integer value
// argv are the argument values -> array of strings

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <num_elems>\n", argv[0]);
		exit(1);
    }

    int num = atoi(argv[1]);
    printf("num = %d\n", num);

	// create a variable length array (vla)
    //int a[num];

    int *a = malloc(sizeof(int) * num);

    for (int i = 0; i < num; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < num; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    free(a);
    return 0;
}
