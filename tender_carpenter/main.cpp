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

		int arr[length] = {0};
		for (int i = 0; i < length; i++) {
			string s;
			cin >> s;
			arr[i] = stod(s);
		}

		bool is_possible = false;
		for (int i = 0; i < length-1; i++) {
			int a = arr[i];
			int b = arr[i+1];

			if (a >= b) {
				if (a/2 < b) {
					is_possible = true;
					break;
				}
			} else {
				if (b/2 < a) {
					is_possible = true;
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
