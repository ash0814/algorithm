#include <iostream>
#include <algorithm> 
#include <vector>
#include <set>

using namespace std;

int N, T[1500001], P[1500001], dp[1500001] = {0, };

int main(void) {  
  cin >> N;
  for (int i = 0; i < N; i++) cin >> T[i] >> P[i];

  for (int i = N - 1; i >= 0; --i) {
    if (N - i < T[i]) {
      dp[i] = dp[i + 1];
    }
    else {
      dp[i] = max(dp[i + 1], P[i] + dp[T[i] + i]);
    }
  }

  cout << dp[0];

  return 0;
}