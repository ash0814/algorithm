#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> list;
	while (N--)
	{
		int W, V;
		cin >> W >> V;
		list.push_back({W, V});
	}

	int dp[100001] = {0, };

	for (auto item: list) {
		for (int i = K; i >= item.first; i--) {
			dp[i] = max(dp[i], dp[i - item.first] + item.second);
		}
	}

	cout << dp[K];
}