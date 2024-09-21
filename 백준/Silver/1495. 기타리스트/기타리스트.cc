#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S, M;
	cin >> N >> S >> M;

	set<int> dp[51];
	dp[0].insert(S);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		for (auto v : dp[i]) {
			int a = v + num;
			int b = v - num;
			if (a <= M)
				dp[i+1].insert(a);
			if (b >= 0)
				dp[i+1].insert(b);
		}
		if (dp[i + 1].size() == 0)
		{
			cout << -1;
			return 0;
		}
	}

	cout << *dp[N].rbegin();
}