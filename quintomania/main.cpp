#include <bits/stdc++.h>

using namespace std;

typedef long long int s64; 

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
    // freopen("tests.txt", "r", stdin);

	s64 testcase_count;
	cin >> testcase_count;

	for (s64 t = 0; t < testcase_count; t++) {
        s64 n;
        cin >> n;

        vector<s64> notes(n);

        s64 x;
        for (s64 i = 0; i < n; i++) {
            cin >> x;
            notes[i] = x;
        }

        bool is_perfect = true;
        for (s64 i = 0; i < n-1; i++) {
            s64 diff = notes[i] - notes[i+1];
            if (! (diff == 5 || diff == 7 || diff == -5 || diff == -7))
                is_perfect = false;
        }

        cout << (is_perfect ? "YES" : "NO") << "\n";
	}
}
