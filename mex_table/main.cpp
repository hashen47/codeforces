#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int a, b;

		string s;
		cin >> s;
		a = stod(s);

		cin >> s;
		b = stod(s);

		if (a == 0 && b == 0) {
			cout << 2 << "\n";
			continue;
		}

		cout << (a >= b ? a : b) + 1 << "\n";
	}
}
