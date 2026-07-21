#include <iostream>
#include <vector>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int tc_count = 0;
    std::cin >> tc_count;

    for (int t = 0; t < tc_count; t++)
    {
        size_t n = 0;
        std::cin >> n;

        n *= 3;
        size_t i = 0;

        std::vector<size_t>arr(n);

        size_t temp = n;
        while (i < temp)
        {
            for (size_t j = 0; j < 2; j++)
            {
                arr[i+j] = n--;
            }
            i += 3;
        }

        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i] != 0)
                printf("%zu ", arr[i]);
            else
                printf("%zu ", n--);
        }
        printf("\n");
    }
}
