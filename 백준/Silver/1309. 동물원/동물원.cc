#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int mod = 9901;

	int dp[100001][3] = {0, };
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1] [2]) % mod;
	}

	int res = (dp[N][0] + dp[N][1] + dp[N][2]) % mod;
	cout << res;
}