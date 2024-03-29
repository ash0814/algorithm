#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		int N = 0;
		cin >> N;

		long long sum = 0, flow = 0;

		while (N--)
		{
			long long num;
			cin >> num;
			long long before = sum;
			sum = sum + num;
			if (num > 0 && before > 0 && sum < 0)
				flow++;
			if (num < 0 && before < 0 && sum > 0)
				flow--;
		}
		if (flow == 0)
		{
			if (sum == 0)
				cout << '0' << '\n';
			else if (sum > 0)
				cout << '+' << '\n';
			else
				cout << '-' << '\n';
		}
		else
		{
			if (flow > 0)
				cout << '+' << '\n';
			else
				cout << '-' << '\n';
		}
	}
}