#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int rounds;
	cin >> rounds;

	for (int i = 0; i < rounds; i++) {
		int length;
		string line;

		cin >> length;
		cin >> line;

		int total = 0; 
		bool isOne = false;
		bool isZero = false;

		for (int i = length-1; i >= 0; i--) {
			if (line[i] == '1') isOne = true;

			if (line[i] == '0') { 
				if (isOne) {
					if (isZero)
						total += 2;
					else
						total++;
				}

				isZero = true;
				isOne = false;
			}
		}

		if (isOne) {
			if (isZero)
				total += 2;
			else
				total++;
		}

		cout << total << "\n";
	}
}
