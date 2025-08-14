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
        s64 n, k;
        size_t j;
        cin >> n >> j >> k;
        j--; // because index started with zero (problem start with one)

        vector<s64> nums;

        for (s64 i = 0; i < n; i++) {
            s64 x;
            cin >> x;
            nums.push_back(x);
        }

        if (k > 1) {
            cout << "YES\n";
            continue;
        }

        s64 greater_count = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            if (i == j) continue;
            if (nums[i] > nums[j]) greater_count++;
        }

        if (greater_count > 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
	}
}
