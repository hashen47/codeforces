#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		long long n, k;
		cin >> n >> k;

		vector<long long> positions(n*2, 0);
		vector<long long> numbers;

		string s;
		for (long long i = 0; i < n; i++) {
			cin >> s;
			int val = stoi(s);
			if (val >= k) continue;
			positions[val]++;
			numbers.push_back(val);
		}

		long long score = 0;
		for (size_t i = 0; i < numbers.size(); i++) {
			int val = k-numbers[i];
			if (val <= 0) continue;

			if (positions[val] > 0 && positions[numbers[i]] > 0) {
				if (val == numbers[i]) {
					if (positions[val] < 2) {
						continue;
					}
				}
				positions[val]--;
				positions[numbers[i]]--;
				score++;
			}
		}

		cout << score << "\n";
	}
}
