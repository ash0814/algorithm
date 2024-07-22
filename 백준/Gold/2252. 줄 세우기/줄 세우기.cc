#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> list;
	int degree[32001] = {0, };
	bool visit[32001] = {0, };

	list.resize(N + 1);


	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		list[a].push_back(b);
		degree[b]++;
	}

	queue<int> q;
	int result[32001];

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty())
			break;
		int x = q.front();
		q.pop();
		result[i] = x;

		for (int j = 0; j < list[x].size(); j++) {
			int y = list[x][j];
			if (--degree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i] << " ";

	return 0;
}