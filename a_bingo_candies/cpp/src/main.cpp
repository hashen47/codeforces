#include <iostream>
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

        std::unordered_map<u64, u64> numbers_with_count;
        for (u64 i = 0; i < n*n; i++) {
            u64 number = 0;
            std::cin >> number;

            auto it = numbers_with_count.find(number);
            if (it != numbers_with_count.end()) {
                numbers_with_count[number]++;
            } else {
                numbers_with_count[number] = 1;
            }
        }

        bool is_able_to_arrange = true;
        for (const auto& [number, count] : numbers_with_count) {
            if (count > n*(n-1)) {
                is_able_to_arrange = false;
                break;
            }
        }

        if (is_able_to_arrange) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
	}
}
