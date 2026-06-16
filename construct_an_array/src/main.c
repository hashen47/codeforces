#include <stdio.h>
#include <stdlib.h>

int main() {
    int tc_count = 0;
    scanf("%d", &tc_count);

    for (int r = 0; r < tc_count; r++) {
        int n = 0;
        scanf("%d", &n);
        for (int i = 1; i < 2*n; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    }
}
