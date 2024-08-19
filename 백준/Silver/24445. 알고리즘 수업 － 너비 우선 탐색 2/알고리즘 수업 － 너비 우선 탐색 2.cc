#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, R;
vector<vector<int>> list;
int visited[100001] = {
    0,
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> R;
  list.resize(N + 1);

  for (int i = 0; i < M; i++)
  {
    int u, v;
    cin >> u >> v;

    list[u].push_back(v);
    list[v].push_back(u);
  }

  for (int i = 1; i <= N; i++)
  {
    sort(list[i].rbegin(), list[i].rend());
  }

  queue<int> q;
  int res[100001] = {
      0,
  };
  int cnt = 0;
  visited[R] = 1;
  res[R] = ++cnt;
  q.push(R);

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (auto v : list[x])
    {
      if (visited[v] == 0)
      {
        visited[v] = 1;
        res[v] = ++cnt;
        q.push(v);
      }
    }
  }

  for (int i = 1; i <= N; i++)
  {
    cout << res[i] << '\n';
  }
}