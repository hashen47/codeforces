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

		for (int i = s.length()-1; i >= 0; i--) {
			if (s[i] == 'p') {
				cout << 'q';
			} else if (s[i] == 'q') {
				cout << 'p';
			} else {
				cout << s[i];
			}
		}

		cout << "\n";
	}
}
