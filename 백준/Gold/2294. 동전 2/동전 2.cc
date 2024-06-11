#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	set<int> coins;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		coins.insert(c);
	}

	int dp[10001] = {0, };

	for (int i = 0; i <= k; i++)
		dp[i] = 987654321;

	for (int i = 1; i <= k; i++) {
		if (coins.find(i) != coins.end()) {
			dp[i] = 1;
		}
		else {
			for (int j = 1; j <= i; j++) {
				dp[i] = min(dp[i], dp[i-j] + dp[j]);
			}
		}

	}

	if (dp[k] == 987654321)
		cout << -1;
	else
		cout << dp[k];

}