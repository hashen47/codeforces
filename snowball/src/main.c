#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT_COUNT 10
#define MAX_N 2 * 10 * 10 * 10 * 10 * 10

int main(void) {
    int tc_count = 0;
    scanf("%d", &tc_count);

    for (int t = 0; t < tc_count; t++) {
        int n = 0;
        scanf("%d", &n);

        // allocate memory
        int divisible_by_6_nums_i = 0;
        int *divisible_by_6_nums = malloc(sizeof(int) * n);

        int only_divisible_by_2_nums_i = 0;
        int *only_divisible_by_2_nums = malloc(sizeof(int) * n);

        int only_divisible_by_3_nums_i = 0;
        int *only_divisible_by_3_nums = malloc(sizeof(int) * n);

        int non_divisible_nums_i = 0;
        int *non_divisible_nums = malloc(sizeof(int) * n);

        // remove extra new line from the stdin
        while (getchar() != '\n');

        int container_i = 0;
        char container[MAX_DIGIT_COUNT + 1] = {0};
        char ch = '\0';
        while ((ch = getchar()) != '\n') {
            if (ch == ' ') {
                int x = strtol(container, NULL, 10);
                if (x % 2 == 0) {
                    if (x % 3 == 0)
                        divisible_by_6_nums[divisible_by_6_nums_i++] = x;
                    else
                        only_divisible_by_2_nums[only_divisible_by_2_nums_i++] = x;
                } else {
                    if (x % 3 == 0)
                        only_divisible_by_3_nums[only_divisible_by_3_nums_i++] = x;
                    else
                        non_divisible_nums[non_divisible_nums_i++] = x;
                }
                container_i = 0;
                memset(container, 0, MAX_DIGIT_COUNT + 1);
            } else {
                container[container_i++] = ch;
            }
        }

        // store the last number
        int x = strtol(container, NULL, 10);
        if (x % 2 == 0) {
            if (x % 3 == 0)
                divisible_by_6_nums[divisible_by_6_nums_i++] = x;
            else
                only_divisible_by_2_nums[only_divisible_by_2_nums_i++] = x;
        } else {
            if (x % 3 == 0)
                only_divisible_by_3_nums[only_divisible_by_3_nums_i++] = x;
            else
                non_divisible_nums[non_divisible_nums_i++] = x;
        }

        // print divisible by 6 nums
        for (int i = 0; i < divisible_by_6_nums_i; i++)
            printf("%d ", divisible_by_6_nums[i]);

        // print only divisible by 2 nums
        for (int i = 0; i < only_divisible_by_2_nums_i; i++)
            printf("%d ", only_divisible_by_2_nums[i]);

        // print non divisible nums
        for (int i = 0; i < non_divisible_nums_i; i++)
            printf("%d ", non_divisible_nums[i]);

        // print only divisible by 3 nums
        for (int i = 0; i < only_divisible_by_3_nums_i; i++)
            printf("%d ", only_divisible_by_3_nums[i]);

        printf("\n");

        free(divisible_by_6_nums);
        free(only_divisible_by_2_nums);
        free(only_divisible_by_3_nums);
        free(non_divisible_nums);
    }
}
