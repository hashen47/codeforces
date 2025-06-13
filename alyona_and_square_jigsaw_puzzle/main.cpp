#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int length;
		cin >> length;

		vector<int> parts(length);
		for (int i = 0; i < length; i++) {
	  		string s;
			cin >> s;
			parts[i] = stod(s);
		}

		long long happy_days = 0;
		long long start_val = 1;
		long long total_parts = 0;
		long long full = 1;
		for (int i = 0; i < length; i++) {
			total_parts += (long long) parts[i];

			while (true) {
				if (full >= total_parts) break;
				start_val += 2;
				full = start_val * start_val;
			}

			if (full == total_parts)
				happy_days++;
		}

		cout << happy_days << "\n";
	}
}
