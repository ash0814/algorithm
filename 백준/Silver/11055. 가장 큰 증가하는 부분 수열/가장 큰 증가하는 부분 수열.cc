#include <iostream>

using namespace std;

int main()
{
	int N;
	int list[1001] = {0, };
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> list[i];
	int dp[1001] = {0, };
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		int max_sum = 0;
		for (int j = 1; j < i; j++) {
			if (list[i] > list[j]) {
				max_sum = max_sum > list[i] + dp[j] ? max_sum : list[i] + dp[j];
			}
		}
		dp[i] = max(max_sum, list[i]);
		res = res > dp[i] ? res : dp[i];
	}
	cout << res << endl;

}