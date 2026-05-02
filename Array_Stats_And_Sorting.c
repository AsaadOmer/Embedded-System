#include <stdio.h>

int main() {
    int arr_1[5];
    int max, min, max_pos = 0, min_pos = 0;

    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr_1[i]);
    }

    printf("\nThe 5 elements of arr_1 are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr_1[i]);
    }

    max = arr_1[0];
    min = arr_1[0];

    for (int i = 1; i < 5; i++) {
        if (arr_1[i] > max) {
            max = arr_1[i];
            max_pos = i;
        }
        if (arr_1[i] < min) {
            min = arr_1[i];
            min_pos = i;
        }
    }

    printf("\n\nThe maximum Number is %d in position %d", max, max_pos);
    printf("\nThe minimum Number is %d in position %d", min, min_pos);

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (arr_1[j] > arr_1[j + 1]) {
                int temp = arr_1[j];
                arr_1[j] = arr_1[j + 1];
                arr_1[j + 1] = temp;
            }
        }
    }

    printf("\n\nArray elements after sorting (Ascending): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr_1[i]);
    }

    printf("\n");
    return 0;
}