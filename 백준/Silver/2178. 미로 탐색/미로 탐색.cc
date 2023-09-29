#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y)
{
  queue<pair<int, int>> q;
  q.push({x, y});

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
      {
        continue;
      }
      if (map[nx][ny] == 0)
      {
        continue;
      }
      if (map[nx][ny] == 1)
      {
        map[nx][ny] = map[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  return map[N - 1][M - 1];
}

int main()
{
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
      scanf("%1d", &map[i][j]);
  }

  cout << bfs(0, 0) << endl;

  return 0;
}