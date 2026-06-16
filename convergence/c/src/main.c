#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// BUG:
// hashmap fail because of allocation size is too much
// have to fix that

#define N 100
#define DIGIT_LEN 10 
#define STR_LEN N + DIGIT_LEN * N + 1

typedef unsigned long long u64;

int compare_asc(const void *n1, const void *n2) {
    return *((u64*)n1) - *((u64*)n2);
}

int compare_desc(const void *n1, const void *n2) {
    return *((u64*)n2) - *((u64*)n1);
}

int main(void) {
    u64 tc_count = 0;
    scanf("%llu", &tc_count);

    for (u64 r = 0; r < tc_count; r++) {
        // read n
        u64 n = 0;
        scanf("%llu\n", &n);

        // read friends locations
        char line[STR_LEN] = {0};
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        u64 nums_i = 0;
        u64 nums[N] = {0};

        for (char *str = line; ;str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;

            u64 n = strtoull(token, NULL, 10);
            nums[nums_i++] = n;
        }

        qsort(nums, nums_i, sizeof(u64), compare_asc);

        // find minimum call count 
        u64 call_count = 0;
        for (u64 i = 0; i < nums_i/2; i++) {
            if (nums[i] != nums[nums_i/2] || nums[nums_i-1-i] != nums[nums_i/2]) {
                call_count++;
            }
        }

        printf("%llu\n", call_count);
    }
}
