#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int count;
		cin >> count;

		unordered_map<int, int> marble_counts;
		for (int i = 0; i < count; i++) {
			string x;
			cin >> x;
			int val = stod(x);

			if (marble_counts.find(val) == marble_counts.end()) {
				marble_counts.insert({val, 1});
			} else {
				marble_counts[val]++;
			}
		}

		int one_count = 0;
		int other_count = 0;
		for (const auto& pair: marble_counts) {
			// cout << "first: " << pair.first << ", second: " << pair.second << "\n"; 
			if (pair.second > 1) {
				other_count++;
			} else {
				one_count++;
			}
		}

		int total = 0;
		int val = one_count/2;
		total += val * 2;

		if (one_count % 2 != 0) {
			total += 2;
		}

		total += other_count;

		cout << total << "\n";
	}
}
