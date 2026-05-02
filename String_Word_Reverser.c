#include <stdio.h>
#include <string.h>

void reverse_segment(char* start, char* end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void reverse_words(char* s) {
    char* word_start = s;
    char* temp = s;

    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse_segment(word_start, temp - 1);
        } else if (*temp == ' ') {
            reverse_segment(word_start, temp - 1);
            word_start = temp + 1;
        }
    }

    reverse_segment(s, temp - 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);
    reverse_words(str);

    printf("Reversed words: %s\n", str);

    return 0;
}