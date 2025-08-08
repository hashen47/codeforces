#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int testcase_count;
	cin >> testcase_count;

	for (int t = 0; t < testcase_count; t++) {
        unsigned long long n;
        vector<unsigned long long> nums;

        cin >> n;

        unsigned long long x;
        for (unsigned long long i = 0; i < n; i++) {
            cin >> x;
            nums.push_back(x);
        }

        // sort vector in ascending order
        sort(nums.begin(), nums.end());

        unsigned long long sum = 0;
        for (unsigned long long i = 0; i < n; i++)
            sum += nums[i] == 0 ? 1 : nums[i];

        cout << sum << "\n";
	}
}
