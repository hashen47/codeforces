#include <iostream>

int main(void)
{
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++)
    {
        int x = 0;
        int y = 0;
        std::cin >> x >> y;

        if (x % y == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
