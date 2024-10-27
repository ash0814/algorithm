#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
	int n;
	cin >> n;

	int sticker[2][100001] = {0, };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sticker[i][j];
		}
	}

	int dp[2][100001] = {0, };
	dp[0][0] = sticker[0][0];
	dp[1][0] = sticker[1][0];
	if (n < 2) {
		if (dp[0][0] > dp[1][0])
			cout << dp[0][0] << '\n';
		else
			cout << dp[1][0] << '\n';
		return ;
	}

	dp[0][1] = dp[1][0] + sticker[0][1];
	dp[1][1] = dp[0][0] + sticker[1][1];

	int max_score = max(dp[0][1], dp[1][1]);

	for (int i = 2; i < n; i++) {
		dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i];
		dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sticker[1][i];
		max_score = max(max_score, max(dp[0][i], dp[1][i]));
	}

	cout << max_score << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solution();
	}
}