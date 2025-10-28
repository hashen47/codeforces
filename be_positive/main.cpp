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
		int length = 0;
		int element = 0;
		int zero_number_count = 0;
		int negative_number_count = 0;
		int smallest_negative_number = 0;

		cin >> length;
		for (int i = 0; i < length; i++)
		{
			cin >> element;
			if (element == 0)
			{
				zero_number_count++;
				continue;
			}

			if (element < 0)
			{
				if (smallest_negative_number > element)
					smallest_negative_number = element;
				negative_number_count++;
			}
		}

		int total_operations = zero_number_count;

		if (negative_number_count % 2 != 0)
			total_operations += (smallest_negative_number * -1) + 1;

		cout << total_operations << "\n";
	}
}
