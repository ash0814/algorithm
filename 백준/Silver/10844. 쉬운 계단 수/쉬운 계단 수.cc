#include <iostream>

using namespace std;

int main()
{
	int N;
	int mod = 1000000000;
	cin >> N;
	long long dp[101][11] = {0, };

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++){
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = dp[i-1][1] % mod;
			else if (j == 9)
				dp[i][j] = dp[i-1][8] % mod;
			else
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
		}
	}
	long long sum = 0;
	for (auto n: dp[N]){
		sum += n;
	}
	cout << sum % mod << endl;
}