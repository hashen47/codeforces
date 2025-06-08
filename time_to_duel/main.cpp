#include <bits/stdc++.h>

using namespace std;

int main() {
	size_t rounds;
	cin >> rounds;

	for (size_t r = 0; r < rounds; r++) {
		size_t length;
		cin >> length;

		int arr[length] = {0};
		string s;
		for (size_t i = 0; i < length; i++) {
			cin >> s;
			arr[i] = stod(s);
		}

		bool is_liar = false;
		size_t zero_count = 0;
		size_t one_count = 0;

		for (size_t i = 0; i < length; i++) {
			if (arr[i] == 0) {
				zero_count++;
				if (zero_count > 1) {
					is_liar = true;
					break;
				}
			} else {
				zero_count = 0;
			}
		}

		zero_count = 0;
		one_count = 0;
		if (!is_liar) {
			for (size_t i = 0; i < length; i++) {
				if (arr[i] == 1) {
					one_count++;
				} else {
					zero_count++;
					one_count = 0;
				}
			}

			if (zero_count == 0 && one_count > 1) {
				is_liar = true;
			}
		}

		if (is_liar) {
			cout << "YES\n";
			continue;
		}

		cout << "NO\n";
	}
}
