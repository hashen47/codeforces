#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
	  	int length;
		bool is_possible = true;
		vector<int> clocks;

	  	cin >> length;

		string s;
		for (int i = 0; i < length; i++) {
			cin >> s;
			int val = stoi(s);

			if (val == 1) {
				is_possible = false;
			}
			clocks.push_back(val);
		}

		if (length % 2 != 0) {
			if (clocks[length/2] <= (length/2) * 2) {
				is_possible = false;
			}
		}

		if (! is_possible) {
			cout << "NO\n";
			continue;
		}

		for (int i = 0; i < length; i++) {
			if (i < length/2) {
				if (clocks[i] <= (length-1-i) * 2) {
					is_possible = false;
					break;
				}
			} else {
				if (clocks[i] <= i * 2) {
					is_possible = false;
					break;
				}
			}
		}

		if (is_possible) {
			cout << "YES\n";
			continue;
		}

		cout << "NO\n";
	}
}
