#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
		int length;
		cin >> length;

		int arr[length] = {0};

		int val = 0;
		for (int i = 0; i < length; i++) {
			if (i > length-i-1) break;
			arr[i] = ++val;
			if (i == length-i-1) break;
			arr[length-i-1] = ++val;
		}

		for (int i = 0; i < length; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}
