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
		i64 n;
		i64 c;
		i64 k;

        std::cin >> n >> c >> k;
        std::vector<i64> healths(n);

        for (size_t i = 0; i < (size_t)n; i++)
        {
            std::cin >> healths[i];
        }

        std::sort(healths.begin(), healths.end());

        for (auto health: healths)
        {
            if (c == health)
            {
                c += health;
            }
            else if (c > health)
            {
                if (k >= c - health)
                {
                    k -= (c - health);
                    c *= 2;
                }
                else if (k > 0)
                {
                    c += (health + k);
                    k = 0;
                }
                else
                {
                    c += health;
                }
            }
        }

        std::cout << c << "\n";
	}
}
