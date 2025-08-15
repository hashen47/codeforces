#include <bits/stdc++.h>

using namespace std;

typedef long long int s64;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
    // freopen("tests.txt", "r", stdin);

	int testcase_count;
	cin >> testcase_count;

	for (int t = 0; t < testcase_count; t++) {
        s64 n, s;
        cin >> n >> s;

        vector<s64> nums;

        for (s64 i = 0; i < n; i++) {
            s64 x;
            cin >> x;
            nums.push_back(x);
        }

        sort(nums.begin(), nums.end());

        if (n == 1 && s == nums[0]) {
            cout << 0 << "\n";
            continue;
        }

        if (s <= nums[0]) {
            cout << (nums[n-1]-s) << "\n";
            continue;
        }

        if (s >= nums[n-1]) {
            cout << (s-nums[0]) << "\n";
            continue;
        }

        s64 left = s - nums[0];
        s64 right = nums[n-1] - s;

        if (left < right) {
            cout << (left*2 + right) << "\n";
        } else {
            cout << (right*2 + left) << "\n";
        }
	}
}
