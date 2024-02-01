#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> list;
	cin >> N;
	while (N--)
	{
		int num;
		cin >> num;
		list.push_back(num);
	}
	int dp[1000001] = {0};
	dp[0] = list[0];
	int ret = dp[0];
	for (int i = 1; i < list.size(); i++)
	{
		dp[i] = max(dp[i-1] + list[i], list[i]);
		ret = max(ret, dp[i]);
	}
	cout << ret << '\n';
}