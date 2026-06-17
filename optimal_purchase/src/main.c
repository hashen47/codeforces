#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

int main(void) {
    u64 tc_count = 0;
    scanf("%llu", &tc_count);

    for (u64 r = 0; r < tc_count; r++) {
        u64 n = 0;
        u64 a = 0;
        u64 b = 0;

        scanf("%llu %llu %llu", &n, &a, &b);

        u64 groups = n / 3;
        u64 remain = n % 3;

        u64 min_price = (n - remain) * a;

        if (groups * b < min_price) {
            min_price = groups * b;
        }

        if (b < remain * a) {
            min_price += b;
        } else {
            min_price += remain * a;
        }

        printf("%llu\n", min_price);
    }
}
