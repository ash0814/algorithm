#include <iostream>

using namespace std;

int main(void)
{
  long long N;
  cin >> N;
  long long dp[92][92];

  dp[1][0] = 0;
  dp[1][1] = 1;
  for (long long i = 2; i <= 90; i++)
  {
    dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
    dp[i][1] = dp[i - 1][0];
   }
  cout << dp[N][0] + dp[N][1] << endl;
}