#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int testcase_count;
	cin >> testcase_count;

	for (int t = 0; t < testcase_count; t++) {
        u64 n, c; 
        vector<u64> nums;
        cin >> n >> c;

        u64 total_coins = 0; 

        for (u64 i = 0; i < n; i++) {
            u64 x;
            cin >> x;
            total_coins++;
            if (x <= c)
                nums.push_back(x);
        }

        sort(nums.begin(), nums.end(), greater<u64>());

        u64 mult = 1;

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] * mult <= c) {
                total_coins--;
                mult *= 2;
             }
        }

        cout << total_coins << "\n";
	}
}
