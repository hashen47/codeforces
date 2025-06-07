#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// congratulations samishka ayya

	int rounds;
	cin >> rounds;


	for (int r = 0; r < rounds; r++) {
        vector<int> numbers;

        for (int i = 0; i < 5; i++) {
            if (i == 2) {
                numbers.push_back(0);
                continue;
            }

            string s;
            cin >> s;

            numbers.push_back(stod(s));
        }

		int left = 0;
		int right = 0;

		// find left
		numbers[2] = numbers[0] + numbers[1];
		left++;

		if (numbers[1] + numbers[2] == numbers[3]) left++;
		if (numbers[2] + numbers[3] == numbers[4]) left++;

		// find right
		numbers[2] = numbers[4] - numbers[3];
		right++;

		if (numbers[1] + numbers[2] == numbers[3]) right++;
		if (numbers[0] + numbers[1] == numbers[2]) right++;

		if (left >= right)
			cout << left << "\n";
		else
			cout << right << "\n";

	}
}
