#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[301][301] = {0, };

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int year = 0;

void print()
{
	cout << "=======================" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}

bool check()
{
	int tmp[301][301];
	copy(&map[0][0], &map[0][0]+(301 * 301), &tmp[0][0]);

	bool flag = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] > 0) {
				// bfs
				if (flag)
					return true;
				flag = true;
				queue<pair<int, int>> q;
				q.push({i, j});

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
						if (tmp[nx][ny] > 0) {
							q.push({nx, ny});
							tmp[nx][ny] = 0;
						}
					}
				}
			}
		}
	}
	return false;
}

void melt()
{
	int visited[301][301] = {0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0) {
				int mCnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
						continue;
					if (!visited[nx][ny] && map[nx][ny] == 0)
						mCnt++;
				}
				map[i][j] = max(0, map[i][j] - mCnt);
				visited[i][j] = true;
			}
		}
	}
}

int check_all()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0)
				return true;
		}
	}
	return false;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (!check())
	{
		melt();
		year++;

		if (!check_all())
		{
			cout << 0;
			return 0;
		}
	}

	cout << year;
}