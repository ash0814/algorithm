#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int paper[101][101] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int x = a; x < c; x++) {
			for (int y = b; y < d; y++) {
				paper[x][y]++;
			}
		}
	}

	int cnt = 0;
	vector<int> v;
	bool visited[101][101] = {false, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && paper[i][j] == 0) {
				cnt++;

				int area = 0;
				queue<pair<int, int>> q;
				q.push({i, j});
				visited[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					area++;

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 0 || nx >= N || ny < 0 || ny >= M)
							continue;
						if (!visited[nx][ny] && paper[nx][ny] == 0) {
							q.push({nx, ny});
							visited[nx][ny] = true;
						}
					}
				}
				v.push_back(area);
			}
		}
	}

	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (auto n : v)
		cout << n << " ";
}