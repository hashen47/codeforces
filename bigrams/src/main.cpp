#include <iostream>

int main(void)
{
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++)
    {
        int k = 0;
        std::cin >> k;

        bool can = false;
        int two_pair_count = 0;
        for (int i = 0; i < k; i++)
        {
            int temp = 0;
            std::cin >> temp;

            if (temp >= 3)
                can = true;
            else if (temp == 2)
                two_pair_count++;
        }

        if (can || two_pair_count >= 2)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
