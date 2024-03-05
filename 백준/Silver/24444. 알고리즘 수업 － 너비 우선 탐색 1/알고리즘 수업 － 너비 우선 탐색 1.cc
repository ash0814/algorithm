#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visited[100001] = {0, };
int seq = 0;
vector<vector<int>> edges(100001);

void bfs(int R)
{
	queue<int> q;
	visited[R] = ++seq;
	q.push(R);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : edges[u]) {
			if (visited[v] == 0){
				visited[v] = ++seq;
				q.push(v);
			}
		}
	}
}

int main()
{
	int N, M, R;
	cin >> N >> M >> R;

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(edges[i].begin(), edges[i].end());
	}
	bfs(R);

	for (int i = 1; i <= N; i++)
		cout << visited[i] << "\n";
}