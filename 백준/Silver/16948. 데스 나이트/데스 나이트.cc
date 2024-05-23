#include <iostream>
#include <queue>

using namespace std;

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int N;
int sx, sy, ex, ey;

int board[201][201] = {0, };

int main()
{
	cin >> N;
	cin >> sx >> sy >> ex >> ey;

	if (sx == ex && sy == ey) {
		cout << 0;
		return 0;
	}
	queue<pair<int, int>> q;
	q.push({sx, sy});

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[nx][ny] == 0) {
				board[nx][ny] = board[x][y] + 1;
				q.push({nx, ny});
			} else {
				if (board[nx][ny] > board[x][y] + 1) {
					board[nx][ny] = board[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
	}

	cout << ((board[ex][ey] == 0) ? -1 : board[ex][ey]);
}