#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_DIGIT_LEN 11 
#define MAX_N 2 * 10 * 10 * 10 * 10 * 10
#define STR_LEN MAX_N + MAX_DIGIT_LEN * MAX_N + 1

typedef unsigned long long u64;

int main(void) {
    u64 tc_count = 0;
    scanf("%llu", &tc_count);

    for (u64 r = 0; r < tc_count; r++) {
        u64 n = 0;
        scanf("%llu\n", &n);

        char line[STR_LEN] = {0};
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        // printf("line: %s\n", line);
        u64 nums_i = 0;
        u64 nums[MAX_N] = {0};
        u64 sum = 0;
        u64 min_avg = ULLONG_MAX;

        for (char *str = line; ; str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;
            nums[nums_i++] = strtol(token, NULL, 10);
            sum += nums[nums_i-1];

            if (min_avg > sum / nums_i)
                min_avg = sum / nums_i;

            printf("%llu ", min_avg);
        }

        /*
        for (u64 i = 0; i < n; i++) {
            if (nums[i] == 0) {
                printf("%d ", nums[i] > min_avg ? nums[i] : min_avg);
            } else {
                printf("%d ", min_avg);
            }
        }
        */

        printf("\n");
    }
}
