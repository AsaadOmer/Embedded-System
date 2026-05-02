#include <stdio.h>
void print_fib_iterative(int n) {
    int t1 = 0, t2 = 1, next_term;
    
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        next_term = t1 + t2;
        t1 = t2;
        t2 = next_term;
    }
}

int fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    int limit;

    printf("Enter the number of terms: ");
    scanf("%d", &limit);

    printf("Fibonacci Series (Iterative): ");
    print_fib_iterative(limit);

    printf("\nFibonacci Series (Recursive): ");
    for (int i = 0; i < limit; i++) {
        printf("%d, ", fib_recursive(i));
    }

    printf("\n");
    return 0;
}