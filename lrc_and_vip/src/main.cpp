#include <iostream>
#include <vector>

int main(void)
{
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++)
    {
        int n = 0;
        std::cin >> n;

        int max = 0;
        int prev = 0;
        bool is_all_equal = true;
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
            if (arr[i] > max)
                max = arr[i];

            if (i == 0)
                prev = arr[i];
            else if (arr[i] != prev)
                is_all_equal = false;
        }

        if (is_all_equal)
        {
            std::cout << "No\n";
            continue;
        }

        std::cout << "Yes\n";
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == max)
                std::cout << "2 ";
            else
                std::cout << "1 ";
        }
        std::cout << "\n";
    }
}
