#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;

	int list[1001] = {0, };
	int dp[1001] = {0, };
	for (int i = 1; i <= N; i++)
	{
		cin >> list[i];
		dp[i] = list[i];
	}

	for (int i = 2; i <= N; i++) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int k = 0; k <= i; k++) {
			pq.push(dp[k] + dp[i - k]);
		}
		dp[i] = pq.top();
	}

	cout << dp[N];
}