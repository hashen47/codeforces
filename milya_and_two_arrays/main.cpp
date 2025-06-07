#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int length;
		vector<int> a_arr;
		vector<int> b_arr;
		unordered_set<int> a_set;
		unordered_set<int> b_set;
		bool is_all_same_a = true;
		bool is_all_same_b = true;

		cin >> length;

		for (int i = 0; i < length; i++) {
			string s;
			cin >> s;

			int n = stod(s); 
			a_set.insert(n);
			a_arr.push_back(n);

			if (i != 0) {
				if (a_arr[i-1] != n) is_all_same_a = false; 
			}
		}

		for (int i = 0; i < length; i++) {
			string s;
			cin >> s;

			int n = stod(s); 
			b_set.insert(n);
			b_arr.push_back(n);

			if (i != 0) {
				if (b_arr[i-1] != n) is_all_same_b = false; 
			}
		}

		if (
			(is_all_same_a && (is_all_same_b || b_set.size() < 3)) ||
			(is_all_same_b && (is_all_same_a || a_set.size() < 3))
		) {
			cout << "NO" << "\n";
			continue;
		}

		cout << "YES" << "\n";
	}
}
