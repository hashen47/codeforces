#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
	int testcase_count;
	cin >> testcase_count;

	for (int t = 0; t < testcase_count; t++) {
        string s;
        cin >> s;

        string N_str = "";
        string F_str = "";
        string T_str = "";

        string other_str = "";

        for (size_t i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case 'F':
                    F_str += s[i];
                    break;
                case 'T':
                    T_str += s[i];
                    break;
                case 'N':
                    N_str += s[i];
                    break;
                default:
                    other_str += s[i];
                    break;
            }
        }

        cout << T_str << N_str << F_str << other_str << "\n";
	}
}
