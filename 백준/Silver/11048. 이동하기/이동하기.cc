#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int graph[1001][1001] = {0, };
int candy[1001][1001] = {0, };
int visited[1001][1001] = {0, };

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};

void solution(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({a, b});

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (visited[nx][ny]) {
				if (candy[nx][ny] < candy[x][y] + graph[nx][ny]) {
					candy[nx][ny] = candy[x][y] + graph[nx][ny];
					q.push({nx, ny});
				}
			} else {
				candy[nx][ny] = candy[x][y] + graph[nx][ny];
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	candy[0][0] = graph[0][0];

	solution(0, 0);

	cout << candy[N-1][M-1];
}