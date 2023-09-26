#include <iostream>
#include <cstring>

using namespace std;

int n;
int graph[101][101];
int visited[101] = {0};
int answer = 0;

void dfs(int k)
{
  visited[k] = 1;
  answer++;

  for (int i = 1; i <= n; i++)
  {
    if (graph[k][i] == 1 && visited[i] == 0)
      dfs(i);
  }
  return;
}

int main()
{
  cin >> n;
  int cnt;
  memset(graph, 0, sizeof(graph));
  cin >> cnt;
  while (cnt--)
  {
    int a, b;
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  dfs(1);
  cout << answer - 1 << endl;
  return 0;
}