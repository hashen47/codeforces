#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGIT_COUNT 4
#define N 1000
#define STR_LEN N + N * DIGIT_COUNT + 1

int compare(const void *n1, const void *n2) {
    return *(int*)n1 - *(int*)n2;
}

int main(void) {
    int tc_count = 0;
    scanf("%d", &tc_count);

    for (int t = 0; t < tc_count; t++) {
        int n = 0;
        scanf("%d\n", &n);

        char line[STR_LEN] = {0};
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        int nums_i = 0;
        int nums[N] = {0};

        for (char *str = line; ;str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;
            nums[nums_i++] = strtol(token, NULL, 10);
        }

        qsort(nums, nums_i, sizeof(int), compare);
        // printf("max: %d, max: %d\n", nums[0], nums[nums_i-1]);
        int middle = (nums[0] + nums[nums_i-1]);
        middle >>= 1;
        printf("%d\n", nums[nums_i-1] - middle);
    }
}
