#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int length;
		map<char, int> m;
		string s;

		cin >> length;
		cin >> s;

		for (int i = 0; i < length; i++) {
			char key = s[i];
			if (m.find(key) != m.end()) {
				m[key]++;
			} else {
				m[key] = 1;
			}
		}

		char min_char = s[0];
		char max_char = s[0];
		int max = 0;
		int min = 11;

		for (auto el: m) {
			if (max <= el.second) {
				max_char = el.first;
				max = el.second;
			}

			if (min > el.second) {
				min_char = el.first;
				min = el.second;
			}
		}

		bool done = false;
		for (int i = 0; i < length; i++) {
			char ch = s[i];
			if (ch == min_char && !done) {
				cout << max_char;
				done = true;
			} else {
				cout << ch;
			}
		}

		cout << "\n";
	}
}
