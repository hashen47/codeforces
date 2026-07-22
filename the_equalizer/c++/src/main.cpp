#include <iostream>

typedef long long i64;

int main(void)
{
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++)
    {
        i64 n = 0;
        i64 k = 0;
        i64 total = 0;

        std::cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            i64 temp = 0;
            std::cin >> temp;
            total += temp;
        }

        if (total % 2 == 1 || (n * k) % 2 == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
