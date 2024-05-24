#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, K;
char road[6][6];
int visited[6][6] = {0, };

int cnt = 0;
int res = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	if (x == 0 && y == C - 1) {
		if (cnt == K)
			res++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			continue;
		if (road[nx][ny] != 'T' && visited[nx][ny] == false) {
			dfs(nx, ny);
			cnt--;
			visited[nx][ny] = false;
		}
	}

}

int main()
{
	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> road[i][j];
		}
	}

	dfs(R - 1, 0);

	cout << res;
}