#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int field[51][51] = {0, };
int visited[51][51] = {0, };
int N, M, K;
int cnt;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int a, int b)
{
	queue<pair<int, int>> q;
	visited[a][b] = 1;
	q.push({a, b});
	cnt++;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= M)
				continue;
			else if (field[xx][yy] == 1 && visited[xx][yy] == 0)
			{
				q.push({xx, yy});
				visited[xx][yy] = 1;
			}
		}
	}
}

void reset()
{
	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			field[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	cnt = 0;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		reset();

		cin >> N >> M >> K;
		while (K--)
		{
			int i, j;
			cin >> i >> j;
			field[i][j] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (field[i][j] == 1 && visited[i][j] == 0)
					bfs(i, j);
			}
		}

		cout << cnt << '\n';
	}
}