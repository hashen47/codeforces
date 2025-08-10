#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int testcase_count;
	cin >> testcase_count;

	for (int t = 0; t < testcase_count; t++) {
        unsigned long long x;
        cin >> x;

        unsigned long long smallest_digit = x % 10;
        while (x != 0) {
            unsigned long long remainder = x % 10; 
            if (remainder < smallest_digit) {
                smallest_digit = remainder;
            } 
            x /= 10;
        }

        cout << smallest_digit << "\n";
	}
}
