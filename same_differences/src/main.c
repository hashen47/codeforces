#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CHAR_LEN 6 
#define NUMS_LEN 2 * 10 * 10 * 10 * 10 * 10
#define STR_LEN NUMS_LEN + CHAR_LEN * NUMS_LEN + 1

typedef long long i64;
typedef unsigned long long u64;

int main(void) {
    u64 tc_count = 0;
    scanf("%llu", &tc_count);

    for (u64 r = 0; r < tc_count; r++) {
        u64 pairs = 0;

        u64 n = 0;
        scanf("%llu\n", &n);

        u64 nums_i = 1;
        u64 positive_nums[NUMS_LEN] = {0};
        u64 negative_nums[NUMS_LEN] = {0};

        // number digits 
        char str[STR_LEN] = {0};
        fgets(str, STR_LEN, stdin);
        str[strlen(str)-1] = '\0';

        for (char *s = str; ; s = NULL, nums_i++) {
            char *token = strtok(s, " ");
            if (token == NULL)
                break;
            u64 temp = strtoull(token, NULL, 10);
            if (temp >= nums_i) {
                if (positive_nums[temp-nums_i] > 0) {
                    pairs += positive_nums[temp-nums_i];
                }
                positive_nums[temp-nums_i]++;
            } else {
                if (negative_nums[nums_i-temp] > 0) {
                    pairs += negative_nums[nums_i-temp];
                }
                negative_nums[nums_i-temp]++;
            }
        }

        printf("%llu\n", pairs);
    }
}

