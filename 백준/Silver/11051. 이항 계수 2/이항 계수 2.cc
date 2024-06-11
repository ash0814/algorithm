#include <iostream>

using namespace std;

int main()
{

	int N, K;

	scanf("%d %d", &N, &K);

	int dp[1001][1001] = {0, };
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
		}
		dp[i][i] = 1;
	}
	printf("%d", dp[N][K]);
}