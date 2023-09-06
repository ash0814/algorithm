#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int list[20002];
int dp[2002][2002];
int N, M;

int main()
{

  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  vector<int> answer;
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    int c;
    cin >> c;
    list[i] = c;
  }
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= N; i++)
  {
    dp[i][i] = 1;
    if (i + 1 <= N && list[i] == list[i + 1])
      dp[i][i + 1] = 1;
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = i + 2; j <= N; j++)
    {
      if (list[i] == list[j] && dp[i + 1][j - 1])
        dp[i][j] = 1;
    }
  }

  // printDp();

  cin >> M;
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    // answer.push_back(dp[a][b]);
    cout << dp[a][b] << '\n';
  }

  // for (int i = 0; i < answer.size(); i++)
  //   cout << answer[i] << '\n';
  return 0;
}