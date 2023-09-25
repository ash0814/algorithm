#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  long long dp[40];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int n = 1; n < 36; n++)
  {
    for (int i = 0; i < n; i++)
    {
      dp[n] += dp[i] * dp[n - 1 - i];
    }
  }

  int N;
  cin >> N;
  cout << dp[N] << endl;
}