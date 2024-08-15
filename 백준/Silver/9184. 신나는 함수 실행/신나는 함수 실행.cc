#include <iostream>

using namespace std;

int dp[21][21][21] = {0, };

int solution(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (a > 20 || b > 20 || c > 20) {
		return solution(20, 20, 20);
	}

	if (dp[a][b][c] > 0)
		return dp[a][b][c];

	if (a < b && b < c) {
		dp[a][b][c] = solution(a, b, c-1) + solution(a, b-1, c-1) - solution(a, b-1, c);
		return dp[a][b][c];
	}

	dp[a][b][c] = solution(a-1, b, c) + solution(a-1, b-1, c) + solution(a-1, b, c-1) - solution(a-1, b-1, c-1);
	return dp[a][b][c];

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << solution(a, b, c) << '\n';
	}
}