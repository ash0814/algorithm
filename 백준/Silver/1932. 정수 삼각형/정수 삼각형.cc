#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[501][501] = {0,};
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for (int j = 1; j < triangle[i].size(); j++) {
            int bigger = max(dp[i - 1][j-1], dp[i-1][j]);
            dp[i][j] = bigger + triangle[i][j];
        }
    }

    for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
        if (answer < dp[triangle.size() - 1][i])
            answer = dp[triangle.size() - 1][i];
    }

    return answer;
}

int main()
{
	cin >> n;
	vector<vector<int>> triangle;
	for (int i = 0; i < n; i++) {
		vector<int> line;
		for (int j = 0; j <= i; j++) {
			int num;
			cin >> num;
			line.push_back(num);
		}
		triangle.push_back(line);
	}
	cout << solution(triangle);
}