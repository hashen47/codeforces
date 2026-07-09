#include <iostream>

int main(void) {
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++) {
        std::string s;
        std::cin >> s;

        int equal_pairs  = 0;
        for (int i = 0; i < (int)s.size()-1; i++) {
            if (s[i] == s[i+1])
                equal_pairs++;
        }

        std::cout << (equal_pairs <= 2 ? "YES" : "NO") << "\n";
    }
}
