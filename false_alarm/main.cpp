#include <bits/stdc++.h>

using namespace std;

int main() {
	size_t rounds;
	cin >> rounds;

	for (size_t r = 0; r < rounds; r++) {
		int length, interval;
		cin >> length >> interval;

		bool is_possible = true;
		int arr[length] = {0};

		for (int i = 0; i < length; i++) {
			string s;
			cin >> s;
			arr[i] = stod(s);
		}

		for (int i = 0; i < length; i++) {
			if (arr[i] == 1) {
				for (int j = i+interval; j < length; j++) {
					if (arr[j] == 1) {
						is_possible = false;
						break;
					}
				}
			}

			if (!is_possible) {
				break;
			}
		}

		cout << (is_possible ? "YES" : "NO") << "\n";
	}
}
