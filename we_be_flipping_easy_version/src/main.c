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
        i64 c = 0;
        i64 indexes_i = 0;
        i64 indexes[N] = {0};
        bool is_positive = true; 

        // seperate by spaces
        for (char *str = line; ;str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;

            int number = strtol(token, NULL, 10);

            // handle the first number
            if (nums_i == 0) {
                is_positive = number > 0;
            } else {
                if (nums_i == n-1) {
                    if (is_positive) {
                        if (number < 0) {
                            is_positive = false;
                            indexes[indexes_i++] = nums_i-1;
                            c++;
                        } else {
                            indexes[indexes_i++] = nums_i;
                            c++;
                        }
                    } else {
                        if (number > 0) {
                            indexes[indexes_i++] = nums_i-1;
                            c++;
                            indexes[indexes_i++] = nums_i;
                            c++;
                        }
                    }
                } else {
                    if (is_positive) {
                        if (number < 0) {
                            is_positive = false;
                            indexes[indexes_i++] = nums_i-1;
                            c++;
                        }
                    } else  {
                        if (number > 0) {
                            is_positive = true;
                            indexes[indexes_i++] = nums_i-1;
                            c++;
                        }
                    }
                }
            }

            nums_i++;
        }

        printf("%lld\n", c);
        for (i64 i = indexes_i-1; i >= 0; i--)
            printf("%lld ", indexes[i]+1);
        if (indexes_i > 0)
            printf("\n");
    }
}
