#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int dp[100001] = {0, };
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		int minNum = INT_MAX;
		for (int j = 1; j * j <= i; j++)
		{
			int num = i - j * j;
			minNum = minNum > dp[num] + 1 ? dp[num] + 1 : minNum;
		}
		dp[i] = minNum;
	}

	cout << dp[N];
	return 0;
}