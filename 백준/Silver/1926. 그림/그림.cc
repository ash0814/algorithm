#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int map[501][501] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int drawCnt = 0;
int maxArea = 0;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({i, j});
	map[i][j] = 0;
	int area = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (map[nx][ny] == 1) {
				map[nx][ny] = 0;
				area++;
				q.push({nx, ny});
			}
		}
	}

	if (maxArea < area)
		maxArea = area;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				drawCnt++;
				bfs(i, j);
			}
		}
	}

	cout << drawCnt << '\n';
	cout << maxArea << '\n';
}