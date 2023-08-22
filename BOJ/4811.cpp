#include <iostream>
#include <vector>
using namespace std;

long long dp[32][32];

int main()
{
  dp[0][0] = 1;
  for (int i = 0; i <= 30; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      for (int k = 0; k <= j; k++)
        dp[i][j] += dp[i - 1][k];
    }
  }

  vector<int> input;
  while (1)
  {
    int n;
    cin >> n;
    if (n == 0)
      break;
    input.push_back(n);
  }

  // for (int i = 0; i <= 10; i++)
  // {
  //   for (int j = 0; j <= 10; j++)
  //   {
  //     printf("%5lld ", dp[i][j]);
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < input.size(); i++)
    cout << dp[input[i]][input[i]] << endl;
}
