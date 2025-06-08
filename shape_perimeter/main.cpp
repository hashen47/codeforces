#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	int rounds;
	cin >> rounds;

	for (int r = 0; r < rounds; r++) {
    	int n_of_operations, side_length;
    	cin >> n_of_operations >> side_length;

		int min_x = 101;
		int min_y = 101;
		int max_x = 0;
		int max_y = 0;
		int prev_x = 0, prev_y = 0;
        for (int i = 0; i < n_of_operations; i++) {
			int x, y;
			cin >> x >> y;
			if (x+prev_x < min_x) min_x = x+prev_x;
			if (y+prev_y < min_y) min_y = y+prev_y;
			if (x+prev_x > max_x) max_x = x+prev_x;
			if (y+prev_y > max_y) max_y = y+prev_y;
			prev_x += x;
			prev_y += y;
        }

		// cout << "min_x: " << min_x << ", max_x: " << max_y << ", min_y: " << min_y << ", max_y: " << max_y << "\n";
		cout << ((max_x+side_length-min_x) * 2) + ((max_y+side_length-min_y) * 2) << "\n";
	}
}
