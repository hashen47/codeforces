#include <bits/stdc++.h>

using namespace std;

typedef long long int s64; 

int main(void)
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
    // freopen("tests.txt", "r", stdin);
	vector<int> scores(3);
	cin >> scores[0] >> scores[1] >> scores[2];

	sort(scores.begin(), scores.end());

	if (scores[2] - scores[0] >= 10)
		cout << "check again\n";
	else
		cout << "final " << scores[1] << "\n";
}
