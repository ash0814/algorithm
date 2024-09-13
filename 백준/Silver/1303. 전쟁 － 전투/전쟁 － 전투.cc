#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char graph[101][101];
int visited[101][101] = {0, };
int N, M;
int wCnt = 0;
int bCnt = 0;

void bfs(int a, int b)
{
	char team = graph[a][b];
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({a, b});
	visited[a][b] = true;
	cnt++;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (!visited[nx][ny] && graph[nx][ny] == team) {
				cnt++;
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}

	if (team == 'W') {
		wCnt += cnt * cnt;
	} else {
		bCnt += cnt * cnt;
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	cout << wCnt << " " << bCnt;
}