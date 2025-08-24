#include <bits/stdc++.h>

using namespace std;

typedef long long s64; 
typedef unsigned long long u64; 

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
    // freopen("tests.txt", "r", stdin);

	s64 testcase_count;
	cin >> testcase_count;

	for (s64 ti = 0; ti < testcase_count; ti++) {
        string s, t;
        cin >> s;
        cin >> t;

        u64 min_length = min(s.size(), t.size());
        u64 max_length = max(s.size(), t.size());
        u64 equal_char_length = 0;
        u64 total_seconds = 0;

        for (size_t i = 0; i < min_length; i++) {
            if (s[i] == t[i]) equal_char_length++;
            else break;
        }

        if (equal_char_length > 0) {
            total_seconds += equal_char_length;                                                   // first screen append
            total_seconds++;                                                                      // replace the second screen with first screen
            total_seconds += (max_length - equal_char_length) + (min_length - equal_char_length); // fill both screens (both words remain parts)
        } else {
            total_seconds += s.size() + t.size();                                                 // both words length
        }

        cout << total_seconds << "\n";
	}
}
