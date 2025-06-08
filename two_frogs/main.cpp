#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int n,a,b;

		cin >> n >> a >> b;

		if (a > b) {
			int diff = (a-b)-1;
			if (diff % 2 == 0) {
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			continue;
		}

		int diff = (b-a)-1;
		if (diff % 2 == 0) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
	}
}
