#include <iostream>
#include <algorithm> 

using namespace std;

int N, T[15], P[15], dp[15] = {0, };

int main(void) {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> T[i] >> P[i];

  cout << endl;

  for (int i = N - 1; i >= 0; --i) {
    cout << "i: " << i << " P[i] : " << P[i] << " T[i] :" << T[i] << endl;
    if (N - i < T[i]) {
      dp[i] = dp[i + 1]; // 마지막날까지 상담을 못끝내면 -> 직전 날짜까지의 최대값
    }
    else {
      dp[i] = max(dp[i + 1], P[i] + dp[T[i] + i]); 
      // max(직전 날짜까지의 최대값 vs 오늘 상담값 + 오늘 상담 일자 이후 날짜까지의 최대값)
    }
  }

  cout << "====" << endl;
  for (int i = 0; i < N; i++)
  {
    cout << dp[i] << endl;
  }

  cout << dp[0] << endl;

  return 0;
}