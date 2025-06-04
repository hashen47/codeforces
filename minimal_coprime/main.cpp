#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int x = 0; x < rounds; x++) {
		int l, r;

		cin >> l >> r;

		// cout << l << ", " << r << "\n";

		if (l == r && l == 1) {
			cout << 1 << "\n";
			continue;
		}

		cout << r - l << "\n";
	}
}
