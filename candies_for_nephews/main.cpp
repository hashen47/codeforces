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

	int n = 0;
	for (s64 t = 0; t < testcase_count; t++)
	{
		cin >> n;
		printf("%d\n",  n % 3 == 0 ? 0 : 3 - (n % 3));
	}
}
