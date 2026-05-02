#include <stdio.h>

int main() {
    int num, originalNum, remainder, result = 0;

  
    printf("enter the number = ");
    scanf("%d", &num);

    originalNum = num;

   
    while (originalNum != 0) {
       
        remainder = originalNum % 10;
        
        
        result += remainder * remainder * remainder;
        
       
        originalNum /= 10;
    }

  
    if (result == num) {
        printf("armstrong number\n");
    } else {
        printf("not an armstrong number\n");
    }

    return 0;
}