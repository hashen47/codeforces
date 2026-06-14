#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;
typedef long long i64;

int main(void) {
    u64 tc_count = 0;
    scanf("%llu", &tc_count);

    for (u64 r = 0; r < tc_count; r++) {
        u64 n = 0;
        scanf("%llu", &n);

        if (n == 10)
            printf("-1\n");
        else {
            u64 remainder = n % 12;
            if (remainder == 10) {
                printf("22 %llu\n", n - 22);
            } else {
                printf("%llu %llu\n", remainder, n - remainder);
            }
        }
    }
}
