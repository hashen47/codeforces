#include <iostream>
#include <vector>

typedef unsigned long long u64;

int main(void) {
    u64 tc_count = 0;
    std::cin >> tc_count;

    for (u64 t = 0; t < tc_count; t++) {
        u64 x = 0;
        u64 y = 0;
        std::cin >> x >> y;

        // std::cout << "x: " << x << ", y: " << y << "\n";
        u64 n = (y/x)-1;
        if (n == 1)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
}
