#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int m,a,b,c;
		cin >> m >> a >> b >> c;

		int remain = 0;
		int total = 0;
		if (m >= a) {
			remain = m-a;
			total += a;
		} else {
			total += m;
		}

		if (m >= b) {
			remain += m-b;
			total += b;
		} else {
			total += m;
		}

		if (remain >= c) {
			total += c;
		} else {
			total += remain;
		}

		cout << total << "\n";
	}
}
