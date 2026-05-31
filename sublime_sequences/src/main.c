#include <stdio.h>

int main() {
    int testcase_count;

    scanf("%d", &testcase_count);

    for (int i = 0; i < testcase_count; i++) {
        int x, n;
        scanf("%d %d", &x, &n);
        printf("%d\n", (n % 2 == 0) ? 0 : x);
    }
}
