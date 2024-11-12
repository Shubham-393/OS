#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int data[argc - 1];

    for (int i = 1; i < argc; i++) {
        data[i - 1] = atoi(argv[i]);  // Convert each string argument back to integer
    }

    printf("Printing elements in reverse:\n");
    for (int i = argc - 2; i >= 0; i--) {  // Print elements in reverse order
        printf("%d ", data[i]);
    }
    printf("\nEXECVE task completed.\n");

    return 0;
}

