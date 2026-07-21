#include <iostream>
#include <vector>
#include <algorithm>

typedef long long i64;

int main(void)
{
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++)
    {
        i64 n = 0;
        std::vector<i64> arr(7);

        for (size_t i = 0; i < 7; i++)
        {
            std::cin >> n;
            arr[i] = n;
        }

        std::sort(arr.begin(), arr.end());

        i64 total = 0;
        for (size_t i = 0; i < 6; i++)
        {
            total += -1 * arr[i];
        }

        std::cout << total + arr[6] << "\n";
    }
}
