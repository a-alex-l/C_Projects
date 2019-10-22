#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mergesort.h"

int comparator_char(const void *a, const void *b) {
    return *((const char*)a) - *((const char*)b);
}

int comparator_int(const void *a, const void *b) {
    return *((const int*)a) - *((const int*)b);
}

int comparator_str(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}


int main(int argc, char **argv) {
    int mergeerror = 0;
    if (strcmp(argv[1], "char") == 0) {
        char *array = malloc(sizeof(char) * (argc - 2));
        for (int i = 0; i < argc - 2; i++) {
            array[i] = argv[i + 2][0];
        }
        mergeerror = mergesort(array, (argc - 2), sizeof(char), &comparator_char);
        for (int i = 0; i < argc - 2; i++) {
            printf("%c ", array[i]);
        }
        free(array);
    }
    if (strcmp(argv[1], "int") == 0) {
        int *array = malloc(sizeof(int) * (argc - 2));
        for (int i = 0; i < argc - 2; i++) {
            array[i] = atoi(argv[i + 2]);
        }
        mergeerror = mergesort(array, (argc - 2), sizeof(int), &comparator_int);
        for (int i = 0; i < argc - 2; i++) {
            printf("%d ", array[i]);
        }
        free(array);
    }
    if (strcmp(argv[1], "str") == 0) {
        mergeerror = mergesort(argv + 2, (argc - 2), sizeof(char**), &comparator_str);
        for (int i = 2; i < argc; i++) {
            printf("%s ", argv[i]);
        }
    }
    if (mergeerror) {
        printf("Error: memory allocation failed.");
        return 1;
    }
    return 0;
}
