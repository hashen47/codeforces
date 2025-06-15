#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		long long coin;
		cin >> coin;

		if (coin <= 3) {
			cout << 1 << "\n";
			continue;
		}

		long long total = 0;
		while (true) {
			if (total == 0) {
				total += 2;
			} else {
				total *= 2;
			}

			long long next_coin_value = coin/4;
			if (next_coin_value <= 3) {
				break;
			}

			coin = next_coin_value;
		}

		cout << total << "\n";
	}
}
