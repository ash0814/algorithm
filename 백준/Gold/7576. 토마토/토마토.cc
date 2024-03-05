#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int box[1001][1001];
queue<pair<int, int>> q;
int N, M;

void bfs()
{
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (box[nx][ny] == 0) {
				box[nx][ny] = box[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}


int main()
{
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1)
				q.push({i, j});
		}
	}

	bfs();

	int max = -1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}
			if (box[i][j] > max)
				max = box[i][j];
		}
	}
	if (max != -1)
		cout << max-1 << '\n';
	else
		cout << 0 << '\n';
}