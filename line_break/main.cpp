#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int n, m;
		cin >> n >> m;

		string s;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			cin >> s;
			int length = s.length();
			arr.push_back(length);
		}

		int total_length = 0;
		int word_count = 0;
		for (int i = 0; i < n; i++) {
			total_length += arr[i];
			if (total_length > m) break;
			word_count++;
		}

		cout << word_count << "\n";
	}
}
