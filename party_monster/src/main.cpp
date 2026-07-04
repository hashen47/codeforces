#include <iostream>

int main(void) {
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++) {
        int n = 0;
        std::cin >> n;

        int opening_bracket_count = 0;
        int closing_bracket_count = 0;

        for (int i = 0; i < n; i++) {
            char bracket = '\0';
            std::cin >> bracket;

            if (bracket == '(')
                opening_bracket_count++;
            else
                closing_bracket_count++;
        }

        std::cout << ((opening_bracket_count == closing_bracket_count) ? "YES\n" : "NO\n");
    }
}
