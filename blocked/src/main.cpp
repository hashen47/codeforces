#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main(void)
{
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++)
    {
        int n = 0;
        std::cin >> n;

        std::vector<int> arr(n);
        std::unordered_map<int, int> m;
        bool can = true;
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
            auto it = m.find(arr[i]);

            if (it == m.end())
            {
                m.insert({arr[i], 1});
            }
            else
            {
                can = false;
                int temp = 0;
                for (int j = i+1; j < n; j++)
                    std::cin >> temp;
                break;
            }
        }

        if (can)
        {
            std::sort(arr.begin(), arr.end(), std::greater<int>());
            for (auto n: arr)
                std::cout << n << " ";
            std::cout << "\n";
        }
        else
        {
            std::cout << "-1\n";
        }
    }
}
