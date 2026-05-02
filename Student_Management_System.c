#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float degree;
    int section;
};

void print_students(struct Student *ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d\n", i + 1);
        printf("Name   : %s\n", (ptr + i)->name);
        printf("Age    : %d\n", (ptr + i)->age);
        printf("Degree : %.2f\n", (ptr + i)->degree);
        printf("Section: %d\n", (ptr + i)->section);
        printf("--------------------------\n");
    }
}

int main() {
    struct Student school[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter data for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", school[i].name);
        printf("Age: ");
        scanf("%d", &school[i].age);
        printf("Degree: ");
        scanf("%f", &school[i].degree);
        printf("Section: ");
        scanf("%d", &school[i].section);
        printf("\n");
    }

    print_students(school, 5);

    return 0;
}