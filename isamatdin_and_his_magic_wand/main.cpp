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

	for (s64 t = 0; t < testcase_count; t++)
	{
		int vec_len;
		cin >> vec_len;

		int have_even_numbers = false;
		int have_odd_numbers  = false;

		vector<int> vec1(vec_len);
		int el;
		for (int i = 0; i < vec_len; i++)
		{
			cin >> el;

			if (! have_even_numbers && el % 2 == 0)
				have_even_numbers = true;
			if (! have_odd_numbers && el % 2 != 0)
				have_odd_numbers = true;

			vec1[i] = el; 
		}

		if (have_even_numbers && have_odd_numbers)
			sort(vec1.begin(), vec1.end());

		for (int el: vec1)
			cout << el << " ";
		cout << "\n";
	}
}
