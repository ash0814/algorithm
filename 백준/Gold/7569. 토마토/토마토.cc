#include <iostream>
#include <queue>

using namespace std;

int N, M, H;
int tomato[101][101][101];
bool visited[101][101][101] = {false, };
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
int day = 1;

struct Direction {
	int h;
	int x;
	int y;
};

queue<Direction> q;

bool is_finish() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

void bfs()
{
	while (!q.empty()) {
		int h = q.front().h;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = h + dh[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nh < 0 || nh >= H || nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (visited[nh][nx][ny] == true || tomato[nh][nx][ny] == -1)
				continue;
			if (tomato[nh][nx][ny] == 0 && !visited[nh][nx][ny]) {
				visited[nh][nx][ny] = true;
				tomato[nh][nx][ny] = tomato[h][x][y] + 1;
				if (day < tomato[nh][nx][ny])
					day = tomato[nh][nx][ny];
				Direction n;
				n.h = nh;
				n.x = nx;
				n.y = ny;
				q.push(n);
			}
		}
	}
}

int main()
{
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					Direction n;
					n.h = i;
					n.x = j;
					n.y = k;
					q.push(n);
				}
			}
		}
	}

	bfs();
	if (is_finish())
		cout << day - 1;
	else
		cout << -1;
}