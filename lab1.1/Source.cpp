#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int my_atoi(const char* str) {
    int result = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

int main() {
    FILE* file;
    char line[100];
    int sum = 0;

    if (fopen_s(&file, "in.txt", "r") != 0) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0;

        int number = my_atoi(line);
        sum = sum + number;
    }
    fclose(file);
    printf("The sum is: %d\n", sum);
    return 0;
}