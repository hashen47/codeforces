#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10*10*10*10*10
#define DIGIT_LEN 10 
#define STR_LEN N + DIGIT_LEN * N + 1

typedef unsigned long long u64;

int main(void) {
    u64 tc_count = 0;
    scanf("%llu\n", &tc_count);

    for (u64 t = 0; t < tc_count; t++) {
        u64 a_i = 0;
        u64 a[N] = {0};
        u64 b_i = 0;
        u64 b[N] = {0};

        // n
        u64 n = 0;
        scanf("%llu\n", &n);

        // store a array elements
        char line[STR_LEN] = {0};
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        for (char *str = line; ;str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;
            a[a_i++] = strtoull(token, NULL, 10);
        }

        memset(line, 0, STR_LEN);

        // store b array elements
        fgets(line, STR_LEN, stdin);
        line[strlen(line)-1] = '\0';

        for (char *str = line; ;str = NULL) {
            char *token = strtok(str, " ");
            if (token == NULL)
                break;
            b[b_i++] = strtoull(token, NULL, 10);
        }

        a_i = 0; // store the a array max
        b_i = 0; // store the b array sum
        for (u64 i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                b_i += a[i];
                if (b[i] > a_i)
                    a_i = b[i];
            } else {
                if (a[i] > a_i)
                    a_i = a[i];
                b_i += b[i];
            }
        }

        // print the total
        printf("%llu\n", a_i + b_i);
    }
}
