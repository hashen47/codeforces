#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		string s;
		cin >> s;

		// cout << s << "\n";

		int total = 0;
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == '1') total++;
		}

		cout << total << "\n";
	}
}
