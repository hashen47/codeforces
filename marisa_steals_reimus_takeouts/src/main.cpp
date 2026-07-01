#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int tc_count = 0;
    cin >> tc_count;

    for (int t = 0; t < tc_count; t++) {
        int n = 0;
        cin >> n;

        int total = 0;

        vector<int> arr(0);
        vector<bool> positions(0);
        for (auto i = 0; i < n; i++) {
            int x = 0;
            cin >> x;
            if (x == 0) {
                total++;
            } else {
                arr.push_back(x);
                positions.push_back(true);
            }
        }

        // find 1,2 pairs
        if (!arr.empty()) {
            for (size_t i = 0; i < arr.size()-1; i++) {
                if (!positions[i])
                    continue;
                for (size_t j = i+1; j < arr.size(); j++) {
                    if (!positions[j])
                        continue;
                    if (arr[i] + arr[j] == 3) {
                        total++;
                        positions[i] = false;
                        positions[j] = false;
                        break;
                    }
                }
            }
        }

        // find other triple pairs
        int sum = 0;
        for (size_t i = 0; i < arr.size(); i++) {
            if (! positions[i])
                continue;
            sum += arr[i];
            if (sum % 3 == 0) {
                total++;
                sum = 0;
            }
        }

        cout << total << "\n";
    }
}
