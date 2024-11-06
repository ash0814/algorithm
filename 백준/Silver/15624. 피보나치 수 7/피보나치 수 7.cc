#include <iostream>

using namespace std;

int main()
{
	int mod = 1000000007;
	long long dp[1000001] = {0, };

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	int N;
	cin >> N;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i-1] + dp[i - 2]) % mod;
	}
	cout << dp[N];
}