#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int area[501][501] = {0, };
int dp[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void dijkstra(int x, int y)
{
	priority_queue<pair<int, pair<int, int>>,
		vector<pair<int, pair<int, int>>>,
		greater<pair<int, pair<int, int>>>> pq;

	pq.push({0, {x, y}});

	dp[x][y] = 0;

	while (!pq.empty())
	{
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int next_cost = cost;

			if (nx < 0 || nx >= 501 || ny < 0 || ny >= 501)
				continue;
			if (area[nx][ny] == 2)
				continue;
			if (area[nx][ny] == 1) {
				next_cost++;
			}
			if (next_cost >= dp[nx][ny])
				continue;

			dp[nx][ny] = next_cost;
			pq.push({next_cost, {nx, ny}});
		}
	}
}

int main()
{
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = min(x1, x2); x <= max(x1, x2); x++) {
			for (int y = min(y1, y2); y <= max(y1, y2); y++) {
				area[x][y] = 1;
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = min(x1, x2); x <= max(x1, x2); x++) {
			for (int y = min(y1, y2); y <= max(y1, y2); y++) {
				area[x][y] = 2;
			}
		}
	}

	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			dp[i][j] = 987654321;
		}
	}

	dijkstra(0, 0);

	if (dp[500][500] == 987654321)
	{
		cout << -1;
		return 0;
	}
	cout << dp[500][500];
}