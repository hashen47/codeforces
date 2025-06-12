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

		vector<int> arr(length);
		for (int i = 0; i < length; i++) {
			string s;
			cin >> s;
			arr[i] = stod(s);
		}

		int top = -1;
		for (int i = 0; i < length; i++) {
			if (arr[i] != 0) break;
			top++;
		}

		int bottom = length;
		for (int i = length-1; i >= 0; i--) {
			if (arr[i] != 0) break;
			bottom--;
		}

		if (top == length-1 && bottom == 0) {
			cout << 0 << "\n";
			continue;
		}

		bool is_found_zero = false;
		for (int i = top+1; i < bottom; i++) {
			if (arr[i] == 0) {
				is_found_zero = true;
				break;
			}
		}

		cout << (is_found_zero ? 2 : 1) << "\n";
	}
}
