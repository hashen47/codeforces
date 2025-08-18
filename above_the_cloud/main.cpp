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
        string s;

        cin >> n;
        cin >> s;

        if (n == 3) {
            if (s[0] == s[1] || s[2] == s[1]) cout << "Yes\n";
            else cout << "No\n";
            continue;
        }

        bool is_ok = false;
        for (s64 i = 0; i < n-2; i++) {
            for (s64 j = i+1; j < n-1; j++) {
                if (s[i] == s[j]) {
                    is_ok = true;
                    goto end;
                }
            } 
        }

        for (s64 i = n-1; i > 1; i--) {
            for (s64 j = i-1; j > 0; j--) {
                if (s[i] == s[j]) {
                    is_ok = true;
                    goto end;
                }
            } 
        }

    end:
        if (is_ok) cout << "Yes\n";
        else cout << "No\n";
	}
}
