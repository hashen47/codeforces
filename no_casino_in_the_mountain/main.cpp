#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int testcase_count;
	cin >> testcase_count;

	for (int t = 0; t < testcase_count; t++) {
        unsigned long n, k;
        cin >> n >> k;

        int x;
        unsigned long total_hikes = 0;
        unsigned long count = 0;
        for (unsigned long i = 0; i < n; i++) {
            cin >> x;
            if (x == 1) {
                count = 0;
                continue;
            }

            count++;

            if (count == k) {
                total_hikes++;
                count = -1;     // because he need at least one day break
            }
        }

        cout << total_hikes << "\n";
	}
}
