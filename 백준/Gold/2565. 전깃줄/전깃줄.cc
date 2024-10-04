#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 가장 긴 증가하는 부분수열
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> list;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		list.push_back({a, b});
	}
	sort(list.begin(), list.end());

	vector<int> S;
	for (auto n : list) {
		S.push_back(n.second);
	}

	int dp[501] = {0, };
	int lcs = 0;
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (S[j] < S[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			} else {
				dp[i] = max(dp[i], 1);
			}
		}
		lcs = max(dp[i], lcs);
	}

	cout << N - lcs;
}