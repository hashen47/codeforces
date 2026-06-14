#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 200

void find_solution(int limit);
void _find_solution(
    bool *is_solution_found,
    int *solution,
    int n,
    bool diffs[N][N],
    int *last_pos,
    int *counts,
    int index
);

int main(void) {
    int tc_count = 0;
    scanf("%d", &tc_count);

    for (int r = 0; r < tc_count; r++) {
        int n = 0;
        scanf("%d", &n);

        find_solution(n);
    }
}

void find_solution(int n) {
    bool is_solution_found = false;
    bool diffs[N][N] = {0};
    int counts[N] = {0};
    int last_pos[N] = {0};
    int solution[N] = {0};

    for (int i = 0; i < n; i++) {
        last_pos[i] = -1;
    }

    for (int i = 0; i < 4*n; i++) {
        solution[i] = -1;
    }

    _find_solution(
        &is_solution_found,
        solution,
        n,
        diffs,
        last_pos,
        counts,
        0
    );
}

void _find_solution(
    bool *is_solution_found,
    int *solution,
    int n,
    bool diffs[N][N],
    int *last_pos,
    int *counts,
    int index
) {
    if (*is_solution_found)
        return;

    if (index == 4*n) {
        *is_solution_found = true;
        for (int i = 0; i < 4*n; i++) {
            if (i == 4*n-1) {
                printf("%d\n", solution[i]+1);
            } else {
                printf("%d ", solution[i]+1);
            }
        }
        // printf("solution is found\n");
        return;
    }

    for (int j = 0; j < n; j++) {
        if (*is_solution_found)
            break;

        if (counts[j] == 4)
            continue;

        if (last_pos[j] == -1) {
            // set value
            last_pos[j] = index;
            counts[j]++;
            solution[index] = j;

            _find_solution(
                is_solution_found,
                solution,
                n,
                diffs,
                last_pos,
                counts,
                index+1
            );

            // reset values
            last_pos[j] = -1;
            counts[j]--;
            solution[index] = -1;

            continue;
        }

        int diff = index - last_pos[j];

        if (! diffs[j][diff]) {
            // set values
            diffs[j][diff] = true;
            int prev_last_pos = last_pos[j];
            last_pos[j] = index; 
            counts[j]++;
            solution[index] = j;

            _find_solution(
                is_solution_found,
                solution,
                n,
                diffs,
                last_pos,
                counts,
                index+1
            );

            // reset values
            diffs[j][diff] = false;
            last_pos[j] = prev_last_pos;
            counts[j]--;
            solution[index] = -1;
        }
    }
}
