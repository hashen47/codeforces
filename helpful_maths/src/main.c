#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SIMPLE ARRAY IMPLEMENTATION
void array_init(int** arr) {
    *arr = malloc(sizeof(int) * 2 + sizeof(int) * 4);
    (*arr)[0] = 0; // index
    (*arr)[1] = 4; // bufsize
}

void array_free(int **arr) {
    if (arr == NULL) 
        return;
    if (*arr != NULL)
        free(*arr);
    *arr = NULL;
}

void array_append(int **arr, int val) {
    if (2 + (*arr)[0] + 1 >= (*arr)[1]) {
        (*arr)[1] *= 2;
        *arr = realloc(*arr, sizeof(int) * 2 + sizeof(int) * (*arr)[1]);
    }
    (*arr)[2 + (*arr)[0]++] = val;
}

int array_get(int **arr, int index) {
    return (*arr)[2 + index];
}

int array_len(int **arr) {
    return (*arr)[0];
}

int compare(const void *a, const void *b) {
    int n1 = *((int*)a);
    int n2 = *((int*)b);
    return n1 - n2;
}

#define STRLEN 101

int main() {
    char s[STRLEN] = {0};
    fgets((char*)&s, STRLEN, stdin);
    size_t len = strlen(s); // including newline character

    int *numbers = NULL;
    array_init(&numbers);

    for (size_t i = 0; i < len-1; i++) {
        char ch = s[i];
        if (strncmp((const char*)&ch, "+", 1) == 0)
            continue;
        array_append(&numbers, ch-48);
    }

    qsort(numbers + 2, array_len(&numbers), sizeof(int), compare);

    int arr_len = array_len(&numbers);
    for (int i = 0; i < arr_len; i++) {
        printf("%d", array_get(&numbers, i));
        if (i != arr_len-1) {
            printf("+");
        }
    }
    printf("\n");
}
