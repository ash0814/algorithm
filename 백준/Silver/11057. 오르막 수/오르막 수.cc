#include <iostream>

using namespace std;

int main()
{
	long long dp[1001][10] = {0, };
	int N;
	cin >> N;

	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 9; j++) {
			dp[1][j] = 1;
			if (i >> 1)
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++){
		sum += dp[N][i];
	}
	cout << sum % 10007 << '\n';
}