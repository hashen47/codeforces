#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define DIGIT_LIMIT 10

typedef int64_t i64;
typedef uint64_t u64;

typedef enum {
    NOT_SET,
    EQUAL,
    ASC,
    OTHER,
} NumState;

int main() {
    u64 testcase_count = 0;
    scanf("%zu\n", &testcase_count);

    for (u64 i = 0; i < testcase_count; i++) {
        u64 n = 0;
        u64 k = 0;
        scanf("%zu %zu\n", &n, &k);
        // printf("n: %zu, k: %zu\n", n, k);

        NumState state = NOT_SET;

        char ch;
        int chars_i = 0;
        n = 0;
        char chars[DIGIT_LIMIT] = {0};
        bool stop = false;
        u64 temp = 0;
        while(!stop) {
            ch = fgetc(stdin);
            if (ch == EOF)
                break;
            switch (ch) {
                case ' ':
                    chars_i = 0;
                    temp = (u64)strtoll(chars, NULL, 10);
                    for (int i = 0; i < DIGIT_LIMIT; i++) {
                        chars[i] = 0; 
                    }
                    // printf("tc: %zu, %zu\n", i, temp);
                    if (n != 0 && state != OTHER) {
                        if (n < temp) {
                            state = ASC;
                        } else if (n == temp) {
                            if (state != ASC)
                                state = EQUAL;
                        } else {
                            state = OTHER;
                        }
                    }
                    n = temp;
                    break;
                case '\n':
                    temp = (u64)strtoll(chars, NULL, 10);
                    // printf("tc: %zu, %zu\n", i, temp);
                    if (n != 0 && state != OTHER) {
                        if (n < temp) {
                            state = ASC;
                        } else if (n == temp) {
                            if (state != ASC)
                                state = EQUAL;
                        } else {
                            state = OTHER;
                        }
                    }
                    n = temp;
                    stop = true;
                    break;
                default:
                    chars[chars_i++] = ch;
                    break;
            }
        }

        // printf("state: %d\n", state);

        printf("%s\n", (k > 1 || state != OTHER) ? "YES" : "NO");
    }
}

