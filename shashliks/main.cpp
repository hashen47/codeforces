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
        s64 k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;

        if (a > k && b > k) {
            cout << 0 << "\n";
            continue;
        }

        s64 total = 0;

        if ((x < y && k >= a) || b > k) {
            s64 a_meal_count = (k-a)/x;
            k -= a_meal_count * x + x;
            a_meal_count++;
            total += a_meal_count;

            if (k >= b) {
                s64 b_meal_count = (k-b)/y;
                k = b_meal_count * y + y;
                b_meal_count++;
                total += b_meal_count;
            }
        } else {
            s64 b_meal_count = (k-b)/y;
            k -= b_meal_count * y + y;
            b_meal_count++;
            total += b_meal_count;

            if (k >= a) {
                s64 a_meal_count = (k-a)/x;
                k = a_meal_count * x + x;
                a_meal_count++;
                total += a_meal_count;
            }
        }

        cout << total << "\n";
	}
}
