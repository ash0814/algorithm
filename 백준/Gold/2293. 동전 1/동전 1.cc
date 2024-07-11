#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<int> coins;
  for (int i = 0; i < n; i++)
  {
    int coin;
    cin >> coin;
    coins.push_back(coin);
  }

  int dp[10001] = {
      0,
  };
  for (int i = 0; i < n; i++)
  {
    if (coins[i] > k)
      continue;
    dp[coins[i]]++;
    for (int j = coins[i]; j <= k; j++)
      dp[j] = dp[j] + dp[j - coins[i]];
  }
  cout << dp[k];
}