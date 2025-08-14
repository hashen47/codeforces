#include <bits/stdc++.h>

using namespace std;

typedef long long int s64;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
    // freopen("tests.txt", "r", stdin);
	
	int testcase_count;
	cin >> testcase_count;

	for (int t = 0; t < testcase_count; t++) {
        s64 n;
        cin >> n;

        bool is_alice_turn = true;
        unordered_set<s64> set;
        s64 prev_val = 0;

        bool is_choose = false;
        for (s64 i = 0; i < n; i++) {
            is_choose = false;

            if (is_alice_turn) {
                if (auto search = set.find(i); search == set.end()) {
                    prev_val = i;
                    is_choose = true;
                    set.insert(i);
                    is_alice_turn = !is_alice_turn;
                }
            } else {
                for (s64 j = i; j < n; j++) {
                    if ((prev_val+i)%4 == 3) {
                        prev_val = i;
                        is_choose = true;
                        set.insert(i);
                        is_alice_turn = !is_alice_turn;
                        break;
                    }
                }
            }
        }

        if (is_alice_turn && is_choose) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
	}
}
