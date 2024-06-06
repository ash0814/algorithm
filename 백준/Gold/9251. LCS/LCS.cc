#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	int dp[1001][1001] = {0, };

	A = '0' + A;
	B = '0' + B;
	for (int i = 0; i < B.length(); i++) {
		for (int j = 0; j < A.length(); j++) {
			if (i == 0 || j == 0)
        		dp[i][j] = 0;
			else if (A[j] == B[i])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << dp[B.size()-1][A.size()-1];
}