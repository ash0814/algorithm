#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[51][51] = {
		0,
};
int visited[51][51] = {
		0,
};
int N, M;
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int cnt = 0;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({i, j});
	visited[i][j] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
				continue;
			if (visited[next_x][next_y] == 0 && map[next_x][next_y] == 1)
			{
				q.push({next_x, next_y});
				visited[next_x][next_y] = 1;
			}
		}
	}
}

int main()
{
	while (1)
	{
		cin >> M >> N;
		if (N == 0 && M == 0)
			break;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
