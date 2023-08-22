#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

#define T_MAX 1000 + 1 
#define W_MAX 30 + 1
#define NAMU_POSI 2 + 1
// #pragma warning(disable:4996)

vector<int> jadoo_time;
int T, W;
int dp[T_MAX][W_MAX][NAMU_POSI] = { 0 };
 
int main() {
    ios::sync_with_stdio(false);
    cin >> T >> W;
    jadoo_time.resize(T + 1, 0);
    for (int t_idx = 1; t_idx <= T; t_idx++) 
        cin >> jadoo_time.at(t_idx);
 
    // dp 초기화 
    if (jadoo_time.at(1) == 2)
        dp[1][1][jadoo_time.at(1)] = 1;
    else 
        dp[1][0][jadoo_time.at(1)] = 1;
 
    // W는 0번 부터 사용하고 T는 1번부터 사용한다. 
    // 시간을 기준으로 변경한 횟수를 갱신한다. 
    for (int t_idx = 2; t_idx <= T; t_idx++) {
        for (int w_idx = 0; w_idx <= W && w_idx < t_idx; w_idx++) {
            // 자두가 시간 t에 1번 나무에 있으면 
            // 이전 위치가 2번일 때의 값에다가 w_idx+1 인 인덱스 
            if (jadoo_time.at(t_idx) == 1) {
                dp[t_idx][w_idx][1] = max({ dp[t_idx][w_idx][1], dp[t_idx - 1][w_idx][1] + 1 });
                if (w_idx < W && w_idx < t_idx - 1)
                    dp[t_idx][w_idx + 1][1] = max({ dp[t_idx][w_idx + 1][1], dp[t_idx - 1][w_idx][2] + 1 });
 
                dp[t_idx][w_idx][2] = max({ dp[t_idx][w_idx][2], dp[t_idx - 1][w_idx][2] });
            }
            // 2번에 있으면 
            else {
                dp[t_idx][w_idx][2] = max({ dp[t_idx][w_idx][2], dp[t_idx - 1][w_idx][2] + 1 });
                if (w_idx < W && w_idx < t_idx - 1)
                    dp[t_idx][w_idx + 1][2] = max({ dp[t_idx][w_idx + 1][2], dp[t_idx - 1][w_idx][1] + 1 });
 
                dp[t_idx][w_idx][1] = max({ dp[t_idx][w_idx][1], dp[t_idx - 1][w_idx][1] });
            }
        }
    }
 
    int answer = 0;
    // dp에서 시간이 T 일때의 최대값을 탐색하여 출력한다.
    for (int w_idx = 0; w_idx <= W; w_idx++)
        answer = max({ dp[T][w_idx][1],dp[T][w_idx][2], answer });
    cout << answer;
    return 0;
}