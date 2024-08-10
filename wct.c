//WORD COUNT TOOL FOR FILE
#include <stdio.h>
#include <ctype.h>

// Function to count words in a string
int count_words(const char *str) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (isspace(*str)) {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }
        str++;
    }

    return count;
}

int main() {
    char filename[1024];
    FILE *file;
    char input[1024];

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    int word_count = 0;
    while (fgets(input, sizeof(input), file)) {
        word_count += count_words(input);
    }

    fclose(file);

    printf("Word count: %d\n", word_count);

    return 0;
}