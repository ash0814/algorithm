#include <iostream>
using namespace std;

int main()
{
  int dp[50][2];

  dp[0][0] = 1;
  dp[0][1] = 0;
  for (int i = 1; i < 46; i++)
  {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
  }
  int k;
  cin >> k;
  cout << dp[k][0] << " " << dp[k][1] << endl;
}