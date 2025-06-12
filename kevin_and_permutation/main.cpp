#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int n, k;
		cin >> n >> k;

		if (k == 1) {
			for (int i = 1; i <= n; i++) {
				cout << i << " ";
			}
			cout << "\n";
			continue;
		}

		int limit = n/k;
		int x = 1;
		int y = 0;

		for (int i = limit+1; i <= n; i++) {
			y++;
			cout << i << " ";
			if (y == k-1 && x <= limit) {
				cout << x << " ";
				x++;
				y = 0;
			}
		}

		cout << "\n";
	}
}
