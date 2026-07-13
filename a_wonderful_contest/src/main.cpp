#include <iostream>

int main(void)
{
    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++)
    {
        int n = 0;
        std::cin >> n;

        int temp = 0;
        bool is_wonderful = false;
        for (int i = 0; i < n; i++)
        {
            std::cin >> temp;
            if (temp == 100)
                is_wonderful = true;
        }

        std::cout << (is_wonderful ? "Yes\n" : "No\n");
    }
}
