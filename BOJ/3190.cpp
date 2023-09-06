#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[104][104];
int dx[4] = {1, 0, -1, 0}; // 우, 하, 좌, 상
int dy[4] = {0, 1, 0, -1};
int dir = 0;

int main()
{
  int N, K, L;
  vector<pair<int, char>> move;
  cin >> N;
  for (int i = 0; i < N + 2; i++)
  {
    for (int j = 0; j < N + 2; j++)
    {
      map[i][j] = 0;
      map[0][j] = 1;
      map[N + 1][j] = 1;
      map[i][0] = 1;
      map[i][N + 1] = 1;
    }
  }
  cin >> K;
  while (K--)
  {
    int x, y;
    cin >> x >> y;
    map[x][y] = 2;
  }

  cin >> L;
  while (L--)
  {
    int x;
    char c;
    cin >> x >> c;
    move.push_back({x, c});
  }
  int time = 0;
  queue<pair<int, int>> snake;
  snake.push({1, 1});
  while (map[snake.back().first][snake.back().second] != 1)
  {
    int nx = snake.back().first + dx[dir];
    int ny = snake.back().second + dy[dir];
    if (move.front().first == time)
    {
      if (move.front().second == 'D')
        dir = (dir + 1) % 4;
      else
        dir = (dir + 3) % 4;
    }
    // if map[nx][ny] 가 뱀 몸통이 아니거나 벽(1)이 아니라면
    queue<pair<int, int>> newSnake;
    int nope = 0;
    while (newSnake.size())
    {
      if ((newSnake.front().first == nx && newSnake.front().second == ny) || map[snake.back().first][snake.back().second] == 1)
      {
        nope = 1;
        break;
      }
      newSnake.pop();
    }
    if (nope == 1)
      break;
    snake.push({nx, ny}); // 이동

    if (map[snake.back().first][snake.back().second] == 0)
      snake.pop();

    time++;
  }

  cout << time << endl;
  return 0;
}