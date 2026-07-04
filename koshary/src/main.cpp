#include <iostream>

int main(void) {
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;

        if (a % 2 == 0 || b % 2 == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
