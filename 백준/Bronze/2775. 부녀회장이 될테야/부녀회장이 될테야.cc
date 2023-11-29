#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int dp[15][15] = {
      0,
  };

  for (int i = 1; i <= 14; i++)
  {
    dp[0][i] = i;
  }

  for (int i = 1; i <= 14; i++)
  {
    dp[i][0] = 0;
    for (int j = 1; j <= 14; j++)
    {
      dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    }
  }

  int T;
  cin >> T;
  while (T--)
  {
    int k, n;
    cin >> k >> n;
    cout << dp[k][n] << endl;
  }
}