#include <bits/stdc++.h>

using namespace std;

typedef long long int s64; 

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
    // freopen("tests.txt", "r", stdin);

	s64 testcase_count;
	cin >> testcase_count;

	for (s64 t = 0; t < testcase_count; t++)
	{
	  	s64 team_count;
		cin >> team_count;

		s64 won_group_match_count  = team_count -1;
		s64 lost_group_match_count = won_group_match_count -1;
		s64 total_match_count      = won_group_match_count + lost_group_match_count + 1; // add extra one for final match

		cout << total_match_count << "\n"; // 2n - 2 
	}
}
