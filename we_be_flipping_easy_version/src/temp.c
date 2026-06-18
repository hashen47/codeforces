#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 2 * 10 * 10 * 10 * 10 * 10
#define MAX_DIGIT_LEN 10
#define STR_LEN N + N * MAX_DIGIT_LEN + 1

typedef long long i64;

int main(void) {
    i64 tc_count = 0;
    scanf("%lld", &tc_count);

    for (i64 r = 0; r < tc_count; r++) {
        i64 n = 0;
        scanf("%lld\n", &n);

        // read the line
        char line[STR_LEN] = {0};
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        i64 nums_i = 0;
        i64 nums[N] = {0};

        // seperate by spaces
        for (char *str = line; ;str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;

            // store the number in the array
            nums[nums_i++] = strtol(token, NULL, 10);
        }

        i64 c = 0;
        i64 indexes_i = 0;
        i64 indexes[N] = {0};
        bool is_positive = true; 
        for (i64 i = nums_i-1; i >= 0; i--) {
            if (is_positive && nums[i] > 0) {
                c++;
                indexes[indexes_i++] = i;
                is_positive = !is_positive;
                continue;
            }

            if (!is_positive && nums[i] < 0) {
                c++;
                indexes[indexes_i++] = i;
                is_positive = !is_positive;
                continue;
            }
        }

        // print the solution
        printf("%lld\n", c);
        for (i64 i = 0; i < indexes_i; i++)
            printf("%lld ", indexes[i]+1);
        printf("\n");
    }
}
