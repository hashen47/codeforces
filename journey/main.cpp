#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;

		long long sum = a+b+c; 
		long long ans =  (n/sum)*3;
		long long remainder = n%sum;

		if (remainder > 0) {
			ans++;
			long long arr[] = {a, b, c};
			long long temp = arr[0];
			for (int i = 1; i < 3; i++) {
				if (remainder > temp) {
					temp += arr[i];
					ans++;
					continue;
				}
				break;
			}
		}

		cout << ans << "\n";
	}
}
