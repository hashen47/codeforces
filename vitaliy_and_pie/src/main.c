#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN 2 * 10 * 10 * 10 * 10 * 10
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// A - Z = 65 - 90
// a - z = 97 - 122
int main() {
    int n = 0;
    int keys_should_buy = 0;
    char s[STRLEN] = {0};
    int keys[26] = {0};

    while (fgets((char*)&s, STRLEN, stdin)) {
        if (n == 0) {
            n = strtod((const char*)&s, NULL);
            memset((void*)&s, 0, STRLEN);
        }
    }

    size_t len = strlen(s);
    for (size_t i = 0; i < len-1; i++) {
        char ch = s[i]; 

        // key
        if (i % 2 == 0) {
            keys[ch - 97]++;
            continue;
        }

        // door
        if (keys[ch - 65] >= 1) {
            keys[ch - 65]--;
            continue;
        }

        keys_should_buy++;
    }

    printf("%d\n", keys_should_buy);
}
