#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT_COUNT 3
#define MAX_NUM 100
#define STR_LEN MAX_NUM + MAX_NUM * MAX_DIGIT_COUNT + 1

int compare(const void* n1, const void* n2) {
    return *(int*)n1 - *(int*)n2;
}

int main(void) {
    int tc_count = 0;
    scanf("%d", &tc_count);

    for (int t = 0; t < tc_count; t++) {
        int n = 0;
        int c = 0;
        scanf("%d %d", &n, &c);

        while (getchar() != '\n');

        int a_i = 0;
        int a[MAX_NUM] = {0};
        int b_i = 0;
        int b[MAX_NUM] = {0};
        char line[STR_LEN] = {0};
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        for (char *token = line;;token = NULL) {
            char *temp = strtok(token, " ");
            if (temp == NULL)
                break;
            a[a_i++] = strtol(temp, NULL, 10);
        }

        memset(line, 0, STR_LEN);

        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        for (char *token = line;;token = NULL) {
            char *temp = strtok(token, " ");
            if (temp == NULL)
                break;
            b[b_i++] = strtol(temp, NULL, 10);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            if (a[i] > b[i]) {
                total += a[i] - b[i];
            } else {
                total = -1;
                break;
            }
        }

        if (total != -1) {
            printf("%d\n", total);
            continue;
        }

        qsort(a, a_i, sizeof(int), compare);
        qsort(b, b_i, sizeof(int), compare);

        // because a array have to re-order
        total = c;

        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            if (a[i] > b[i]) {
                total += a[i] - b[i];
            } else {
                total = -1;
                break;
            }
        }

        printf("%d\n", total);
    }
}
