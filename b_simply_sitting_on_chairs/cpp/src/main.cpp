#include <iostream>
#include <vector>
#include <unordered_map>

typedef unsigned long long u64;
typedef long long i64;

int main(void)
{
	u64 tc_count = 0;
	std::cin >> tc_count;

	for (u64 t = 0; t < tc_count; t++)
	{
        u64 n = 0;
        std::cin >> n;
        std::vector<u64> permutation(n);
        std::unordered_map<u64, bool> sitted_chairs;

        for (u64 i = 0; i < n; i++)
        {
            std::cin >> permutation[i];
        }

        u64 total_sitted_chairs_count = 0;
        for (u64 i = 0; i < n; i++)
        {
            if (permutation[i] <= i+1)
            {
                auto it = sitted_chairs.find(i+1);
                if (it != sitted_chairs.end())
                {
                    break;
                }
                else
                {
                    sitted_chairs[permutation[i]] = true;
                    total_sitted_chairs_count++;
                }
            }
            else if (permutation[i] >= n)
            {
                auto it = sitted_chairs.find(i+1);
                if (it != sitted_chairs.end())
                {
                    break;
                }
                else
                {
                    sitted_chairs[permutation[i]] = true;
                    total_sitted_chairs_count++;
                }
            }
        }

        std::cout << total_sitted_chairs_count << "\n";
	}
}
