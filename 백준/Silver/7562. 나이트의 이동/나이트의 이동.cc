#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int c, d;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
	int T;
	cin >> T;

	while (T--) {
		cin >> N;
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int visited[301][301] = {0, };
		queue<pair<int, int>> q;
		q.push({a, b});
		visited[a][b] = 1;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if (visited[nx][ny] == 0 ||
						(visited[nx][ny] > 0 && visited[nx][ny] > visited[x][y] + 1))
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push({nx, ny});
				}
			}

		}

		cout << visited[c][d] - 1 << '\n';
	}
}