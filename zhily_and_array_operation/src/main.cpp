#include <iostream>
#include <vector>

typedef long long i64;

int main(void)
{
    i64 tc_count = 0;
    std::cin >> tc_count;

    for (i64 t = 0; t < tc_count; t++)
    {
        i64 n = 0;
        std::cin >> n;

        std::vector<i64> arr(n);
        for (i64 i = 0; i < n; i++)
        {
            i64 temp = 0;
            std::cin >> temp;
            arr[i] = temp;
        }

        for (i64 i = n-1; i >= 0; i--)
        {
            if (i+1 >= n)
                continue;

            if (arr[i+1] > 0 && arr[i] + arr[i+1] > 0)
                arr[i] += arr[i+1];
        }

        i64 positive_num_count = 0;
        for (i64 i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                positive_num_count++;
        }

        std::cout << positive_num_count << "\n";
    }
}
