#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int graph[126][126] = {0, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int n)
{
	priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
	int dist[126][126];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 987654321;
		}
	}
	pq.push({graph[0][0], {0, 0}});
	dist[0][0] = graph[0][0];

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0)
				continue;
			int nCost = cost + graph[nx][ny];

			if (nCost < dist[nx][ny]) {
				dist[nx][ny] = nCost;
				pq.push({dist[nx][ny], {nx, ny}});
			}
		}
	}

	return dist[n-1][n-1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int idx = 1;
	while (1) {
		int N;
		cin >> N;
		if (N == 0)
			return 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
			}
		}

		cout << "Problem " << idx << ": " << bfs(N) << '\n';
		idx++;
	}
}