#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1001;

int graph[MAX][MAX];
int visited[MAX] = {0};

void dfs(int v)
{
  visited[v] = 1;
  cout << v << ' ';

  for (int i = 1; i < MAX; i++)
  {
    if (graph[v][i] == 1 && visited[i] == 0)
      dfs(i);
  }
  return;
}

void bfs(int v)
{
  queue<int> q;
  q.push(v);
  cout << v << " ";

  while (!q.empty())
  {
    visited[q.front()] = 1;
    for (int i = 1; i < MAX; i++)
    {
      if (visited[i] == 0 && graph[q.front()][i] == 1)
      {
        q.push(i);
        visited[i] = 1;
        cout << i << " ";
      }
    }
    q.pop();
  }
}

int main()
{
  int N, M, V;
  cin >> N >> M >> V;
  memset(graph, 0, sizeof(graph));

  while (M--)
  {
    int a, b;
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  dfs(V);
  memset(visited, 0, sizeof(visited));
  cout << endl;
  bfs(V);

  return 0;
}