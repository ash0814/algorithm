#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int dp[1000001];
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= N; i++)
  {
    dp[i] = (dp[i - 1] + (2 * dp[i - 2])) % 10007;
  }
  cout << dp[N] << endl;
}
