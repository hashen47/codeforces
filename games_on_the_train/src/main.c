#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGIT_LEN 1
#define MAX_HEIGHT_COUNT 6
#define STR_LEN MAX_HEIGHT_COUNT + MAX_HEIGHT_COUNT * DIGIT_LEN + 1

int compare(const void *n1, const void *n2) {
    return *(int*)n1 - *(int*)n2;
}

int main(void) {
    int tc_count = 0;
    scanf("%d", &tc_count);

    for (int t = 0; t < tc_count; t++) {
        int n = 0;
        scanf("%d\n", &n);

        int heights_i = 0;
        int heights[MAX_HEIGHT_COUNT] = {0};

        char line[STR_LEN] = {0};
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        for (char *str = line; ;str = NULL) {
            char *token = NULL;
            token = strtok(str, " ");
            if (token == NULL)
                break;

            heights[heights_i++] = strtol(token, NULL, 10);
        }

        qsort(heights, heights_i, sizeof(int), compare);

        printf("%d\n", heights[heights_i-1]-heights[0]+1);
    }
}
