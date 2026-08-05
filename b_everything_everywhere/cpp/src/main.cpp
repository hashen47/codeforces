#include <iostream>
#include <vector>
#include <numeric>

typedef unsigned long long u64;
typedef long long i64;

int main(void)
{
	u64 tc_count = 0;
	std::cin >> tc_count;

	for (u64 t = 0; t < tc_count; t++)
	{
		// code goes here
        u64 n = 0;
        std::cin >> n;

        u64 total_sub_array_count = 0;

        std::vector<u64> numbers(n);
        for (size_t i = 0; i < n; i++) {
            std::cin >> numbers[i];
        } 

        for (size_t i = 0; i < numbers.size()-1; i++) {
            /*
            if (
                (numbers[i+1] % 2 == 0 && numbers[i] == numbers[i+1]/2) ||
                (numbers[i] % 2 == 0 && numbers[i+1] == numbers[i]/2) ||
                (numbers[i] + 1 == numbers[i+1]) ||
                (numbers[i+1] + 1 == numbers[i])
            ) {
                total_sub_array_count++;
            }
            */

            if (numbers[i] > numbers[i+1]) {
                if (std::gcd(numbers[i], numbers[i+1]) == numbers[i] - numbers[i+1]) {
                    total_sub_array_count++;
                }
            } else {
                if (std::gcd(numbers[i], numbers[i+1]) == numbers[i+1] - numbers[i]) {
                    total_sub_array_count++;
                }
            }
        }

        std::cout << total_sub_array_count << "\n";
	}
}
