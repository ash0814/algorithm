#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mod = 1000000009;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	long long dp[1000001] = {0, };
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	for (int i = 5; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
	}
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
}