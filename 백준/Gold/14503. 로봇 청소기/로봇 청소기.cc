#include <iostream>

using namespace std;

int room[51][51] = {0,};
int N, M, r, c, dir;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool stop = false;
int cnt = 0;

bool can_go()
{
	for (int i = 0; i < 4; i++) {
		int new_dir = (new_dir + i) % 4;
		int nx = r + dx[new_dir];
		int ny = c + dy[new_dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (room[nx][ny] == 0)
			return true;
	}
	return false;
}

void robot()
{
	if (room[r][c] == 0) {
		room[r][c] = 2;
		cnt++;
	}

	if (can_go()) { // 갈 수 있으면
		for (int i = 0; i < 4; i++) {
			dir = (dir + 3) % 4;
			int nx = r + dx[dir];
			int ny = c + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (room[nx][ny] == 0) {
				r = nx;
				c = ny;
				return;
			}
		}
	} else {
		// 후진
		int bx = r - dx[dir];
		int by = c - dy[dir];
		if (bx < 0 || bx >= N || by < 0 || by >= M || room[bx][by] == 1) {
			stop = true;
			return;
		}
		else {
			r = bx;
			c = by;
			return;
		}
	}

	return;
}

int main()
{
	cin >> N >> M;
	cin >> r >> c >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}
	while (stop == false)
		robot();

	cout << cnt;
}