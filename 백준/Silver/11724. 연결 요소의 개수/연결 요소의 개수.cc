#include <iostream>

using namespace std;

int graph[1001][1001] = {0};
int visited[1001] = {0};

void dfs(int v)
{
  visited[v] = 1;

  for (int i = 1; i < 1001; i++)
  {
    if (graph[v][i] == 1 && visited[i] == 0)
      dfs(i);
  }
  return;
}

int main()
{
  int N, M;
  cin >> N >> M;
  int answer = 0;
  while (M--)
  {
    int a, b;
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  for (int i = 1; i <= N; i++)
  {
    if (visited[i] == 0)
    {
      dfs(i);
      answer++;
    }
  }
  cout << answer << endl;
  return 0;
}