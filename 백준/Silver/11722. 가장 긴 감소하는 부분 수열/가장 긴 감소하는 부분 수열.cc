#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int list[1001] = {0, };
	int dp[1001] = {0, };

	for (int i = 1; i <= N; i++)
		cin >> list[i];

	int res = 0;
	for (int i = 1; i <= N; i++) {
		int len = 0;
		for (int j = 1; j < i; j++) {
			if (list[j] > list[i])
				len = len > dp[j] + 1 ? len : dp[j] + 1;
		}
		dp[i] = len > 1 ? len : 1;
		res = res > dp[i] ? res : dp[i];
	}

	cout << res << endl;
}