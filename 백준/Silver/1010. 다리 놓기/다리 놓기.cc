#include <iostream>
#include <vector>

using namespace std;

int main()
{

  // 파스칼의 삼각형
  //  1
  //  1 1
  //  1 2 1
  //  1 3 3 1
  //  1 4 6 4 1

  long long dp[31][31] = {
      0,
  };
  dp[0][0] = 1;
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= 30; i++)
  {
    dp[i][0] = 1;
    for (int j = 1; j < i + 1; j++)
    {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }

  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;
    cout << dp[m][n] << endl;
  }
}