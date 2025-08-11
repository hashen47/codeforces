#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int testcase_count;
	cin >> testcase_count;

	for (int t = 0; t < testcase_count; t++) {
        unsigned long long a, b, k;
        cin >> a >> b >> k;

        if (a <= k && b <= k) {
            cout << 1 << "\n";
            continue;
        }

        unsigned long long val = gcd(a, b);
        cout << ((a/val <= k && b/val <= k) ? 1 : 2) << "\n";
	}
}
