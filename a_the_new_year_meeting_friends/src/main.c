#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int64_t i64;

int compare(const void *n1, const void *n2) {
    return *(i64*)n2 - *(i64*)n1;
}

int main() {
    i64 nums[3] = {0};
    scanf("%ld %ld %ld", &nums[0], &nums[1], &nums[2]);
    qsort(nums, 3, sizeof(i64), compare);
    // printf("%ld %ld %ld", nums[0], nums[1], nums[2]);
    printf("%ld\n", nums[0] - nums[2]);
}
