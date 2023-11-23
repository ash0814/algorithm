#include <iostream>
#include<vector>
using namespace std;

int min_3(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int solution(vector<vector<int>> board)
{
    int answer = 1;

    vector<vector<int>> dp = board;
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            if (board[i][j] == 0)
                dp[i][j] = 0;
            else {
                dp[i][j] += min_3(dp[i - 1][j], dp[i][j-1], dp[i-1][j-1]);
                answer = answer < dp[i][j] ? dp[i][j] : answer;
            }
        }
    }
    
    int zero = 0;
    for (auto n: board) {
        for (auto l : n) {
            zero += l;
        }
    }
    if (zero == 0)
        return 0;
    
    return answer * answer;
}