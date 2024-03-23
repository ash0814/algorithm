#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int N, M;
char campus[601][601];
bool visited[601][601] = {false, };
int cnt = 0;

void bfs(int i, int j)
{
	queue<pair<int, int>> qu;
	qu.push({i, j});

	while (!qu.empty())
	{
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = dx[k] + x;
			int ny = dy[k] + y;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			else if (campus[nx][ny] != 'X' && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				qu.push({nx, ny});
				if (campus[nx][ny] == 'P')
					cnt++;
			}
		}
	}
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int starti;
	int startj;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') {
				starti = i;
				startj = j;
			}
		}
	}

	bfs(starti, startj);
	if (cnt > 0)
		cout << cnt;
	else
		cout << "TT";
}