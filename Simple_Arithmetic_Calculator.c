#include <stdio.h>

int main() {
    float num1, num2, result;
    char op;

   
    printf("Enter Number_1\n");
    scanf("%f", &num1);

   
    printf("Enter the operator (+, -, *, /)\n");
    scanf(" %c", &op);

  
    printf("Enter Number_2\n");
    scanf("%f", &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("The result = %.0f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result = %.0f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result = %.0f\n", result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("The result = %.2f\n", result);
            } else {
                printf("Error! Division by zero.\n");
            }
            break;
        default:
            printf("Error! Operator is not correct.\n");
    }

    return 0;
}