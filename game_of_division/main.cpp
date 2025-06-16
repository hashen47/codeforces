#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int n, k;
		cin >> n >> k;

		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			arr[i] = stod(s);
		}

		bool is_possible = true;
		int answer = arr[0];
		for (int i = 0; i < n; i++) {
			is_possible = true;
			answer = i;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if ((arr[i] - arr[j]) % k == 0) {
					is_possible = false;
					break;
				}
			}
			if (is_possible) break;
		}

		if (is_possible) {
			cout << "YES\n";
			cout << (answer+1) << "\n";
			continue;
		}
		cout << "NO\n";
	}
}
