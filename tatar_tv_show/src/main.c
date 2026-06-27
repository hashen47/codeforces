#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DIGIT_LEN 6
#define MAX_N_LEN 2 * 10 * 10 * 10 * 10 * 10
#define STR_LEN MAX_N_LEN * MAX_DIGIT_LEN + 1

typedef unsigned long long u64;

int main(void) {
    int tc_count = 0;
    scanf("%d\n", &tc_count);

    for (int t = 0; t < tc_count; t++) {
        char line[STR_LEN] = {0};
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        int nums_i = 0;
        u64 nums[2] = {0}; // {n,k}

        for (char *str = line; ; str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;
            nums[nums_i++] = strtoull(token, NULL, 10);
        }

        memset(line, 0, strlen(line));
        fgets(line, nums[0]+2, stdin);
        line[nums[0]+1] = '\0';

        bool can_win = true;
        u64 index = 0;
        while (index < nums[0]) {
            if (line[index] == '0') {
                index++;
                continue;
            }

            if (index + nums[1] >= nums[0]) {
                can_win = false;
                break;
            }

            line[index] = '0';
            if (line[index + nums[1]] == '0') {
                line[index + nums[1]] = '1';
            } else {
                line[index + nums[1]] = '0';
            }

            index++;
        }

        if (! can_win) {
            printf("NO\n");
            continue;
        }

        if (line[nums[0]-1] == '0') {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
