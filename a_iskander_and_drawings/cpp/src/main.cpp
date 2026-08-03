
#include <iostream>

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

        char *line = (char*)malloc(n * sizeof(char));
        std::cin >> line;

        u64 longestLineLength = 0;
        u64 lineLength = 0;
        for (u64 i = 0; i < n; i++) {
            if (line[i] == '*') {
                if (longestLineLength < lineLength) {
                    longestLineLength = lineLength;
                }
                lineLength = 0;
            } else {
                lineLength++;
                // std::cout << "tc_count: " << tc_count << ", lineLength: " << lineLength << "\n";
            }
        }

        if (longestLineLength < lineLength) {
            longestLineLength = lineLength;
        }
        
        std::cout << (longestLineLength / 2) + (longestLineLength % 2) << "\n";
        free(line);
	}
}
