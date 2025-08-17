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
        s64 a, x, y;
        cin >> a >> x >> y;

        s64 arr[3] = {a, x, y};
        sort(arr, arr+3);

        if (a == arr[1]) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
	}
}
