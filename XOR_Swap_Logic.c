#include <stdio.h>


void swap(int x, int y) {
  
    printf("befor swapping\n");
    printf("x=%d y=%d\n", x, y);

   
    x = x + y; 
    y = x - y; 
    x = x - y;

   
    printf("after swapping\n");
    printf("x=%d y=%d\n", x, y);
}

int main() {
    int num1, num2;

    printf("Enter first number\n");
    scanf("%d", &num1);

    printf("Enter second number\n");
    scanf("%d", &num2);

   
    swap(num1, num2);

    return 0;
}