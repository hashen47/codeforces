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

		sort(arr.begin(), arr.end(), greater<int>());

		int total = 0;
		int add_coin_count = 0;
		for (int i = 0; i < n; i++) {
			total += arr[i];
			if (total == k) {
				break;
			} else if (total > k) {
				add_coin_count = k - (total - arr[i]);
				break;
			}
		}

		if (total < k ) {
			add_coin_count = k-total;
		}

		cout << add_coin_count << "\n";
	}
}
