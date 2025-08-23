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
        s64 x;
        cin >> x;

        if (x % 2 == 0) cout << "Sakurako\n";
        else cout << "Kosuke\n";
	}
}
