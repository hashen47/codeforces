#include <iostream>

#define MOD 676767677

typedef unsigned long long u64;

int main(void) {
    u64 tc_count = 0;
    std::cin >> tc_count;

    for (u64 t = 0; t < tc_count; t++) {
        u64 n = 0;
        std::cin >> n;

        u64 total = 0;
        u64 prev = 0;
        u64 mult = 0;
        for (u64 i = 0; i < n; i++) {
            u64 temp = 0;
            std::cin >> temp;

            if (i == 0) {
                if (temp != 1) {
                    total += (temp % MOD);
                } else {
                    mult = 1;
                }
                prev = temp;
                continue;
            }

            if (temp >= prev) {
                if (prev == 1) {
                    mult = (temp % MOD);
                } else {
                    total += (mult % MOD);
                    mult = temp;
                }
                prev = temp;
                continue;
            }

            total += (mult % MOD);

            if (temp == 1) {
                mult = 1;
            } else {
                mult = 0;
                total += (temp % MOD);
            }

            prev = temp;
        }

        if (mult > 0) {
            total += mult;
        }

        std::cout << total << "\n";
    }
}
