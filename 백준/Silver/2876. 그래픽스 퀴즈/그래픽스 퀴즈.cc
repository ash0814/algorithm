#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;

int main()
{
	int N;
	cin >> N;

	pair<int, int> desk[MAX];

	int dp[MAX][6] = {0,};

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		desk[i] = make_pair(a, b);
	}

	if (N == 1) {
		cout << 1 << " ";
		if (desk[0].first < desk[0].second)
			cout << desk[0].first;
		else
			cout << desk[0].second;
		return 0;
	}

	dp[0][desk[0].first] = 1;
	dp[0][desk[0].second] = 1;

	for (int i = 1; i < N; i++) {
		int a = desk[i].first;
		int b = desk[i].second;
		for (int grade = 1; grade <= 5; grade++) {
			if (grade == a || grade == b) {
				dp[i][grade] = dp[i-1][grade] + 1;
			} else {
				dp[i][grade] = 0;
			}
		}
	}


	int maxCnt = 0;
	int maxGrade = 0;

	for (int grade = 1; grade <= 5; grade++) {
		int grade_max = -1;
		for (int i = 0; i < N; i++) {
			if (grade_max < dp[i][grade])
				grade_max = dp[i][grade];
		}
		if (grade_max > maxCnt) {
			maxCnt = grade_max;
			maxGrade = grade;
		}
	}

	cout << maxCnt << " " << maxGrade;
}