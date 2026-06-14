#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int tc_count = 0;
    scanf("%d", &tc_count);

    for (int r = 0; r < tc_count; r++) {
        int n, x, y, z;
        scanf("%d %d %d %d", &n, &x, &y, &z);
        // printf("n: %d, x: %d, y: %d, z: %d\n", n, x, y, z);

        int t1 = n / (x + y);
        if (n % (x + y) != 0)
            t1++;

        int t2 = (n - x * z) / (x + 10 * y);
        if ((n - x * z) % (x + 10 * y) != 0)
            t2++;
        t2 += z;

        printf("%d\n", t1 < t2 ? t1 : t2);
    }
}
