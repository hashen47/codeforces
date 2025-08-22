#include <bits/stdc++.h>

using namespace std;

typedef long long int s64; 
typedef unsigned long long int u64; 

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
    // freopen("tests.txt", "r", stdin);

	s64 testcase_count;
	cin >> testcase_count;

	for (s64 t = 0; t < testcase_count; t++) {
        unordered_map<u64, u64> m;

        u64 n;
        cin >> n;

        u64 x;
        for (u64 i = 0; i < n; i++) {
            cin >> x;
            if (!m.count(x)) m[x] = 1;
            else m[x]++;
        }

        u64 total = 0;

        for (auto it = m.begin(); it != m.end(); it++) {
            // cout << "key: " << it->first << ", value: " << it->second << "\n";
            total += it->second/2;
        }

        cout << total << "\n";
	}
}
