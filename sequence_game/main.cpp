#include <bits/stdc++.h>

using namespace std;

typedef long long int s64; 

int main(void) {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
    // freopen("tests.txt", "r", stdin);

	s64 testcase_count;
	cin >> testcase_count;

	for (s64 t = 0; t < testcase_count; t++) {
		int len;
		cin >> len;

		vector<int> numbers(len);
		for (int i = 0; i < len; i++) {
			int x;
			cin >> x;
			numbers[i] = x;
		}

		int target;
		cin >> target;

		bool has_small_n = false;
		bool has_big_n   = false;

		for (int i = 0; i < len; i++) {
			if (numbers[i] >= target)
				has_big_n   = true;
			if (numbers[i] <= target)
				has_small_n = true;
		}

		if (has_small_n && has_big_n) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
