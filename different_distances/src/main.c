#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 200

int main(void) {
    int tc_count = 0;
    scanf("%d", &tc_count);

    for (int r = 0; r < tc_count; r++) {
        int n = 0;
        scanf("%d", &n);

        if (n % 2 == 0) {
            for (int i = 0; i < n; i += 2) {
                printf("%d %d %d %d %d %d %d %d ", i+1, i+2, i+2, i+1, i+2, i+1, i+1, i+2);
            }
        } else {
            printf("1 1 2 1 2 3 1 3 2 2 3 3 ");

            for (int i = 3; i < n; i += 2) {
                printf("%d %d %d %d %d %d %d %d ", i+1, i+2, i+2, i+1, i+2, i+1, i+1, i+2);
            }
        }

        printf("\n");
    }
}
