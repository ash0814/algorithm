#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int dp[1001][3] = {0, };
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);

		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r;
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g;
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b;
	}

	int res = min(dp[N][0], min(dp[N][1], dp[N][2]));
	printf("%d\n", res);
}