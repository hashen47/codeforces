#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long u64;
typedef long long i64;

int main(void)
{
    u64 tc_count = 0;
    std::cin >> tc_count;

    for (u64 t = 0; t < tc_count; t++)
    {
       	// code goes here
        std::vector<u64> arr(3);
        std::cin >> arr[0] >> arr[1] >> arr[2];
        std::sort(arr.begin(), arr.end());

        if (arr[0] + arr[1] < arr[2])
        {
            std::cout << arr[1] << "\n";
        }
        else {
            std::cout << arr[2] - arr[0] << "\n";
        }
    }
}
