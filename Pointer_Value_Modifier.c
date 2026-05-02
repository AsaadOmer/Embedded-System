#include <stdio.h>

void edit(int *ptr) {
    (*ptr)++; 
}

int main() {
    int x;

    printf("Enter the value of x\n");
    scanf("%d", &x);

    printf("Before calling edit x=%d\n", x);

    edit(&x);

    printf("After calling edit x=%d\n", x);

    int values[] = {5, 20, 80};
    printf("\nStored numbers: ");
    for(int i = 0; i < 3; i++) {
        printf("%d ", values[i]);
    }

    printf("\n");
    return 0;
}