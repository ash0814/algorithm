#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	int list[1001] = {0, };

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> list[i];
	}

	int dp[1001] = {0, };
	dp[0] = 0;
	int max = 0;

	for (int i = 1; i <= N; i++)
	{
		priority_queue<int> s;
		for (int j = i-1; j >= 0; j--)
		{
			if (list[j] < list[i])
				s.push(dp[j]);
		}
		dp[i] = s.top() + 1;
		max = dp[i] > max ? dp[i] : max;
	}
	cout << max << endl;
}