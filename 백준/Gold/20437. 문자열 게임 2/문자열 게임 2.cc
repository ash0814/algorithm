#include <iostream>
#include <vector>

using namespace std;

void solution()
{
	string str;
	int K;

	cin >> str >> K;

	vector<int> alpha[26];

	for (int i = 0; i < str.size(); i++) {
		alpha[str[i] - 'a'].push_back(i);
	}

	int res_min = 10001;
	int res_max = -1;

	for (int i = 0; i < 26; i++) {
		if (alpha[i].size() >= K) {
			for (int j = 0; j <= alpha[i].size() - K; j++) {
				int k = j + K - 1;
				res_min = min(res_min, alpha[i][k] - alpha[i][j] + 1);
				res_max = max(res_max, alpha[i][k] - alpha[i][j] + 1);
			}
		}
	}

	if (res_max == -1) {
		cout << -1 << "\n";
	} else {
		cout << res_min << " " << res_max << "\n";
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		solution();
	}
}