#include <stdio.h>

int main() {
    int number;
    int isOdd, isEven;

    printf("Enter the number: ");
    scanf("%d", &number);

  
    isOdd = number & 1;
    isEven = !isOdd;

    if (isOdd) {
        printf("The number is odd = 1\n");
        printf("The number is even = 0\n");
    } else {
        printf("The number is odd = 0\n");
        printf("The number is even = 1\n");
    }

    return 0;
}