#include <bits/stdc++.h>

using namespace std;

typedef long long int s64; 

int main(void)
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	
    // freopen("tests.txt", "r", stdin);

	s64 testcase_count;
	cin >> testcase_count;

	for (s64 r = 0; r < testcase_count; r++)
	{
		int container1[123] = {0};      // 123 is the decimal value to 'z' 
		int container2[123] = {0};      // 123 is the decimal value to 'z' 
		bool can_rearrange = true;
		int t_length;
		string s;
		string t;

		cin >> t_length;
		cin >> s;
		cin >> t;

		for (int i = 0; i < t_length; i++)
			container1[(int)s[i]]++;

		for (int i = 0; i < t_length; i++)
			container2[(int)t[i]]++;

		for (int i = 0; i < t_length; i++)
		{
			if (container1[(int)s[i]] != container2[(int)s[i]])
				can_rearrange = false;
		}

		cout << (can_rearrange ? "Yes" : "No") << "\n";
	}
}
