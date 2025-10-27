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

	int capable_problem_count = 0;

	for (s64 t = 0; t < testcase_count; t++)
	{
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		if (n1 + n2 + n3 >= 2)
			capable_problem_count += 1;
	}

	cout << capable_problem_count << "\n";
}
