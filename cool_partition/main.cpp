#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	size_t rounds;
	cin >> rounds;

	for (size_t r = 0; r < rounds; r++) {
		size_t length;
		cin >> length;

		int arr[length] = {0};
		int total = 0;
		map<int, int> m1, m2, m3;

		string s;
		for (size_t i = 0; i < length; i++) {
			cin >> s;
			arr[i] = stod(s);
		}

		m1[arr[0]] = 1;
		m2[arr[0]] = 1;

		for (size_t i = 0; i < length; i++) {
			int key = arr[i];

			if (m1.find(key) != m1.end()) {
				if (m2.find(key) != m2.end()) {
					m2.erase(key);
				}
			} else {
				m3[key] = 1;
			}

			if (m2.size() == 0) {
				total++;
				m1.merge(m3);
				m3.clear();
				m2 = m1;
			}
		}

		cout << total << "\n";
	}
}
