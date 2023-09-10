#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void)
{
  int x;
  cin >> x;

  int dp[x];
  int before[x];
  memset(dp, 0, sizeof(dp));
  memset(before, 0, sizeof(before));
  dp[1] = 0;
  for (int i = 2; i <= x; i++)
  {
    dp[i] = dp[i - 1] + 1;
    before[i] = i - 1;
    if (i % 2 == 0)
    {
      if (dp[i] > dp[i / 2] + 1)
      {
        dp[i] = dp[i / 2] + 1;
        before[i] = i / 2;
      }
    }
    if (i % 3 == 0)
    {
      if (dp[i] > dp[i / 3] + 1)
      {
        dp[i] = dp[i / 3] + 1;
        before[i] = i / 3;
      }
    }
  }
  cout << dp[x] << endl;

  while (x)
  {
    cout << x << " ";
    x = before[x];
  }
  return 0;
}