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
        u64 total_price = 0;
        map<u64, u64> brand_prices_m;

        u64 n, k, b, c;
        cin >> n >> k;

        for (u64 i = 0; i < k; i++) {
            cin >> b >> c;

            if (brand_prices_m.count(b) == 0) {
                brand_prices_m[b] = c;
            } else {
                brand_prices_m[b] += c;
            }
        }

        if (n == k || n > k) {
            for (auto it = brand_prices_m.begin(); it != brand_prices_m.end(); it++)
                total_price += it->second;
        } else {
            vector<u64> prices ;
            for (auto it = brand_prices_m.begin(); it != brand_prices_m.end(); it++)
                prices.push_back(it->second);

            brand_prices_m.clear();                                     // clear the map, not needed anymore
            sort(prices.begin(), prices.end(), greater<u64>());

            for (size_t i = 0; i < min((size_t)n, prices.size()); i++)  // if we replace min with n, out of bound error occur 
                total_price += prices[i];
        }

        cout << total_price << "\n";
	}
}
