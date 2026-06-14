#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGIT_LEN 10 
#define NUM_LEN 100
#define STR_LEN NUM_LEN + NUM_LEN * DIGIT_LEN + 1

typedef long long i64;
typedef unsigned long long u64;

int compare(const void *n1, const void *n2) {
    return *(i64*)n2 - *(i64*)n1;
}

int main(void) {
    u64 tc_count = 0;
    scanf("%llu", &tc_count);

    for (u64 r = 0; r < tc_count; r++) {
        u64 n = 0;
        scanf("%llu\n", &n);

        u64 nums_i = 0;
        u64 nums[100] = {0};

        char line[STR_LEN] = {0};

        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        for (char *str = line; ; str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;
            nums[nums_i++] = strtoull(token, NULL, 10);
        }

        qsort(nums, nums_i, sizeof(u64), compare);

        i64 result = 0;
        for (u64 i = 0; i < nums_i-2; i++) {
            if (nums[i] % nums[i+1] != nums[i+2]) {
                result = -1;
                break;
            }
            // printf("index: %llu, number: %llu\n", i, nums[i]);
        }

        if (result == -1)
            fprintf(stdout, "%d\n", -1);
        else
            fprintf(stdout, "%llu %llu\n", nums[0], nums[1]);
    }
}
