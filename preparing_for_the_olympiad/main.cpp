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

		int a_arr[length] = {0};
		int b_arr[length] = {0};

	  	string s;
		for (int i = 0; i < length; i++) {
	  		cin >> s;
			a_arr[i] = stod(s);
		}

		for (int i = 0; i < length; i++) {
	  		cin >> s;
			b_arr[i] = stod(s);
		}

		int ans = a_arr[length-1];
		for (int i = 0; i < length-1; i++) {
			int diff = a_arr[i] - b_arr[i+1];
			if (diff > 0) {
				ans += diff;
			}
		}

		cout << ans << "\n";
	}
}
