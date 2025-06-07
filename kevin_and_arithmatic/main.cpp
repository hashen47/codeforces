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

        string s;
        bool isOneEven = false;
        long long oddCount = 0;
        for (int i = 0; i < length; i++) {
            cin >> s;

            long long val = stoi(s);

            if (val % 2 == 0) {
                isOneEven = true;
            } else {
                oddCount++;
            }
        }

        if (isOneEven) {
            cout << oddCount + 1 << "\n";
        } else {
            cout << oddCount-1 << "\n";
        }
	}
}
