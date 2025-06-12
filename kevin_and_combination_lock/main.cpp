#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int n;
		cin >> n;

		if (n % 33 == 0) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
}
