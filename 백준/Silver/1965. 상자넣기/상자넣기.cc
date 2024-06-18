#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int list[1001] = {0, };

	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	int dp[1001] = {0, };
	int res = -1;

	for (int i = 1; i <= N; i++) {
		priority_queue<int> pq;
		for (int j = i - 1; j >= 0; j--) {
			if (list[j] < list[i]) {
				pq.push(dp[j]);
			}
		}
		dp[i] = pq.top() + 1;
		if (dp[i] > res)
			res = dp[i];
	}


	cout << res;
}